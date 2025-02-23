#include <stdio.h>
#include <iostream>
using namespace std;
void sort(int array[],int n)
{
  
    for(int i = n; i > 0 ; i--)
    {        
        for(int j = 0; j < n-1; j++)
        {
            if(array[j] > array[j+1])
            {
                array[j] ^= array[j+1];
                array[j+1] ^= array[j];
                array[j] ^= array[j+1];
                
            }
        }
    }
        
}

int minPlatform(int arr[],int dep[],int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout<<"\nArrial :"<<arr[i];
    }
     std::cout<<"\n\n";
     for(int j = 0; j < n; j++)
    {
        std::cout<<"\nDep :"<<dep[j];
    }
    
    sort(arr,n);
    sort(dep,n);
    
    std::cout<<"\n\nAfter";
    for(int i = 0; i < n; i++)
    {
        std::cout<<"\nArrial :"<<arr[i];
    }
     std::cout<<"\n\n";
     for(int j = 0; j < n; j++)
    {
        std::cout<<"\nDep :"<<dep[j];
    }
    
    int platform = 1; int result = 1;
    int i = 1; int j = 0;
    
    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else if(arr[i] > dep[j])
        {
            platform--;
            j++;
        }
        
        if(platform > result)
            result = platform;
    }
    
    return result;
}

int main(int argc, char **argv)
{
    int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minPlatform(arr, dep, n);
	printf("hello world\n");
	return 0;
}
