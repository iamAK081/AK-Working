
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void swap(char* a, char *b)
{
   *a ^= *b;
   *b ^= *a;
   *a ^= *b;
}


char* InputStr(char str[])
{
    int len = strlen(str);
    int i = 0;
    
    char * temp = new char[len];
    memset(temp, 0, len);
    int j = 0;
    for(int i = len; i >=0; i--)
    {
        temp[j++] = str[i];
    }
    
    temp[j+1] = '\0';
    
    int m = 0;
    char * str1 = new char[len];
    while(m <= len)
    {
        int j = m;
        int count = 0;
        char st[20];
        while(temp[j] != ' ')
        {
            st[count++] = temp [j];
            j++;
            if(temp[j+1] == '\0')
                break;
        }
        
        for(int k = count-1; k >= 0 ; k--)
        {
            str1[m++] = st[k];
        }
        
        str1[m++] = ' ';
    }  
    
    for(int i = 0; i <= len; i++)
        cout<<str1[i];
    return str1;
}

/*
    //  cout<<s[i];
  
//aidni ym evol i
int l = str.length();
int j = 0;
std::string s1;
while(j < l)
{  
    int i = 0;
   
   
   
   
   cout<<s1;

  int m = i-1;
  int n = 0;
  while( n < m)
  {
     swap(s1[m],s1[n]);
     n++;
     m--;
  }
  s1[i] = ' ';
  j = i;
  
  cout<<s1;
  
  
}
    return s1;
}
 * 
 */
int main(int argc, char **argv)
{
    char str[] = "my country is india";
    InputStr(str);
	//printf("hello world\n");
	return 0;
}
