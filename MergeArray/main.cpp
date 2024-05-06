#include <stdio.h>
#include<iostream>
using namespace std;

int main(int argc, char **argv)
{
    int a[5] = {1,2,3,4,5};
    int b[3] = {3,6,7};
    int c[8];
    for(int l = 0; l < 8; l++)
        c[l] = 0;
    
    int i = 0;
    int j =0;
    int k = 0;
    while(i<5 && j<3 )
    {
        if(a[i] < b[j])
        {
            c[k++] = a[i];
            i++;
            
        }
        else if(b[j] < a[i])
        {
            c[k++] = b[j];
            j++;           
        }
        else if(a[i] == b[j])
        {
            c[k++] = a[i];
            i++;
            j++;
            
        }
    }
        
        for(;i<5;i++)
        {
            c[k++] = a[i];
        }
        
         for(;j<3;j++)
        {
            c[k++] = b[j];
        }
        
        for(int l = 0; l < k; l++)
            std::cout<<c[l];
        
        
   
	printf("hello world\n");
	return 0;
}
