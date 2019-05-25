#ifndef COELUMG_WINDOW_insert_H
#define COELUMG_WINDOW_insert_H
#include "window.h"


typedef struct WINDOW_insert_STRUCT
{
    window_T base;
} window_insert_T;

window_insert_T* init_window_insert(float x, float y);

void window_insert_tick(actor_T* self);

void window_insert_draw(actor_T* self);
#endif