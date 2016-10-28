#include <stdio.h>
/*
bob
*/
int f(void){return(0);}
int main(void){char*s="#include <stdio.h>%c/*%cbob%c*/%cint f(void){return(0);}%cint main(void){char*s=%c%s%c;printf(s,10,10,10,10,34,s,34,10,10,10,10);f();return(0);}%c/*%cfrancois%c*/%c";printf(s,10,10,10,10,34,s,34,10,10,10,10);f();return(0);}
/*
francois
*/

