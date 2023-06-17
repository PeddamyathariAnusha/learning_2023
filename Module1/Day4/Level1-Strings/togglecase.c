#include <stdio.h>
#include <string.h>
 
void stringtogglecase(char *s)
{
	int i;
    for(i=0;s[i];i++)  
    {
        if(s[i]>=65 && s[i]<=90)
         s[i]+=32;
        else if(s[i]>=97 && s[i]<=122)
         s[i]-=32;
 	}	
}
int main()
{

    char s[1000];  
    printf("Enter the string: ");
    gets(s);
    stringtogglecase(s);
    printf("string in togglecase ='%s'\n",s);
    
}