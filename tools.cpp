#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "header.h"

extern gchar *datapath;

gchar *tools_getparm(gchar *s,gint n)
{
    int u=1;
    int i=0;
    int j=0;
    gchar *r=new gchar[256];
    while(u<n){
        if(s[i]==' '){u++;}
        i++;
    }
    while((s[i]!=' ')&&(s[i]!=0)){
        r[j]=s[i];
        i++;
        j++;
    }
    r[j]=0;
    return r;
}

void tool_armedit(gchar *s)
{
    gint64 size=sizeof(Tarmys);
    gchar *fn=new gchar[256];
    strcpy(fn,datapath);
    strcat(fn,"/armydata");
    FILE *f;
    if(s[0]=='d'){
        gchar *cmd=new gchar[256];
        strcpy(cmd,"rm ");
        strcat(cmd,fn);
        system(cmd);
    }
    if(s[0]=='c'){
        gchar *pr=tools_getparm(s,2);
        Tarmys *a=new Tarmys[25];
        f=fopen(fn,"w");
        fwrite(a,size,atoi(pr),f);
        fclose(f);
        strcpy(s,datapath);
    }
    if(s[0]=='w'){
        Tarmys *a=new Tarmys[25];
        f=fopen(fn,"r");
        fread(a,size,25,f);
        fclose(f);
        gchar *pr=tools_getparm(s,2);
        gint i=atoi(pr);
        free(pr);
        strcpy(a[i].name,tools_getparm(s,3));
        a[i].defence=atoi(tools_getparm(s,4));
        a[i].damage=atoi(tools_getparm(s,5));
        a[i].step=atoi(tools_getparm(s,6));
        a[i].fly=atoi(tools_getparm(s,7));
        a[i].shoot=atoi(tools_getparm(s,8));
        a[i].count=atoi(tools_getparm(s,9));
        a[i].cost=atoi(tools_getparm(s,10));
        f=fopen(fn,"w");
        fwrite(a,size,25,f);
        fclose(f);
    }
    if(s[0]=='p'){
        Tarmys *a=new Tarmys[25];
        for(int i=0;i<25;i++){
            memset(a[i].name,0,32);
        }
        f=fopen(fn,"r");
        fread(a,size,25,f);
        fclose(f);
        for(int i=0;i<25;i++){
            std::cout<<i<<": "<<a[i].name<<" "<<int(a[i].defence)<<" "<<a[i].damage<<" "<<int(a[i].step)<<" "<<int(a[i].fly)<<" "<<bool(a[i].shoot)<<" "<<a[i].count<<" "<<a[i].cost<<'\n';
        }
    }
    delete fn;
}

