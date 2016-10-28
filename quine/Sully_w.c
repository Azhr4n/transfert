#include <stdio.h>
#include <stdlib.h>
int main(void){
int i=5;
if(i > 0){
char *s="#include <stdio.h>%c#include <stdlib.h>%cint main(void){%cint i=%d;%cif(i > 0){%cchar *s=%c%s%c;%cchar buf[256];%csprintf(buf,%cSully_%%d.c%c,i);%cFILE *fd=fopen(buf,%cw+%c);%cfprintf(fd,s,10,10,10,i-1,10,10,34,s,34,10,10,34,34,10,34,34,10,10,10,34,34,10,10,34,34,10,10,10,10,10);%cfclose(fd);%csprintf(buf,%cgcc -Wall -Werror -Wextra Sully_%%d.c -o Sully_%%d%c, i, i);%csystem(buf);%csprintf(buf,%c./Sully_%%d%c, i);%csystem(buf);%c}%creturn(0);%c}%c";
char buf[256];
sprintf(buf,"Sully_%d.c",i);
FILE *fd=fopen(buf,"w+");
fprintf(fd,s,10,10,10,i-1,10,10,34,s,34,10,10,34,34,10,34,34,10,10,10,34,34,10,10,34,34,10,10,10,10,10);
fclose(fd);
sprintf(buf,"gcc -Wall -Werror -Wextra Sully_%d.c -o Sully_%d", i, i);
system(buf);
sprintf(buf,"./Sully_%d", i);
system(buf);
}
return(0);
}
