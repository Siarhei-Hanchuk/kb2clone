#include "header.h"
#include "texts.h"
#include "procc.h"
#include "gui.h"
#include "console.h"
#include "cache.h"

TGlobalvar GV;
Tplayer pl;
Tworld world;

int main (int argc, char *argv[])
{
    GV.datapath=coi_getdatapath(argv[0]);
    gboolean f=coip(argc,argv); if(!f){return 0;}

    srand(time(NULL));
    cache_army();
    cache_images(GV.IMAGES);
    cache_langfile(GV.langfile);

    init_map();

    gui_init(argc,argv);
    cache_clear();
    return 0;
}
