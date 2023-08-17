#include "tag_programmer.h"
#include "../price_tagger.h"

#include <furi.h>

#include <stdlib.h>


void tag_programmer_on_enter(void* context) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
}

bool tag_programmer_on_event(void* context, SceneManagerEvent event) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
    UNUSED(event);

    return false;
}

void tag_programmer_on_exit(void* context) {
    furi_assert(context);
    App* app = context;

    UNUSED(app);
}
