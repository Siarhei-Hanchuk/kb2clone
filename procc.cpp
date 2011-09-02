#include "header.h"
#include "world.h"
#include "texts.h"
#include "graphic.h"


void init_map()
{
    gw_c1_main(world.country[0].map);
    gw_c2_main(world.country[1].map);
    gw_c3_main(world.country[2].map);
    gw_c4_main(world.country[3].map);
    gw_c5_main(world.country[4].map);
    gw_c0_def();
    pl.country=0;
    pl.X=5;
    pl.Y=5;
    pl.wallkick=FALSE;
    pl.money=20000;
    pl.authority=50;
    world.cut_cap=0;
    //init_army();
    for(gint i=0;i<10;i++)
        pl.army[i].armid=0;
    pl.workers.carpenter=4;
    pl.workers.woodsman=6;
    pl.workers.groundsman=0;
    pl.workers.stonesman=3;
    tmpv_wrk=0;
}

gint8 cstep(int x, int y,gint ox=0,gint oy=0)
{
    if(gui_dialog_showed){
        gui_dialog_hideall();
        //gui_dlg_showed=FALSE;
        return 0;
    }
    if(world.country[pl.country].map[x][y].obj==o_nave){
        pl.Y=y;
        pl.X=x;
        pl.innave=TRUE;
        return 1;
     }
    if((world.country[pl.country].map[x][y].land==l_water)&&(pl.innave==TRUE)){
        gboolean s=FALSE;
        if((x>1)&&(x<63)){pl.X=x;s=TRUE;}
        if((y>1)&&(y<63)){pl.Y=y;s=TRUE;}
        //pl.X=x;s=TRUE;
        //pl.Y=y;s=TRUE;
        if(s){world.country[pl.country].map[ox][oy].obj=0;
        world.country[pl.country].map[pl.X][pl.Y].obj=o_nave;}
        world.naveX=pl.X;
        world.naveY=pl.Y;
        world.naveC=pl.country;
        return 1;
     }
     if((world.country[pl.country].map[x][y].land==l_plot)&&(world.country[pl.country].map[x][y].obj==0)){
        pl.X=x;
        pl.Y=y;
        return 1;
     }
     if(((world.country[pl.country].map[x][y].land==l_land)||(world.country[pl.country].map[x][y].land==l_sand))&&(world.country[pl.country].map[x][y].obj==0)){
        pl.X=x;
        pl.Y=y;
        if(pl.innave){pl.innave=FALSE;}
        return 1;
     }
     if(world.country[pl.country].map[x][y].obj==o_guidepost){
        gchar *s2=text_get_strid("sid_guidepost_name");
        gchar *s1=text_get_strid_rand("sid_guidepost",12);
        gui_dialog_show(s2,s1);
        delete[] s1;
        delete[] s2;
        gui_dialog_showed=TRUE;
        return 0;
     }
     if(world.country[pl.country].map[x][y].obj==o_city){
        Tmenu m=gui_menu_city_set(world.country[pl.country].map[x][y].addid);
        gui_keylock_event=o_city;
        tmpv_city=world.country[pl.country].map[x][y].addid;
        gui_menu_show(m);
        gui_menu_free(m);
     }
     if(world.country[pl.country].map[x][y].obj==o_army){
        gui_keylock_event=o_army;
        gui_byarmy_show(world.country[pl.country].map[x][y].addid);
     }
     if(world.country[pl.country].map[x][y].obj==o_goldchest){
        Tmenu m=gui_menu_set_gold();
        gui_keylock_event=o_goldchest;
        gui_menu_show(m);
        gui_menu_free(m);
        world.country[pl.country].map[x][y].obj=0;
     }
     return -1;
}

id** gui_getA()
{
    id **a=new id*[10];
    for(int i=0;i<10;i++){a[i]=new id[10];}
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a[i][j]=world.country[pl.country].map[pl.X-2+i][pl.Y-2+j].land;
            if(world.country[pl.country].map[pl.X-2+i][pl.Y-2+j].obj!=0){a[i][j]=world.country[pl.country].map[pl.X-2+i][pl.Y-2+j].obj;}
    }}
    if(!pl.innave){
        a[2][2]=o_player;
    }else{
        a[2][2]=o_nave;
    }
    if(pl.wallkick)
        a[5][1]=s_wallkick_c;
    else
        a[5][1]=s_wallkick_b;

    if(pl.contract)
        a[5][0]=s_contract_c;
    else
        a[5][0]=s_contract_b;

    a[5][2]=s_magic_0;
    a[5][3]=s_money_0;
    a[5][4]=s_ancientmap_0;
    a[9][9]=world.country[pl.country].map[pl.X][pl.Y].land;

    return a;
}

void gui_freeA(id **A)
{
     for(int i=0;i<10;i++){delete A[i];}
     delete A;
}

id** procw(id key)
{
    gint8 r=0;
    if(gui_dialog_showed){gui_dialog_hideall();return gui_getA();}
    if(key==key_down){
        r=cstep(pl.X,pl.Y+1,pl.X,pl.Y);
    }
    if(key==key_up){
        r=cstep(pl.X,pl.Y-1,pl.X,pl.Y);
    }
    if(key==key_right){
        r=cstep(pl.X+1,pl.Y,pl.X,pl.Y);
    }
    if(key==key_left){
        r=cstep(pl.X-1,pl.Y,pl.X,pl.Y);
    }
    if(r==1){
        return gui_getA();
    }else{return 0;}
}
