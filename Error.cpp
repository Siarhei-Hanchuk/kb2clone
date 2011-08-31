#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

void err_log(const gchar *type,const gchar *error)
{
    time_t t;
    struct tm *ts;
    char buf[80];
    t = time(0);
    ts = localtime(&t);
    t=time(0);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
    ///!---
    FILE *f;
    #ifdef __unix
        f=fopen("/home/siarhei/Projects/KB2/result/errors.log","a");
    #endif
    #ifdef WIN32
        f=fopen("c:\\KB2log.log","a");
    #endif
    gchar *s=(gchar *)malloc(sizeof(gchar)*1024);s[0]=0;
    //
    strcat(s,buf);
    strcat(s," ");
    strcat(s,type);
    strcat(s,": ");
    strcat(s,error);
    strcat(s,"\n");
    fputs(s,f);
    fclose(f);
}

bool err_fileexists(const char *fname)
{
    return  std::ifstream(fname) != NULL;
}
