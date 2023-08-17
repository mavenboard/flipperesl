#pragma once

#include <gui/scene_manager.h>


void tag_manager_on_enter(void* context);
bool tag_manager_on_event(void* context, SceneManagerEvent event);
void tag_manager_on_exit(void* context);
