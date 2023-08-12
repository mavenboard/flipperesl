#include "main_menu.h"
#include "../price_tagger.h"

#include <furi.h>

#include <stdlib.h>


typedef enum {
    MainMenuItem_ProgramTag,
    MainMenuItem_ManageTags,
    MainMenuItem_About,
    MainMenuItem_count
} MainMenuItem;


static void on_selection(void* context, uint32_t index) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
    UNUSED(index);
}


void main_menu_on_enter(void* context) {
    furi_assert(context);
    App* app = context;
    submenu_reset(app->submenu);
    submenu_set_header(app->submenu, "Price Tagger");
    submenu_add_item(app->submenu, "Program Tag", MainMenuItem_ProgramTag, on_selection, app);
    submenu_add_item(app->submenu, "Manage Tags", MainMenuItem_ManageTags, on_selection, app);
    submenu_add_item(app->submenu, "About",       MainMenuItem_About,      on_selection, app);
    view_dispatcher_switch_to_view(app->view_dispatcher, AppView_Menu);
}

bool main_menu_on_event(void* context, SceneManagerEvent event) {

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
