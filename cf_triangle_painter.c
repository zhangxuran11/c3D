#include "cf_module/cf_module.h"
#include "cf_factory/cf_factory.h"
#include <stdio.h>
static void triangle_painter_constructor(cf_element* elem){

}

static void triangle_painter_attr_write(cf_element* elem,void* attr){

}
static void* triangle_painter_processer(cf_element* elem,void* data){

}
static void triangle_painter_data_release(void* data){

}
static void mod_load(void){
    cf_factory* factory = cf_find_factory("cf_3d_factory");
    cf_element_class* elem_class = cf_element_class_create("cf_triangle_painter");
    cf_element_class_set_constructor(elem_class,triangle_painter_constructor);
    cf_element_class_set_processer(elem_class,triangle_painter_processer);
    cf_element_class_set_data_release_method(elem_class,triangle_painter_data_release);
    cf_element_class_register_attr(elem_class,"color",triangle_painter_attr_write,NULL);
    // cf_element_class_set_deconstructor(elem_class,sdlsink_deconstructor);
    // cf_element_class_set_start_method(elem_class,sdlsink_start);
    cf_factory_rigster_element(factory,elem_class);
}
static void mod_unload(void){
    cf_factory* factory = cf_find_factory("cf_3d_factory");
    cf_factory_unrigster_element_by_name(factory,"cf_triangle_painter");
}


static void mod_init(cf_mod* mod){
    cf_mod_set_name(mod,"cf_triangle_painter_mod");
    cf_mod_set_version(mod,CF_MOD_MK_VERSION(0,0,0));
    cf_mod_set_load(mod,mod_load);
    cf_mod_add_dep(mod,"cf_3d_factory_mod");
}

CF_MOD_INIT(mod_init)