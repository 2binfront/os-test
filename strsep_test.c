#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 
int main() 
{ 
char ptr[]={ "abcdefghijklmnopqrstuvwxyz "}; 
char *p,*str= "m"; 
p=ptr; 
printf( "%s\n",strsep(&p,str)); 
printf( "%s\n",p); 
str= "s"; 
printf( "%s\n",strsep(&p,str)); 
printf( "%s\n",p); 
str= "a"; 
printf( "%s\n",strsep(&p,str)); 
printf( "%s\n ",p); 
} 
