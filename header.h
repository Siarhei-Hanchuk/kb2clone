#include <stdlib.h>
#include <gtk/gtk.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef long int id;

const int MAXC=65;

const id l_water=1;
const id l_land=2;
const id l_sand=3;
const id l_stone=4;
const id l_forest=5;
const id l_plot=6;

const id o_player=10;
const id o_city=11;
const id o_guidepost=12;
const id o_nave=13;
const id o_goldchest=14;
const id o_army=15;
const id o_castel_c=16;
const id o_castel_r=17;
const id o_castel_l=18;
const id o_capitan=19;

const id s_wallkick_b=81;
const id s_wallkick_c=82;
const id s_contract_b=83;
const id s_contract_c=84;
const id s_magic_0=90;
const id s_money_0=100;
const id s_ancientmap_0=110;

const id a_peasant=51;
const id a_aborigine=52;
const id a_boar=53;
const id a_skeleton=54;
const id a_woodgoblin=55;
const id a_elf=56;
const id a_dwarf=57;
const id a_gorilla=58;
const id a_zombie=59;
const id a_rknight=60;

const id e_navi=301;
const id e_workers=302;
const id e_city_wrk=303;

const int screenw=960;
const int screenh=600;

const id key_up=82;
const id key_down=84;
const id key_left=81;
const id key_right=83;
const id key_map=0x6d;
const id key_esc=27;
const id key_d=0x64;
const id key_v=0x76;
const id key_n=0x6e;
const id key_w=0x77;
const id key_arm=0x61;
const id key_enter=13;
const id key_backspace=8;

const gint8 key_1=49;
const gint8 key_2=50;
const gint8 key_3=51;
const gint8 key_4=52;
const gint8 key_5=53;
const gint8 key_6=54;
const gint8 key_7=55;

struct Tcity
{
    id castleid;
    id magic;
    guint8 wraft;
    guint8 wforest;
    guint8 wstone;
    guint8 wland;
};

struct Point
{
    id land;
    id obj;
    id addid;
};

typedef Point Tmap[MAXC][MAXC];

struct Tarmys
{
    gchar name[32];
    guint16 defence;
    guint16 damage;
    guint8 step;
    gboolean fly;
    gboolean shoot;
    guint16 count ;
    guint16 cost;
    gchar reserved[6];
};


struct Tcountry
{
    Tmap map;
};

struct Tarmy
{
    id armid;
    uint count;
};

struct Tcastle
{
    Tarmys army[5];
    bool owner;
};

struct Tcapitan
{
    Tarmys army[5];
};

struct Tplayerworkers
{
    gint32 woodsman;
    gint32 groundsman;
    gint32 stonesman;
    gint32 carpenter;
};

struct Tplayer
{
    Tarmy army[10];
    //Tplayermagic magic;
    gboolean wallkick;
    gboolean nave;
    gboolean innave;
    guint8 country;
    gboolean contract;
    //Захваченые замки
    //Взятые контракты
    gint64 money;
    gint64 authority;
    gint16 magic;
    Tplayerworkers workers;
    short X;
    short Y;

};

struct Tworld
{
    Tcountry country[5];
    Tcity city[25];
    gint16 naveX;
    gint16 naveY;
    gint8 naveC;
    Tcastle castles[25];
    Tcapitan capitans[150];
    gint16 cut_cap;
};

struct Tmenu{
    gchar *p[9];
};

struct TGlobalvar{
    gchar *datapath;
    gchar *langfile;
    cairo_surface_t **IMAGES;
    Tarmys armys[125];

    GtkWidget *window;
    GtkWidget *drawarea;

    id **lastA;
    gboolean gui_dialog_showed;
    gint16 gui_keylock_event;

    gint64 tmpv_gold;
    gint64 tmpv_city;
    gint64 tmpv_nextX;
    gint64 tmpv_nextY;
    gint64 tmpv_wrk;
    gint16 tmpv_cityX;
    gint16 tmpv_cityY;

    gint8 w3_ty;
    gint w3_yy;
    gint16 w3_armi;
};

extern TGlobalvar GV;
extern Tworld world;
extern Tplayer pl;
