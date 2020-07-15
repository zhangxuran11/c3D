#include "cf_module/cf_module.h"
#include "cf_factory/cf_factory.h"
static void mod_load(void){
    cf_factory* factory = cf_factory_create("cf_3d_factory");
    cf_factory_add_factory(factory);
}

static void mod_init(cf_mod* mod){
    cf_mod_set_name(mod,"cf_3d_factory_mod");
    cf_mod_set_version(mod,CF_MOD_MK_VERSION(0,0,0));
    cf_mod_set_load(mod,mod_load);
}

CF_MOD_INIT(mod_init)