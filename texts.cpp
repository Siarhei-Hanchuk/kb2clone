#include "header.h"
#include "charstr.h"
#include "Error.h"

int LoadFile(const gchar *fn,gchar *&file)
//!Загрука файла в оперативную память, возвращает размер или -1 если файл не удалось открыть
{
    FILE *f=fopen(fn,"r");
    if(f==NULL){fclose(f);return -1;}
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
    strcpy(pt,datapath);
    strcat(pt,"/texts/russian.txt");
    #ifdef WIN32
        win32_slash(pt);
    #endif
    LoadFile(pt,data);
}

gchar *text_get_strid(const gchar *strid)
{
    char *s=new char[256];memset(s,0,256);
    int i=pos(strid,langfile);
    int j=0;
    if(i!=-1){
        i=i+strlen(strid)+1;
        while(langfile[i]!=10){
            s[j]=langfile[i];
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
