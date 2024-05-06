#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void strswap(char*a, char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b; 
}

int length(char* c)
{
    int l = 0;
    while(*c != '\0')
    {
        l++;
        c++;
    }
}

void reverseString(char *str,int l)
{   
    cout<<l;
    int i=0,j = l-1;
    while(i < j)
    {
        strswap(&str[i],&str[j]);
        i++;
        j--;
    }
    cout<<str;
}
/*
int main(int argc, char **argv)
{
    int a = 10; int b = 20;
    swap(a,b);
    cout<<"A :" <<a<< "B:" <<b;
    char aa = 'a', bb = 'b';
    strswap(&aa,&bb);
   // cout<<"Aa :" <<aa<< "Bb:" <<bb;
    
    char str[] = "Hello";
    int l = strlen(str);
    reverseString(str,l);
	//printf("hello world\n");
	return 0;
}
*/

void sort(int *a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1])
        {
            swap(&a[i],&a[i+1]);
        }
    }
}

int main()
{
    int metRoom[4][2] = {{1,3},{5,7},{4,6},{9,10}};
    
    int start[4];
    int end[4];
    
    int i = 0;
    int j = 0;
    for(auto &row : metRoom)
    {
        start[i++] = *row;
        int l = 0;
        for(auto &col : row)
        {
            if(l == 0)
            {
                l++;
                continue;
            }
            end[j++] = col;            
        }
    }
    
    sort(start,4);
    sort(end,4);
    
    int k = 0;
    int noOfRoom = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if(start[i] < end[k])
        {
            noOfRoom++;
        }
        else
        {
            k++;
        }
    }
    
    cout<<noOfRoom;
    
    return 0;
}