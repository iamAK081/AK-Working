#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


 vector<int> twoRepeated(int n, int arr[]) 
 {
        // Your code here
        vector<int>ans;
         map<int,bool>map;
        
        for(int i=0; i < n+2; i++)
        {
            if(map[arr[i]])
            {
                ans.push_back(arr[i]);
            }
           map[arr[i]] = true;
        }
        return ans;
        
        
}
    
int main(int argc, char **argv)
{
    int n = 6, arr[] = {1, 2, 1, 3, 4, 3};
    
     vector<int> out = twoRepeated(n,arr);
     for(int i =0; i < out.size();i++)
     {
         cout<<out[i];
     }
	printf("hello world\n");
	return 0;
}
