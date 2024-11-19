#include<unistd.h>
#include<errno.h>
#include<string.h>

size_t customlen(const char *k){
    size_t lengthh=0;
    while(*k!='\0' && *k!='\n' && *(k++)!=-1) lengthh++;
    return lengthh;
}
size_t lencustomforerror(char *strr){
    size_t k=1;
    while((*(++strr)<'A' || *(strr)>'Z') && *(strr)!='\n' && *(strr)!=-1 && *(strr)!='\0') k++;
    return k;
}

void getlatesterror(const char *customcomment){
    int commentlen = customlen(customcomment);
    write(2,customcomment,commentlen);
    write(2,": ",2);
    char *perr=strerror(errno);
    write(2,perr,lencustomforerror(perr));
}

int main() {
    char *k;
    if (read(0,k,100) !=-1) write(1,"yes",3);
    else{
        
        getlatesterror("This is the error");
        write(1,"\n",1);
    }
}

