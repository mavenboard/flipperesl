#include "main_menu.h"
#include "../price_tagger.h"

#include <furi.h>

#include <stdlib.h>


typedef enum {
    MainMenuItem_Tags,
    MainMenuItem_Program,
    MainMenuItem_count
} MainMenuItem;


static void on_selection(void* context, uint32_t index) {
    furi_assert(context);
    App* app = context;

    switch (index) {
    case MainMenuItem_Tags:
        scene_manager_next_scene(app->scene_manager, AppScene_TagManager);
        break;
    case MainMenuItem_Program:
        scene_manager_next_scene(app->scene_manager, AppScene_TagProgrammer);
        break;
    default:
        break;
    }
}


void main_menu_on_enter(void* context) {
    furi_assert(context);
    App* app = context;
    submenu_reset(app->submenu);
    submenu_add_item(app->submenu, "Tags",    MainMenuItem_Tags,    on_selection, app);
    submenu_add_item(app->submenu, "Program", MainMenuItem_Program, on_selection, app);
    view_dispatcher_switch_to_view(app->view_dispatcher, AppView_Menu);
}

bool main_menu_on_event(void* context, SceneManagerEvent event) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
    UNUSED(event);

    return false;
}

void main_menu_on_exit(void* context) {
    furi_assert(context);
    App* app = context;
    submenu_reset(app->submenu);
}
