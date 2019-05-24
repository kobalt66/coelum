#ifndef COELUMG_WINDOW_H
#define COELUMG_WINDOW_H
#include <coelum/actor.h>
#include <coelum/state.h>


typedef struct WINDOW_STRUCT
{
    actor_T base;
    state_T* state;
    char* title;
    float width;
    float height;
} window_T;

window_T* init_window(float x, float y, float width, float height, char* title);

void window_tick(actor_T* self);

void window_draw(actor_T* self);
#endif