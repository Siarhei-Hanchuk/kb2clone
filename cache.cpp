#include "header.h"
#include "Error.h"

void cache_army()
{
    Tarmys *a=new Tarmys[25];
    gint64 size=sizeof(Tarmys);
    gchar *fn=new gchar[256];
    strcpy(fn,GV.datapath);
    strcat(fn,"/armydata");
    FILE *f;
    f=fopen(fn,"r");
    if(f==NULL)return;
    fread(a,size,25,f);
    fclose(f);
    for(int i=0;i<25;i++){
        GV.armys[i+51]=a[i];
        strcpy(GV.armys[i+51].name,a[i].name);
    }
    delete[] a;
    delete[] fn;
}

gchar* cache_i_getimgpath(id imgid)
{
    gchar *s=new gchar[256];
    strcpy(s,GV.datapath);
    switch(imgid){
    case o_city:
        strcat(s,"/images/city.png");
        break;
    case o_army:
        strcat(s,"/images/army.png");
        break;
    case o_nave:
        strcat(s,"/images/nave.png");
        break;
    case o_guidepost:
        strcat(s,"/images/guidepost.png");
        break;
    case o_goldchest:
        strcat(s,"/images/goldchest.png");
        break;
    case l_land:
        strcat(s,"/images/land.png");
        break;
    case l_sand:
        strcat(s,"/images/sand.png");
        break;
    case l_water:
        strcat(s,"/images/water.png");
        break;
    case l_forest:
        strcat(s,"/images/forest.png");
        break;
    case o_player:
        strcat(s,"/images/player.png");
        break;
    case l_stone:
        strcat(s,"/images/stone.png");
        break;
    case s_wallkick_b:
        strcat(s,"/images/status/wallkick_b.png");
        break;
    case s_wallkick_c:
        strcat(s,"/images/status/wallkick_c.png");
        break;
    case s_contract_b:
        strcat(s,"/images/status/contract_b.png");
        break;
    case s_contract_c:
        strcat(s,"/images/status/contract_c.png");
        break;
    case s_ancientmap_0:
        strcat(s,"/images/status/ancientmap_0.png");
        break;
    case s_money_0:
        strcat(s,"/images/status/money_0.png");
        break;
    case s_magic_0:
        strcat(s,"/images/status/magic_0.png");
        break;
    case o_capitan:
        strcat(s,"/images/capitan.png");
        break;
    case o_castel_c:
        strcat(s,"/images/castle_c.png");
        break;
    case o_castel_l:
        strcat(s,"/images/castle_l.png");
        break;
    case o_castel_r:
        strcat(s,"/images/castle_r.png");
        break;
    case a_peasant:
        strcat(s,"/images/army/peasant.png");
        break;
    case a_aborigine:
        strcat(s,"/images/army/aborigine.png");
        break;
    case a_boar:
        strcat(s,"/images/army/boar.png");
        break;
    case a_skeleton:
        strcat(s,"/images/army/skeleton.png");
        break;
    case a_woodgoblin:
        strcat(s,"/images/army/woodgoblin.png");
        break;
    case a_elf:
        strcat(s,"/images/army/elf.png");
        break;
    case a_dwarf:
        strcat(s,"/images/army/dwarf.png");
        break;
    case a_gorilla:
        strcat(s,"/images/army/gorilla.png");
        break;
    case a_zombie:
        strcat(s,"/images/army/zombie.png");
        break;
    case a_rknight:
        strcat(s,"/images/army/rknight.png");
        break;
    default:
        strcat(s,"/images/emo.png");
    }
    #ifdef WIN32
        win32_slash(s);
    #endif
    if(!err_fileexists(s)){
        err_log("No such file",s);
        strcpy(s,GV.datapath);
        strcat(s,"/images/emo.png");
    }
    return s;
}

void cache_images(cairo_surface_t **&arr)
{
    int maxid=120;
    arr=new cairo_surface_t*[maxid];
    gchar *s;
    for(int i=0;i<maxid;i++){
        s=cache_i_getimgpath(i);
        arr[i]=cairo_image_surface_create_from_png(s);
        delete[] s;
    }
}

int cache_i_loadfile(const gchar *fn,gchar *&file)
{
    FILE *f=fopen(fn,"r");
    if(f==NULL){return -1;}
    fseek(f,0,SEEK_END);
    int len=ftell(f);
    fseek(f,0,SEEK_SET);
    if(len==0){fclose(f);return 0;}
    file=new gchar[len];
    fread(file,len,1,f);
    fclose(f);
    return len;
}

void cache_langfile(gchar *&data)
{
    char *pt=new char[256];
    strcpy(pt,GV.datapath);
    strcat(pt,"/texts/russian.txt");
    #ifdef WIN32
        win32_slash(pt);
    #endif
    cache_i_loadfile(pt,data);
    delete pt;
}

void cache_clear()
{
    delete[] GV.langfile;
    delete[] GV.datapath;
    for(int i=0;i<120;i++){
        cairo_surface_destroy(GV.IMAGES[i]);
    }
}
