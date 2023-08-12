#pragma once

#include <gui/gui.h>
#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/modules/popup.h>
//#include <gui/modules/widget.h>
//#include <gui/modules/text_input.h>


//#define TAG "price_tagger"


typedef enum {
    AppScene_MainMenu,
    AppScene_count
} AppScene;

typedef enum {
    AppView_Menu,
    AppView_Popup,
    AppView_count
} AppView;

typedef struct App {
    Gui* gui;
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    Submenu* submenu;
    Popup* popup;
} App;
