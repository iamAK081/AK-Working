#include <stdio.h>
#include<iostream>
using namespace std;

//count no of vowel in the string
void no_of_count_vowel(char* s)
{
    int v = 0;
    int c = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' 
        || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
            v++;        
        else if(s[i] >= 65 && s[i] <=90 || s[i] >= 97 && s[i] <=122)
        c++;
    }
   
    
   cout<<"\nNo of vowel in string: "<<v;
   cout<<"\nNo of Console in string: "<<c;
   
    return;
}

//no of words in the string
void no_of_words(char* s)
{
    int word = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ' && s[i-1] != ' ')
            word++;
    }
    
    cout<<"\n no of words :"<< word + 1;
}

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

void swap(char *s1, char* s2)
{
    *s1 ^= *s2;
    *s2 ^= *s1;
    *s1 ^= *s2;
}
void reverse_string(char* s,int n)
{
    int i = 0; int l = n;
    while(i < l)
    {
        swap(s[i],s[l]);
        i++;
        l--;
    }
}

void reverse_string_backwards(char* s,int n)
{
    int i = 0; int l = n;
    while(i < l)
    {
        swap(s[i],s[l]);
        i++;
        l--;
    }
    
    for(int i =0 ; s[i] != '0'; i++)
    {
        int e = 0;
        int b = i;
        while(s[b] != ' ')
        {
            e++;
            b++;
        }
        
             
        
        while(i < e)
        {
            swap(s[i],s[e]);
            i++;
            e--;
        } 
       s[i+1] = s[b+1];
     
        printf("\nReverse string %s ",s);
        
        i = b + 1;
    }
}

int main(int argc, char **argv)
{
	char str[] = "Arul Murugan kesavan";
    
    no_of_count_vowel(str);
    
    no_of_words(str);
    
    reverse_string_backwards(str,cstrlen(str)-1);
    printf("\nReverse string %s ",str);
	return 0;
}
