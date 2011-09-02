using namespace std;
#include "header.h"
#include "globalvar.h"
#include "texts.h"
#include "procc.h"
#include "graphic.h"
#include "console.h"
#include "cache.h"

int main (int argc, char *argv[])
{
    datapath=coi_getdatapath(argv[0]);
    gboolean f=coip(argc,argv); if(!f){return 0;}

    srand(time(NULL));
    cache_army();
    cache_images(IMAGES);
    cache_langfile(langfile);

    init_map();

    gui_init(argc,argv);
    cache_clear();
    return 0;
}
