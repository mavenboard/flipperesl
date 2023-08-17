#include "app_storage.h"
#include "price_tagger_icons.h"

#include <furi.h>


static const char* TAG_DIR_PATH = APP_DATA_PATH("tags");
// static const char* TAG_FILE_EXT = ".tag";
static const char* IMAGE_DIR_PATH = APP_DATA_PATH("images");
// static const char* IMAGE_FILE_EXT = ".png";


bool app_storage_create_dirs(Storage* storage) {
    return storage_simply_mkdir(storage, TAG_DIR_PATH)
        && storage_simply_mkdir(storage, IMAGE_DIR_PATH);
}

// TODO
bool app_storage_select_tag() {
    //DialogsFileBrowserOptions browser_options;
    //dialog_file_browser_set_basic_options(&browser_options, APP_TAG_FILE_EXT, &I_icon_10);
    //return dialog_file_browser_show(app->dialog, selected_filepath, predefined_filepath, &browser_options);
    return false;
}

// TODO
bool app_storage_select_image() {
    //DialogsFileBrowserOptions browser_options;
    //dialog_file_browser_set_basic_options(&browser_options, APP_TAG_FILE_EXT, &I_icon_10);
    //return dialog_file_browser_show(app->dialog, selected_filepath, predefined_filepath, &browser_options);
    return false;
}
