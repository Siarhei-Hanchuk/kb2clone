#include "header.h"
#include "Error.h"
#include "texts.h"
#include "charstr.h"
#include "procc.h"

//Tplayer pl;
//Tworld world;

void pl_nave_get()
{
    for(gint16 a=pl.X-1;a<pl.X+1;a++){
        for(gint16 b=pl.Y-1;b<pl.Y+1;b++)
        {
            if(world.country[pl.country].map[a][b].land==l_water){
                world.country[pl.country].map[a][b].obj=o_nave;
                world.naveX=a;
                world.naveY=b;
                world.naveC=pl.country;
                return;
            }
        }
    }
}

gchar* gui_getimgpath(id imgid)
{
    gchar *s=new gchar[256];
    strcpy(s,datapath);
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
        strcpy(s,datapath);
        strcat(s,"/images/emo.png");
    }
    return s;
}

void gui_bkdlg_show(cairo_t *cr)
{
    cairo_move_to(cr,0,screenh-125);
    cairo_set_source_rgb(cr, 0,0,0);
    cairo_set_line_width (cr,250);
    cairo_line_to(cr,screenw-160,screenh-125);
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 255/255, 255/255, 255/255);
    cairo_set_line_width (cr, 4);

    cairo_move_to(cr,2,screenh-125*2);
    cairo_line_to(cr,2,screenh);
    cairo_move_to(cr,0,screenh);
    cairo_line_to(cr,screenw-160,screenh);
    cairo_move_to(cr,screenw-160-2,screenh);
    cairo_line_to(cr,screenw-160-2,screenh-125*2);
    cairo_move_to(cr,screenw-160-2,screenh-125*2);
    cairo_line_to(cr,2,screenh-125*2);

    cairo_stroke(cr);
}

void gui_dialog_show(const gchar *head, const gchar *msg)
{
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    gui_bkdlg_show(cr);

    cairo_move_to(cr,20,460);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
    cairo_show_text(cr,msg);
    cairo_move_to(cr,100,378);
    cairo_show_text(cr,head);
    cairo_stroke(cr);
    cairo_destroy(cr);
//    cairo_surface_destroy(cst);
}

void gui_draw_image_form_file(cairo_t *cr,const gchar *path, int x, int y)
{
    cairo_surface_t *  cst=cairo_image_surface_create_from_png(path);
    cairo_set_source_surface(cr, cst, x, y);
    cairo_paint (cr);
    cairo_surface_destroy(cst);
}

void gui_draw_image_cst(cairo_t *cr,cairo_surface_t *cst, int x, int y)
{
    cairo_set_source_surface(cr, cst, x, y);
    cairo_paint (cr);
}

void gui_printgame(id **A)
{
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    if(A==NULL){return;}
    lastA=A;
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            gui_draw_image_cst(cr,IMAGES[A[i][j]],160*i,120*j);
            }
    }
    cairo_destroy(cr);
}

void gui_draw_point(cairo_t* cr,gint16 x,gint16 y, gint16 size,double red, double green, double blue)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb(cr, red/255,green/255, blue/255);
    cairo_set_line_width (cr, size);
    cairo_line_to(cr,x+size,y);
    cairo_stroke(cr);
}

void gui_draw_line(cairo_t* cr,gint16 x,gint16 y, gint16 X,gint16 Y, gint16 size,double red, double green, double blue)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb(cr, red/255,green/255, blue/255);
    cairo_set_line_width (cr, size);
    cairo_line_to(cr,X,Y);
    cairo_stroke(cr);
}

void gui_textsid_print(cairo_t *cr, const gchar *sid,gint x, gint y)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
    gchar *s=text_get_strid(sid);
    cairo_show_text(cr,s);
    free(s);
}

void gui_text_print(cairo_t *cr, const gchar *s,gint x, gint y)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
    cairo_show_text(cr,s);
}

void w3_gs(gchar *&s,const gchar *sid, gint64 i)
{
    s=text_get_strid(sid);
    strcat(s,": ");
    strcat(s,itoa(i));
}

void gui_byarmy_show(gint8 armid)
{
    w3_armi=armid;
    gint x=20;
    gint i=armid;
    gchar *s=NULL;
    cairo_t *cr=gdk_cairo_create(drawarea->window);;
    gui_bkdlg_show(cr);
    gui_textsid_print(cr,armys[i].name,30,x+370);
    w3_gs(s,"sid_byarmy_money",pl.money);
    strcat(s,"$");
    gui_text_print(cr,s,900-160-150,x+370);
    w3_gs(s,"sid_byarmy_count",armys[i].count);
    gui_text_print(cr,s,30,x+410);
    w3_gs(s,"sid_byarmy_cost",armys[i].cost);
    gui_text_print(cr,s,185,x+410);
    w3_gs(s,"sid_byarmy_move",armys[i].step);
    gui_text_print(cr,s,30,x+470);
    w3_gs(s,"sid_byarmy_defence",armys[i].defence);
    gui_text_print(cr,s,30,x+493);
    w3_gs(s,"sid_byarmy_damage",armys[i].damage);
    gui_text_print(cr,s,30,x+516);
    w3_gs(s,"sid_byarmy_fly",armys[i].fly);
    gui_text_print(cr,s,30,x+539);
    w3_gs(s,"sid_byarmy_youmust",int(pl.authority/armys[i].defence));
    gui_text_print(cr,s,900-160-150-50,x+470);
    gui_textsid_print(cr,"sid_byarmy_how",900-160-150+30,x+539);
    cairo_stroke(cr);

    gui_draw_image_cst(cr,IMAGES[armid],0,240);
}

void gui_map_show()
{
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    cairo_set_line_width (cr, 570);
    cairo_move_to(cr,110,310);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_line_to(cr,650,310);
    cairo_stroke(cr);
    cairo_move_to(cr,315,50);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
    gchar *s=text_get_strid("sid_map_name");
    cairo_show_text(cr,s);
    delete []s;
    cairo_stroke(cr);
    ////
    int ui=120;
    int uj=60;
    for(int i=0;i<MAXC;i++){
        for(int j=0;j<MAXC;j++){
            if((i==pl.X)&&(j==pl.Y)){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,138,131,121);
            }else
            if(world.country[pl.country].map[i][j].obj==o_guidepost){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,200,0,165);
            }else
            if(world.country[pl.country].map[i][j].obj==o_city){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,231,116,5);
            }else
            if(world.country[pl.country].map[i][j].obj==o_goldchest){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,140,116,5);
            }else
            if(world.country[pl.country].map[i][j].obj==o_castel_c){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,233,233,233);
            }else
            if(world.country[pl.country].map[i][j].obj==o_castel_r){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,233,233,233);
            }else
            if(world.country[pl.country].map[i][j].obj==o_castel_l){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,233,233,233);
            }else
            if(world.country[pl.country].map[i][j].obj==o_capitan){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,152,17,17);
            }else
            if(world.country[pl.country].map[i][j].obj==o_army){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,255,255,255);
            }else
            if(world.country[pl.country].map[i][j].obj!=0){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,255,255,255);
            }else
            if(world.country[pl.country].map[i][j].land==l_water){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,0,0,255);
            }else
            if(world.country[pl.country].map[i][j].land==l_forest){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,0,120,0);
            }else
            if(world.country[pl.country].map[i][j].land==l_stone){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,63,40,8);
            }else
            if(world.country[pl.country].map[i][j].land==l_land){
                gui_draw_point(cr,ui+i*8,uj+j*8,8,0,255,0);
            }else
                gui_draw_point(cr,ui+i*8,uj+j*8,8,255,255,255);
    }}
}

Tmenu gui_menu_city_set(id cityid)
{
    Tmenu r;
    r.p[0]=text_get_strid("sid_city_menu_title");
    r.p[1]=text_get_strid("sid_city_menu_p1");
        if(!pl.nave)
        r.p[2]=text_get_strid("sid_city_menu_p2");
        else
        r.p[2]=text_get_strid("sid_city_menu_p2a");
    r.p[3]=text_get_strid("sid_city_menu_p3");
    r.p[4]=text_get_strid("sid_city_menu_p4");
        if(!pl.wallkick)
        r.p[5]=text_get_strid("sid_city_menu_p5");
        else
        r.p[5]=text_get_strid("sid_city_menu_p5a");
    r.p[6]=text_get_strid("sid_city_menu_p6");
    r.p[7]=text_get_strid("sid_city_menu_p7");
    //r.p8=text_get_strid("sid_city_menu_p8");
    r.p[8]=NULL;
    return r;
}

Tmenu gui_menu_navi_set()
{
    Tmenu r;
    r.p[0]=text_get_strid("sid_navi_menu_title");
    r.p[1]=text_get_strid("sid_navi_menu_p1");
    r.p[2]=text_get_strid("sid_navi_menu_p2");
    r.p[3]=text_get_strid("sid_navi_menu_p3");
    r.p[4]=text_get_strid("sid_navi_menu_p4");
    r.p[5]=text_get_strid("sid_navi_menu_p5");
    r.p[6]=NULL;
    return r;
}

Tmenu gui_menu_set_gold()
{
    tmpv_gold=(rand()%25+20)*10;
    Tmenu r;
    r.p[0]=text_get_strid("sid_goldchest_menu_title");
    strcat(r.p[0],itoa(tmpv_gold));
    r.p[1]=text_get_strid("sid_goldchest_menu_p1");
    r.p[2]=text_get_strid("sid_goldchest_menu_p2");
    strcat(r.p[2],itoa(tmpv_gold/50));
    r.p[3]=NULL;
    return r;
}

void gui_menu_free(Tmenu m)
{
    int i=0;
    while(m.p[i]!=0){
        free(m.p[i]);
        i++;
    }
}

void gui_menu_show(Tmenu m)
{
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    gui_bkdlg_show(cr);

    cairo_move_to(cr,100,378);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);

    int i=0;
    while(m.p[i]!=NULL){
        cairo_show_text(cr,m.p[i]);
        cairo_move_to(cr,20,410+i*20);
        i++;

    }
    cairo_stroke(cr);
    cairo_destroy(cr);
}

void gui_dialog_hideall()
{
    gui_printgame(lastA);
    gui_dialog_showed=FALSE;
}

void gui_refresh()
{
    id **A=gui_getA();
    gui_printgame(A);
    gui_freeA(A);
}

void gui_menu_city_proc(gint8 key)
{
    if(key==key_esc){
        gui_keylock_event=0;
        gui_refresh();
        return;
    }
    if(key==key_6){
        //gui_menu_city_wtk_show();


    }
    if(key==key_5){
        if(pl.wallkick){return;}
        pl.wallkick=TRUE;
        pl.money-=3000;
        gui_refresh();
        Tmenu m=gui_menu_city_set(tmpv_city);
        gui_menu_show(m);
    }
    if(key==key_2){
        if(!pl.nave){
            pl.nave=TRUE;
            pl_nave_get();
            pl.money-=500;
            Tmenu m=gui_menu_city_set(tmpv_city);
            gui_menu_show(m);
            return;
        }
        if(pl.nave){
            pl.nave=FALSE;
            Tmenu m=gui_menu_city_set(tmpv_city);
            gui_menu_show(m);
            world.country[world.naveC].map[world.naveX][world.naveY].obj=0;
        }
        gui_refresh();
        return;
    }

}

void gui_menu_gold_proc(gint8 key)
{
    if(key==key_1){
        pl.money+=tmpv_gold;
    }else
    if(key==key_2){
        pl.authority+=int(tmpv_gold/50);
    }else return;
    gui_keylock_event=0;
    gui_refresh();
}

void gui_menu_navi_proc(gint32 key)
{
    pl.country=key-1;
    pl.X=2;
    pl.Y=2;
    gui_keylock_event=0;
}

void gui_magic_show()
{

}

void gui_status_show()
{
    const int v2=240;
    const int v3=310;
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    cairo_move_to(cr,0,screenh/2);
    cairo_set_source_rgb(cr, 0/255,0/255, 0/255);
    cairo_set_line_width (cr, screenh+10);
    cairo_line_to(cr,screenw-160,300);
    cairo_stroke(cr);
    gchar *s;
    cairo_set_font_size(cr, 14);
    cairo_set_source_rgb (cr, 255, 255, 200);

    cairo_move_to(cr,10,30);
    s=text_get_strid("sid_status_authority");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,v2+10,30);
    s=itoa(pl.authority);
    cairo_show_text(cr,s);
    free(s);

    cairo_move_to(cr,10,70);
    s=text_get_strid("sid_status_gold");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,v2+10,70);
    s=itoa(pl.money);
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,10,90);
    s=text_get_strid("sid_status_salary");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,v2+10,90);
    s=text_get_strid("err_0");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,10,110);
    s=text_get_strid("sid_status_expenseofarmy");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,v2+10,110);
    s=text_get_strid("err_0");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,10,150);
    s=text_get_strid("sid_status_magic");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,v2+10,150);
    s=itoa(pl.magic);
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,10,170);
    s=text_get_strid("sid_status_maxmagic");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,v2+10,170);
    s=text_get_strid("err_0");
    cairo_show_text(cr,s);
    free(s);

    cairo_move_to(cr,10,210);
    s=text_get_strid("sid_status_tornado");
    cairo_show_text(cr,s);
    free(s);
    cairo_move_to(cr,10,230);
    s=text_get_strid("sid_status_countoldmap");
    cairo_show_text(cr,s);
    free(s);
//
    cairo_move_to(cr,v2,0);
    cairo_set_line_width (cr, 3);
    cairo_line_to(cr,v2,250);
    cairo_move_to(cr,2,0);
    cairo_set_line_width (cr, 4);
    cairo_line_to(cr,2,250);
    cairo_move_to(cr,v3,0);
    cairo_set_line_width (cr, 4);
    cairo_line_to(cr,v3,250);
    //
    cairo_move_to(cr,0,2);
    cairo_set_line_width (cr, 3);
    cairo_line_to(cr,v3,2);
    cairo_move_to(cr,0,39);
    cairo_set_line_width (cr, 3);
    cairo_line_to(cr,v3,39);
    cairo_move_to(cr,0,125);
    cairo_set_line_width (cr, 3);
    cairo_line_to(cr,v3,125);
    cairo_move_to(cr,0,190);
    cairo_set_line_width (cr, 3);
    cairo_line_to(cr,v3,190);
    cairo_move_to(cr,0,250);
    cairo_set_line_width (cr, 3);
    cairo_line_to(cr,v3,250);
    //
    cairo_stroke(cr);
    gui_dialog_showed=TRUE;
}

void gui_byarmy_proc(gint8 key)
{
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    if((key>=48)&&(key<=57)){
        w3_yy=w3_yy*10+(key-48);
        gui_text_print(cr,itoa(key-48),715+w3_ty*10,558);
        w3_ty++;
    }
    if(key==key_enter)
    {
        if(pl.army[9].armid!=0){
            //!
            return;
        }
        if(w3_yy*armys[w3_armi].defence>pl.authority){
            w3_ty=0;
            w3_yy=0;
            gui_draw_line(cr,715,553,780,553,20,0,0,0);
            return;
        }else{
            pl.money=pl.money-armys[w3_armi].cost*w3_yy;
            gint8 i=0;
            while((pl.army[i].armid!=0)||(pl.army[i].armid==w3_armi)){
                i++;
            }
            pl.army[i].armid=w3_armi;
            pl.army[i].count=w3_yy;

            gui_keylock_event=0;


            w3_ty=0;
            w3_yy=0;

            gui_printgame(lastA);
            return;
        }
    }
    if(key==key_backspace)
    {
        w3_ty=0;
        w3_yy=0;
        gui_draw_line(cr,715,553,780,553,20,0,0,0);
    }
    if(key==key_esc){
            gui_keylock_event=0;
            //cout<<key

            gui_printgame(lastA);
            return;
    }
}

void gui_army_show()
{
    cairo_t *cr = gdk_cairo_create(drawarea->window);
    cairo_move_to(cr,0,screenh/2);
    cairo_set_source_rgb(cr, 0/255,0/255, 0/255);
    cairo_set_line_width (cr, screenh+10);
    cairo_line_to(cr,screenw-160,300);
    cairo_stroke(cr);
    int i=0;
    while(pl.army[i].armid!=0){
        gui_draw_image_cst(cr,IMAGES[pl.army[i].armid],0,screenh/5*i);
        i++;
    }
}

Tmenu gui_menu_workers_set()
{
    Tmenu r;
    r.p[0]=text_get_strid("sid_workers_menu_title");
    r.p[1]=text_get_strid("sid_workers_menu_p1");
    r.p[2]=text_get_strid("sid_workers_menu_p2");
    r.p[3]=text_get_strid("sid_workers_menu_p3");
    r.p[4]=text_get_strid("sid_workers_menu_p4");
    r.p[5]=NULL;
    return r;
}

void gui_workers_proc(gint8 key)
{
    if(key==key_esc){
        tmpv_wrk=0;
        gui_refresh();
        gui_keylock_event=0;
    }
    if(tmpv_wrk==0)
    {
        switch(key){
        case key_1:
            tmpv_wrk=l_water;
            break;
        case key_2:
            tmpv_wrk=l_forest;
            break;
        case key_3:
            tmpv_wrk=l_land;
            break;
        case key_4:
            tmpv_wrk=l_stone;
            break;
        }
        return;
    }
    gboolean rb=FALSE;
    if((key==key_down)&&(world.country[pl.country].map[pl.X][pl.Y+1].land==tmpv_wrk)){
        world.country[pl.country].map[pl.X][pl.Y+1].land=l_land;
        rb=TRUE;
        if(tmpv_wrk==l_water){
            world.country[pl.country].map[pl.X][pl.Y+1].land=l_plot;
        }
    }
    if((key==key_up)&&(world.country[pl.country].map[pl.X][pl.Y-1].land==tmpv_wrk)){
        world.country[pl.country].map[pl.X][pl.Y-1].land=l_land;
        rb=TRUE;
        if(tmpv_wrk==l_water){
            world.country[pl.country].map[pl.X][pl.Y-1].land=l_plot;
        }
    }
    if((key==key_right)&&(world.country[pl.country].map[pl.X+1][pl.Y].land==tmpv_wrk)){
        world.country[pl.country].map[pl.X+1][pl.Y].land=l_land;
        rb=TRUE;
        if(tmpv_wrk==l_water){
            world.country[pl.country].map[pl.X+1][pl.Y].land=l_plot;
        }
    }
    if((key==key_left)&&(world.country[pl.country].map[pl.X-1][pl.Y].land==tmpv_wrk)){
        world.country[pl.country].map[pl.X-1][pl.Y].land=l_land;
        rb=TRUE;
        if(tmpv_wrk==l_water){
            world.country[pl.country].map[pl.X-1][pl.Y].land=l_plot;
        }
    }
    if(rb==TRUE){
        gui_refresh();
        gui_keylock_event=0;
        switch(tmpv_wrk){
        case l_forest:
            pl.workers.woodsman--;
            break;
        case l_land:
            pl.workers.groundsman--;
            break;
        case l_water:
            pl.workers.carpenter--;
            break;
        case l_stone:
            pl.workers.stonesman--;
            break;
        }

        tmpv_wrk=0;
    }
}

void gui_workers_show()
{
    Tmenu m=gui_menu_workers_set();
    gui_menu_show(m);
    cairo_t *cr=gdk_cairo_create(drawarea->window);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
        cairo_move_to(cr,160,410);
        cairo_show_text(cr,itoa(pl.workers.carpenter));
        cairo_move_to(cr,160,430);
        cairo_show_text(cr,itoa(pl.workers.woodsman));
        cairo_move_to(cr,160,450);
        cairo_show_text(cr,itoa(pl.workers.groundsman));
        cairo_move_to(cr,160,470);
        cairo_show_text(cr,itoa(pl.workers.stonesman));
    cairo_destroy(cr);
}

void gui_pressing_key(GtkWidget *buuton, GdkEventKey *event, gpointer func_data)
{
    gint8 key=event->keyval;
        if(gui_keylock_event==o_army){
            gui_byarmy_proc(key);
            return;
        }
        if(gui_keylock_event==o_city){
            gui_menu_city_proc(key);
            return;
        }
        if(gui_keylock_event==o_goldchest){
            gui_menu_gold_proc(key);
            return;
        }
        if(gui_keylock_event==e_navi){
            gui_menu_navi_proc(key);
            return;
        }
        if(gui_keylock_event==e_workers){
            gui_workers_proc(key);
            return;
        }

    if(gui_dialog_showed==TRUE){
        gui_dialog_hideall();
        return;
    }
    if(key==key_map){
        gui_map_show();
        gui_dialog_showed=TRUE;
        return;
    }
    if(key==key_v){
        gui_status_show();
        gui_dialog_showed=TRUE;
        return;
    }
    if(key==key_w){
        gui_workers_show();
        gui_keylock_event=e_workers;
        return;
    }
    if(key==key_n){
        if(!pl.innave){return;}
        Tmenu m=gui_menu_navi_set();
        gui_keylock_event=e_navi;
        gui_menu_show(m);
        gui_menu_free(m);
        return;
    }
    if(key==key_arm){
        gui_army_show();
        gui_dialog_showed=TRUE;
        return;
    }

    id **a;
    a=procw(key);
    gui_printgame(a);
    //delete a;&!!
}

void cache_images(cairo_surface_t **&arr)
{
    int maxid=120;
    arr=new cairo_surface_t*[maxid];
    gchar *s=new char[maxid];
    for(int i=0;i<maxid;i++){
        s=gui_getimgpath(i);
        arr[i]=cairo_image_surface_create_from_png(s);
    }
}

static void gui_destroy(GtkWidget* window, gpointer data)
{
	gtk_main_quit();
}

void gui_init(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "KB2");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_set_size_request(window, 960, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);

    drawarea=gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawarea);

    g_signal_connect(window, "key_press_event", G_CALLBACK(gui_pressing_key), NULL);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gui_destroy), NULL);
    gtk_widget_show_all(window);
    gtk_main();
}
