#include "tag_manager.h"
#include "../price_tagger.h"
#include "../app_storage.h"

#include <furi.h>

#include <stdlib.h>
#include <stdbool.h>


typedef enum {
    TagManagerState_ActionMenu,
    TagManagerState_TagBrowser,
    TagManagerState_DeleteDialog,
    TagManagerState_count
} TagManagerState;

typedef enum {
    TagManagerAction_Create,
    TagManagerAction_Edit,
    TagManagerAction_Delete,
    TagManagerAction_count
} TagManagerAction;


//static void set_state(App* app, TagManagerState state);

static void on_menu_selection(void* context, uint32_t index) {
    furi_assert(context);
    App* app = context;
    bool file_selected = false;

    switch (index) {
    case TagManagerAction_Create:
        // TODO go to create scene
        break;

    case TagManagerAction_Edit:
        file_selected = app_storage_select_tag();
        // TODO load Tag from file
        // TODO handle load error
        //set_state(app, TagManagerState_TagBrowser);
        break;

    case TagManagerAction_Delete:
        file_selected = app_storage_select_tag();
        // TODO delete file
        //set_state(app, TagManagerState_TagBrowser);
        break;

    default:
        break;
    }

    (void)app; // TODO remove
    (void)file_selected; // TODO remove
}

// static void on_context_selection(void* context, uint32_t index) {
//     furi_assert(context);
//     App* app = context;

//     UNUSED(app);

//     switch (index) {
//     case TagManagerContextItem_Edit:
//         break;
//     case TagManagerContextItem_Delete:
//         break;
//     default:
//         break;
//     }
// }

// static void set_state(App* app, TagManagerState state) {
//     TagManagerState prev_state = scene_manager_get_scene_state(app->scene_manager, AppScene_TagManager);
//     if (prev_state == TagManagerState_TagBrowser) {
//         file_browser_stop(app->file_browser);
//     }

//     switch (state) {
//     case TagManagerState_ActionMenu:
//         submenu_reset(app->submenu);
//         submenu_add_item(app->submenu, "Create", TagManagerAction_Create, on_menu_selection, app);
//         submenu_add_item(app->submenu, "Edit",   TagManagerAction_Edit,   on_menu_selection, app);
//         submenu_add_item(app->submenu, "Delete", TagManagerAction_Delete, on_menu_selection, app);
//         view_dispatcher_switch_to_view(app->view_dispatcher, AppView_Menu);
//         break;

//     case TagManagerState_TagBrowser:
//         file_browser_stop(app->file_browser);
//         view_dispatcher_switch_to_view(app->view_dispatcher, AppView_FileBrowser);

//     case TagManagerState_DeleteDialog:
//         break;

//     default:
//         break;
//     }

//     scene_manager_set_scene_state(app->scene_manager, AppScene_TagManager, state);
// }

void tag_manager_on_enter(void* context) {
    furi_assert(context);
    App* app = context;

    // TODO remove
    //set_state(app, TagManagerState_ActionMenu);

    submenu_reset(app->submenu);
    submenu_add_item(app->submenu, "Create", TagManagerAction_Create, on_menu_selection, app);
    submenu_add_item(app->submenu, "Edit",   TagManagerAction_Edit,   on_menu_selection, app);
    submenu_add_item(app->submenu, "Delete", TagManagerAction_Delete, on_menu_selection, app);
    view_dispatcher_switch_to_view(app->view_dispatcher, AppView_Menu);
}

bool tag_manager_on_event(void* context, SceneManagerEvent event) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
    UNUSED(event);

    return false;
}

void tag_manager_on_exit(void* context) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
}
