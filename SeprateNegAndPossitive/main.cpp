#include <stdio.h>
#include<iostream>

int main(int argc, char **argv)
{
    int array[] = {1,2,3,-1,-2,4,-6};
    int j = sizeof(array) / sizeof(int) - 1;
    int i = 0;
    while(i <j)
    {
      while(array[i]<0) i++;
      while(array[j]>=0) j--;
    
      if(i < j)
      {
         array[i] ^= array[j];
         array[j] ^= array[i];
         array[i] ^= array[j];
      }
    }
    
    for(int l = 0; l < sizeof(array) / sizeof(int); l++)
    {
        std::cout<<array[l];
    }
	printf("hello world\n");
	return 0;
}
