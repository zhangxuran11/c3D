#include <SDL2/SDL.h>
#include "cf_module/cf_module.h"
#include "cf_factory/cf_factory.h"
#include "cf_allocator/cf_allocator_simple.h"
#include "cf_std.h"
#include <assert.h>
#include <signal.h>
typedef struct sdlsink{
    SDL_Window* win;
}sdlsink;
static void sdlsink_start(cf_element* elem){
    sdlsink* sink = (sdlsink*)cf_element_get_priv(elem);
    SDL_Surface *screen = SDL_GetWindowSurface(sink->win);
    SDL_LockSurface(screen);
    uint32_t* pixel = (uint32_t*)screen->pixels;
    for(int i = 0;i < screen->w * screen->h;i++){
        uint32_t color = SDL_MapRGB(screen->format, 255, 0, 0);
        *pixel = color;
        pixel++;
    }
    SDL_UnlockSurface(screen);
    SDL_UpdateWindowSurface(sink->win);
}

static void sdlsink_constructor(cf_element* elem){
    sdlsink* sink = (sdlsink*)cf_allocator_simple_alloc(sizeof(sdlsink));
    sink->win = SDL_CreateWindow("sdlsink",100,100,400,400,0);
    cf_element_set_priv(elem,sink);
}
static void sdlsink_deconstructor(cf_element* elem){
    
    sdlsink* sink = (sdlsink*)cf_element_get_priv(elem);
    SDL_DestroyWindow(sink->win);
    cf_allocator_simple_free(sink);
}
static void stop(int num){
    cf_unused(num);
    exit(0);
}
static void mod_load(void){
    signal(SIGINT, stop);
    //SDL_Init(SDL_INIT_EVERYTHING);
    if (!SDL_WasInit(SDL_INIT_VIDEO)) {
        SDL_InitSubSystem(SDL_INIT_VIDEO);
    }

    cf_factory* factory = cf_find_factory("cf_3d_factory");
    cf_element_class* elem_class = cf_element_class_create("sdlsink");
    cf_element_class_set_constructor(elem_class,sdlsink_constructor);
    cf_element_class_set_deconstructor(elem_class,sdlsink_deconstructor);
    cf_element_class_set_start_method(elem_class,sdlsink_start);
    cf_factory_rigster_element(factory,elem_class);
}
static void mod_unload(void){
    cf_factory* factory = cf_find_factory("cf_3d_factory");
    cf_factory_unrigster_element_by_name(factory,"sdlsink");
    SDL_Quit();
}


static void mod_init(cf_mod* mod){
    cf_mod_set_name(mod,"sdlsink_mod");
    cf_mod_set_version(mod,CF_MOD_MK_VERSION(0,0,0));
    cf_mod_set_load(mod,mod_load);
    cf_mod_add_dep(mod,"cf_3d_factory_mod");
}

CF_MOD_INIT(mod_init)