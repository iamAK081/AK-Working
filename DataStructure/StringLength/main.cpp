#include <stdio.h>

int cstrlen(char* s)
{
    int l = 0;
    while(*s != '\0')
    {
        l++;
        s++;
    }
    return l;
}

int cstrcmp(char *s,char *s1)
{
    while(*s != '\0' && *s1 != '0')
    {
        if(*s != *s1)
            return -1;
        s++;
        s1++;
    }
    
    return 0;
}

void ToLower(char*s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 65 && s[i] <=90)
        {
            s[i] = s[i] + 32;
        }
        else if(s[i] >=97 && s[i] <=122)
        {
            s[i] = s[i] -32;
        }
    }
}

void ToUpper(char*s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        s[i] = s[i] - 32;
    }
}


int main(int argc, char **argv)
{
    char str[] = {"ARUL5murugan"};
    
    printf("Str length %d", cstrlen(str));
    char str1[] = {"Kesavan"};
    
    
    if(cstrcmp(str,str1)== 0)
    {
        printf("Both string are matched");
    }
    else
    {
        printf("Both string are not matched");
    }
    
    
    ToLower(str);
    printf("\nTo Uppder %s",str );
    
    ToUpper(str1);
	printf("\nTo Uppder %s",str1 );
	return 0;
}
