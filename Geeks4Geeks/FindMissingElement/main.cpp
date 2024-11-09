#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int missingNumber(int n, vector<int>& arr)
 {
     for(int i = 0; i < n; i++)
     {
         int s = arr[i] + 1;
         if(arr[i+1] != s)
             return s;
     }

        // Your code goes here     
       
          return -1;
}
    
int main(int argc, char **argv)
{
    vector<int> arr = {1,2,3,5};
    int n = 5;
    cout<<missingNumber(n,arr);
	printf("hello world\n");
	return 0;
}
