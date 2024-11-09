#include <stdio.h>
#include<string.h>
#include<iostream>
#include<unordered_set>
int subStringCount(char*str)
{
    int l = strlen(str);
    int i =0;
    int j =l;
    int result = 0;
    
    int cst[26];
    for(int k= 0; k < 26; k++)
    {
        cst[k] = 0;
    }
    
    while(i < l)
    {
        if(j < l && cst[str[j] - 'a'] == 0)
        {
            cst[str[j] - 'a']++;
            result += (j - i + 1);      
            j++;      
        }
        else
        {
            cst[str[i] - 'a']--;
            i++;
        }
       
    }
    std::cout<<result;
    
    
}

int countSubStr(std::string str)
{
    int l = str.length();
     
    std::string s = str;
   std::unordered_set<std::string> myset;
    
    for(int i = 0 ; i < l; i ++)
    {
        for(int j = i + 1; j < l -1; j++)
        {
            myset.insert(s.substr(i, j));
        }
    }
}
int main(int argc, char **argv)
{
    std::string st = "gffg";
   countSubStr(st);
	printf("hello world\n");
	return 0;
}
