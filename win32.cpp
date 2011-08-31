#include <gtk/gtk.h>

void win32_slash(gchar *s)
{
    gint i=0;
    while(s[i]!=0){
        if(s[i]=='/'){
            s[i]='\\';
        }
        i++;
    }
}
