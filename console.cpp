#include "header.h"
#include "tools.h"

gboolean coip(int argc, char *argv[])
{
    if(argc>1)
    {
        if((strcmp(argv[1],"--version")==0)||(strcmp(argv[1],"-v")==0)){
            std::cout<<"kb2clone 0.2.x\n";
            return FALSE;
        }
        if((strcmp(argv[1],"--tool")==0)||(strcmp(argv[1],"-t")==0)){
            if(argc<3){
                cout<<"--tool <toolname>\n";
                return FALSE;
            }

            if(strcmp(argv[2],"armedit")==0){
                tool_armedit(argv[3]);
                return FALSE;
            }
            cout<<"unknow tool\n";
            return FALSE;
        }
    }
    return TRUE;
}

gchar *coi_getdatapath(gchar *s)
{
    char cu='/';
    #ifdef WIN32
        cu='\\';
    #endif
    gint8 y=0;
    gint i=strlen(s);
    while(y<2){
        if(s[i]==cu){y++;}
        i--;
    }
    gchar *r=new gchar[256];
    memset(r,0,256);
    for(int h=0;h<i+2;h++){
        r[h]=s[h];
    }
    strcat(r,"kb2");
    return r;
}
