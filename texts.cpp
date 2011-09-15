#include "header.h"
#include "charstr.h"
#include "Error.h"

gchar *text_get_strid(const gchar *strid)
{
    char *s=new char[256];memset(s,0,256);
    int i=pos(strid,GV.langfile);
    int j=0;
    if(i!=-1){
        i=i+strlen(strid)+1;
        while(GV.langfile[i]!=10){
            s[j]=GV.langfile[i];
            j++;
            i++;
            if(j>200){return NULL;}
        }
        s[j]=0;
        return s;
    }else{
        strcpy(s,strid);
        err_log("unknow string",strid);
        return s;
    }
}

gchar *text_get_strid_rand(const gchar *strid,gint8 mn)
{
    gchar *s=new gchar[256];
    strcpy(s,strid);
    strcat(s,"_");
    char *i=itoa(rand()%(mn)+1);
    strcat(s,i);
    delete i;
    char *u=text_get_strid(s);
    delete s;
    return u;
}
