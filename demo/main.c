#include "cf_module/cf_module.h"
#include "cf_factory/cf_factory.h"
#include "cf_thread/cf_thread.h"
#include <assert.h>
int main(){
    cf_mod_setup();
    cf_factory* factory = cf_find_factory("cf_3d_factory");
    cf_element* sdlsink = cf_factory_create_elem(factory,"cf_sdlsink",NULL);
    cf_element* painter = cf_factory_create_elem(factory,"cf_triangle_painter",NULL);
    cf_element_link(painter,sdlsink);
    cf_element_start(painter);
    while(true){
        cf_msleep(10);
    };
    return 0;
}