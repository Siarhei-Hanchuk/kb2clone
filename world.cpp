#include "header.h"

//extern Tworld world;

void gw_all_base(Tmap &map)
{
    //Заполнение всей карты водой
    for(gint16 i=0;i<MAXC; i++){
        for(gint16 j=0;j<MAXC; j++){
            map[i][j].land=l_water;
        }
    }
    //Заполнение всей карты базовой землёй
    for(gint16 i=5;i<MAXC-5; i++){
        for(gint16 j=5;j<MAXC-5; j++){
            map[i][j].land=l_land;
        }
    }
    //Обнудение obj
    for(gint16 i=5;i<MAXC-5; i++){
        for(gint16 j=5;j<MAXC-5; j++){
            map[i][j].obj=0;
            map[i][j].addid=0;
        }
    }
}

void gw_all_cities(Tmap &map)
{//Установка 5 городов в любую страну
    //gint16 r=0;
    gint16 v=0;
    gint8 x;
    gint8 y;
      while(v<5){
            x=rand()%MAXC;
            y=rand()%MAXC;
            if(((map[x+1][y].land==l_water)||(map[x-1][y].land==l_water)||(map[x][y+1].land==l_water)||(map[x][y-1].land==l_water))&&
            ((map[x][y].land==l_land))){
                    map[x][y].obj=o_city;
                    map[x][y].addid=v;
                    v++;
                }
        }
}

void gw_all_guidepost(Tmap &map)
{
    gint16 c=0;
//    gint16 r=0;
    gint8 x=0;
    gint8 y=0;
    while(c<8){
        y=rand()%54+5;
        x=rand()%54+5;
        if((map[x][y].land==l_land)||(map[x][y].land==l_sand)){
           map[x][y].obj=o_guidepost;
        }
        c++;
    }
}

void gw_all_goldchest(Tmap &map,gint16 t=40)
{
    gint16 c=0;
    gint16 r=0;
    for(gint16 i=5;i<MAXC-5; i++){
        for(gint16 j=5;j<MAXC-5; j++){
            if(((map[i][j].land==l_land)||(map[i][j].land==l_sand))&&(map[i][j].obj==0)){
                r=rand()%t;
                    if(r==1){
                        map[i][j].obj=o_goldchest;
                        c++;
                    }
            }
    }}
}

void gw_all_castels(Tmap &map)
{
    int x=0;
    int y=0;
    int c=0;
    while(c<5){
        x=rand()%MAXC;
        y=rand()%MAXC;
        if((map[x][y].land==l_land)&&(map[x-1][y].land==l_land)&&(map[x+1][y].land==l_land)&&(map[x][y+1].land==l_land)){
            map[x][y].obj=o_castel_c;
            map[x+1][y].obj=o_castel_r;
            map[x-1][y].obj=o_castel_l;
            map[x][y].addid=c;
            map[x][y+1].obj=o_capitan;
            map[x][y+1].addid=world.cut_cap;
            world.cut_cap++;
            c++;

        }
    }
}

void gw_c1_army(Tmap &map)
{//Заполнения равнолесья воинами
    //gint16 r=0;
    gint8 v=0+51;
    gint8 x;
    gint8 y;
    while(v<10+51){
        x=rand()%65;
        y=rand()%65;
            if((map[x][y].obj==0)&&(map[x][y].land==l_land)){
                map[x][y].obj=o_army;
                map[x][y].addid=v;
                v++;
            }
    }
}

void gw_c1_land(Tmap &map)
{//Заполнения равнолесья лесом, скалами и тп.
    gint16 r=0;gint16 r2=0;
     for(gint16 i=6;i<MAXC-6; i++){
        for(gint16 j=6;j<MAXC-6; j++){
            r=rand()%7;
            r2=rand()%20;
            if((map[i][j].obj==0)&&(map[i][j].land==l_land)){
                if(r==1){map[i][j].land=l_forest;}
                if(r2==1){map[i][j].land=l_stone;}
            }
        }
    }
}

void gws_all_river1(Tmap &map,int x,int y,gint8 pm,gint16 pl=10)
{
    int p=0;
    while(p<pl){
        p++;
        for(int o=-2;o<3;o++){
            map[x][y+o].land=l_water;
        }
        y=y+rand()%5-2;
        x+=pm;
    }

}

void gws_all_river2(Tmap &map,int x,int y,gint8 pm,gint16 pl=10)
{
    int p=0;
    int q=0;
    int w=0;
    while(p<pl){
        p++;
        q=rand()%2;
        q=rand()%3;
        for(int o=-q-1;o<w+2;o++){
            map[x+o][y].land=l_water;
        }
        x=x+rand()%5-2;
        y+=pm;
    }

}

void gw_all_river(Tmap &map,gint16 pl=10)
{
    int x=5;
    int y=30;
    int r=rand()%4;
    if(r==0){ x=5;   y=rand()%54+5; gws_all_river1(map,x,y,1,pl);}
    if(r==1){ x=59; y=rand()%54+5; gws_all_river1(map,x,y,-1,pl);}
    if(r==2){ y=5;   x=rand()%54+5; gws_all_river2(map,x,y,1,pl);}
    if(r==3){ y=59; x=rand()%54+5; gws_all_river2(map,x,y,-1,pl);}
}

void gw_c1_main(Tmap &map)
{//Выполнение всех функций по генерации равнолесья
    gw_all_base(map);
    gw_all_river(map,30);
    gw_all_river(map,20);
    gw_all_river(map,40);
    gw_c1_land(map);
    gw_all_castels(map);
    gw_all_cities(map);
    gw_all_guidepost(map);
    gw_all_goldchest(map);
    gw_c1_army(map);

}

void gw_c2_main(Tmap &map)
{
    gw_all_base(map);
}

void gw_c3_main(Tmap &map)
{
    gw_all_base(map);
}

void gw_c4_main(Tmap &map)
{
    gw_all_base(map);
}

void gw_c5_sand(Tmap &map)
{
    for(int i=6;i<59;i++){
        for(int j=6;j<11;j++){
         map[i][j].land=l_sand;
         map[j][i].land=l_sand;
        }
    }
    for(int i=6;i<59;i++){
        for(int j=54;j<59;j++){
         map[j][i].land=l_sand;
         map[i][j].land=l_sand;
        }
    }
}

void gw_c5_stone(Tmap &map)
{
    for(int i=11;i<MAXC-11;i++){
        for(int j=11;j<MAXC-11;j++){
            if((map[i][j].obj==0)&&(map[i][j].land==l_land)){
                int r=rand()%30;
                if(r<16){
                    map[i][j].land=l_stone;
                }
            }
        }
    }
}

void gw_c5_main(Tmap &map)
{
    gw_all_base(map);
    gw_c5_sand(map);
    gw_all_river(map);
    gw_all_cities(map);
    gw_c5_stone(map);
    gw_all_goldchest(map,100);
    gw_all_guidepost(map);
}

