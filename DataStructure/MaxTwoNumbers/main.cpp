#include <stdio.h>
#include<iostream>

int main(int argc, char **argv)
{
   int array[10] = {2,100,3,5,6,8,9,4,7,0};
   int n = 10;
   int max = array[0];
  int max_index = 0;
  
   for(int i = 0; i < n-1; i++)
   {
      if(max < array[i+1]) 
      {
         max = array[i+1];
         max_index = i+1;;
      //  std::cout<<array[max_index];
      }
   }

   //std::cout<<array[max_index];
   int second = array[0];
   int index = 0;
   
   for(int i = 0; i < n; i++)
   {        
         if(second < array[i+1]) 
         { 
             std::cout<<std::endl;
             std::cout<<array[i+1]<<"    "<<array[max_index];
             if(array[i+1] != array[max_index])
             {
               second = array[i+1];
                index = i+1;             
             }
          }      
    }

   std::cout<<"First Bigest NO:"<<array[max_index]<<"   Second Bigest No:"<<array[index];
   
	printf("hello world\n");
	return 0;
}
