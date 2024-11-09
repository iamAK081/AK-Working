#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int findExtra(int n, int arr1[], int arr2[])
 {
        // add code here.
        int temp[n];
        for(int i =0; i < n; i++)
        temp[i] = arr1[i];
        
        for(int i = 0; i < n-1;i++)
        {
            if(arr2[i] == temp[i])
              temp [i] = 0;
        }
        
         for(int i = 0; i < n;i++)
            if(temp[i] != 0)
            return temp[i];
}
    
    
int main(int argc, char **argv)
{
    int n = 7, arr1[] = {2,4,6,8,9,10,12}, arr2[] = {2,4,6,8,10,12};
    cout<<findExtra(n,arr1,arr2);
    
	printf("hello world\n");
	return 0;
}
