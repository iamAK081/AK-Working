#include <stdio.h>
#include<iostream>
using namespace std;

void FindDupUsingHash(int array[],int n)
{
    int largest = array[0];;
    for(int i =0; i< n-1; i ++)
    {
        if(largest < array[i+1])
            largest = array[i+1];
    }
    
    int m = largest +1;
    int array1[m];
    for(int i = 0; i < m; i++)
    {
        array1[i] = 0;
    }
    
    for(int j = 0; j < n;j++)
    {
        array1[array[j]]++;
    }
    
    for(int j=0; j < n; j++)
    {
        if(array1[j] > 1)
            cout<<"\n\nThe Duplicate elements is"<<j <<"   No of times"<<array1[j];;
    }
}
void FindDuplicateInUnsorted(int array[],int n)
{
    int count =0;
    for(int i = 0; i < n-1; i++)
    {
        count = 1;
        if(array[i] != -1)
        {
            for(int j = i+1; j < n; j++)
            {
                if(array[i] == array[j])
                {
                    count++;
                    array[j] = -1;
                }
            }
            
            if(count > 1)
              cout<<"\n\nThe Duplicate elements is"<<array[i] <<"   No of times"<<count;
        }
        
    }
    
    
}
int main(int argc, char **argv)
{
    int array[14]= {1,2,3,4,4,5,6,8,8,8,4,4,2,2};
   // std::cout<<LastDuplicate(array,10);
   // coutNoDuplicate(array,10);
    //FindDuplicateInUnsorted(array,14);
    FindDupUsingHash(array,14);
    
	//printf("hello world\n");
	return 0;
}
