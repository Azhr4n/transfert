/*
george
*/
#include <stdio.h>
#define FD FILE *fd=fopen("Grace_kid.c", "w+");
#define S char *s = "/*%cgeorge%c*/%c#include <stdio.h>%c#define FD FILE *fd=fopen(%cGrace_kid.c%c, %cw%c);%c#define S char *s = %c%s%c;%c#define FT int main(void){FD S fprintf(fd, s, 10, 10, 10, 10, 34, 34, 34, 34, 10, 34, s, 34, 10, 10, 10);return(0);}%cFT%c";
#define FT int main(void){FD S fprintf(fd, s, 10, 10, 10, 10, 34, 34, 34, 34, 10, 34, s, 34, 10, 10, 10);return(0);}
FT
