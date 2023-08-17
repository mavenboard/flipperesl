#pragma once

#include "tag.h"

#include <dialogs/dialogs.h>
#include <gui/gui.h>
#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/modules/popup.h>
#include <storage/storage.h>


//#define TAG "price_tagger"


typedef enum {
    AppScene_MainMenu,
    AppScene_TagManager,
    AppScene_TagProgrammer,
    AppScene_count
} AppScene;

typedef enum {
    AppView_Menu,
    //AppView_Popup,
    AppView_count
} AppView;

typedef struct App {
    Gui* gui;
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    DialogsApp* dialogs;
    Submenu* submenu;
    //Popup* popup;
    Storage* storage;

    //FuriString* file_path; // TODO
    //Tag* active_tag;
} App;
