#include "price_tagger.h"
#include "scenes/main_menu.h"

#include <furi.h>

#include <stdlib.h>


static const uint32_t TICK_PERIOD_MS = 100;


static void (*const on_enter_handlers[])(void*) = {
    main_menu_on_enter
};

static bool (*const on_event_handlers[])(void*, SceneManagerEvent) = {
    main_menu_on_event
};

static void (*const on_exit_handlers[])(void*) = {
    main_menu_on_exit
};

static const SceneManagerHandlers scene_handlers = {
    .on_enter_handlers = on_enter_handlers,
    .on_event_handlers = on_event_handlers,
    .on_exit_handlers = on_exit_handlers,
    .scene_num = AppScene_count
};


static void on_tick_event(void* context) {
    furi_assert(context);
    App* app = context;
    scene_manager_handle_tick_event(app->scene_manager);
}

static bool on_navigation_event(void* context) {
    furi_assert(context);
    App* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}

static bool on_custom_event(void* context, uint32_t event) {
    furi_assert(context);
    App* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, event);
}

static App* app_alloc() {
    App* app = malloc(sizeof(App));
    app->gui = furi_record_open(RECORD_GUI);

    app->view_dispatcher = view_dispatcher_alloc();
    view_dispatcher_enable_queue(app->view_dispatcher);
    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_set_tick_event_callback(app->view_dispatcher, on_tick_event, TICK_PERIOD_MS);
    view_dispatcher_set_navigation_event_callback(app->view_dispatcher, on_navigation_event);
    view_dispatcher_set_custom_event_callback(app->view_dispatcher, on_custom_event);
    view_dispatcher_attach_to_gui(app->view_dispatcher, app->gui, ViewDispatcherTypeFullscreen);

    app->submenu = submenu_alloc();
    view_dispatcher_add_view(app->view_dispatcher, AppView_Menu, submenu_get_view(app->submenu));

    app->popup = popup_alloc();
    view_dispatcher_add_view(app->view_dispatcher, AppView_Popup, popup_get_view(app->popup));

    app->scene_manager = scene_manager_alloc(&scene_handlers, app);
    scene_manager_next_scene(app->scene_manager, AppScene_MainMenu);

    return app;
}

static void app_free(App* app) {
    scene_manager_free(app->scene_manager);

    view_dispatcher_remove_view(app->view_dispatcher, AppView_Menu);
    submenu_free(app->submenu);

    view_dispatcher_remove_view(app->view_dispatcher, AppView_Popup);
    popup_free(app->popup);

    view_dispatcher_free(app->view_dispatcher);

    furi_record_close(RECORD_GUI);
    free(app);
}

int32_t app_main(void* p) {
    UNUSED(p);
    App* app = app_alloc();
    view_dispatcher_run(app->view_dispatcher);
    app_free(app);
    return 0;
}
