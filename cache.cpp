#include <gtk/gtk.h>
#include <string.h>
#include "header.h"

void cache_army()
{
    Tarmys *a=new Tarmys[25];
    gint64 size=sizeof(Tarmys);
    gchar *fn=new gchar[256];
    cout<<"DP:"<<datapath<<endl;
    strcpy(fn,datapath);
    strcat(fn,"/armydata");
    FILE *f;
    f=fopen(fn,"r");
    fread(a,size,25,f);
    fclose(f);
    for(int i=0;i<25;i++){
        armys[i+51]=a[i];
        strcpy(armys[i+51].name,a[i].name);
    }
}

