#include <stdio.h>
#include <iostream>
using namespace std;

void RemoveDup(int array[],int &n)
{
    int temp[10];
    for(int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }
    
    for(int j = 0;  j < n; j++)
    {
        temp[array[j]] = array[j];
    }
        
     
    int l = 0;
   for(int k = 0; k <n; k++) 
   {
       if(temp[k]!=0)
       {
           array[l++] = temp[k];
       }
   }
    n = l;
   // array = temp;
}
int main(int argc, char **argv)
{
    int array[10] = {3,4,4,5,4,5,6,5,7,8};
    int n = 10;
    RemoveDup(array,n);
    for(int i = 0; i < n; i++)
    {
        std::cout<<array[i];
    }
	printf("hello world\n");
	return 0;
}
