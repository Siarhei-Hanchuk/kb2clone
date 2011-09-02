#include "header.h"

char *strlwr(char *s)
{
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if((s[i]>64)&&(s[i]<91)){
            s[i]=s[i]+32;
        }
    }
    return s;
}

char *strupr(char *s)
{
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if((s[i]>96)&&(s[i]<123)){
            s[i]=s[i]-32;
        }
    }
    return s;
}

char *strcpy_m(char *Dst,int begin,int end,const char *Src,long begdst=0)
{
	int i=0;
	for(i=begdst;i<=end-begin+begdst;i++){
		Dst[i]=Src[i+begin];
	}
	Dst[i]=0;
	return Dst;
}

int pos(const char *substr,const char *str)
{
    if(str==NULL){return -1;}
    //!выдаёт номер позицию где первый раз встречается substr
	if(strlen(substr)==1){
		int l=strlen(str);
		for(int j=0;j<l;j++){
			if(str[j]==substr[0]){return j;}
		}
		return -1;
	}
	else{
	int i=0;
	int sizeSub=strlen(substr);
	int sizeStr=strlen(str);
	if(sizeStr<sizeSub){return 0;}
	char *tmp=new char[sizeSub+1];
	memset(tmp,0,sizeSub+1);
	for(i=0;i<sizeStr-sizeSub+2;i++){
		strcpy_m(tmp,i,sizeSub+i-1,str);
		if(!strcoll(tmp,substr)){free(tmp);return i;}
	}
	free(tmp);
	}
	return -1;
}

char *itoa(const long int n)
{
    //!Переводит число в строку
    //!Для чисел со знаком, не блолее 64 разрядов
    long int t=n;
    //char *buf=new char[21];memset(buf,0,21);
    char *buf=(char *)malloc(sizeof(char)*21);memset(buf,0,21);
    if(n==0){
        buf[0]='0';buf[1]=0;
        return buf;
    }
    char *tmp=(char *)malloc(sizeof(char)*21);memset(buf,0,21);
    int i=0;
    while(t!=0){
        tmp[i]=abs(t%10)+48;
        t=t/10;
        i++;
    }
    i--;

    short j=0;
    if(n<0){buf[0]='-';j=1;}
    while(i>-1){
        buf[j]=tmp[i];
        i--;j++;
    }
    free(tmp);
    return buf;
}
