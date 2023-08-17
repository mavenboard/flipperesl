#pragma once

//#include <furi.h>


typedef struct Tag {
    //FuriString* name;
} Tag;

Tag* tag_alloc();
void tag_free(Tag* tag);
