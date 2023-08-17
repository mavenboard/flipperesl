#include "tag.h"

#include <stdlib.h>


Tag* tag_alloc() {
    Tag* tag = malloc(sizeof(Tag));
    //tag->name = furi_string_alloc();
    return tag;
}

void tag_free(Tag* tag) {
    //furi_string_free(tag->name);
    free(tag);
}
