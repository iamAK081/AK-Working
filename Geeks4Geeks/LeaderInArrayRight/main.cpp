#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int> leaderInArray(vector<int> arr,int n)
{
    vector<int> ans;
    int max = arr[n-1];
   
    for(int i = n-1; i >=0; i--)
    {
        if(max <= arr[i])
        {
            max = arr[i];
            ans.push_back(max);
        }
        
    }
    
    return ans;
}

int main(int argc, char **argv)
{
    std::vector<int> a = {16,17,4,3,5,2};
    int n = 6;
    std::vector<int> out = leaderInArray(a,n);
    for(int i =0; i < out.size(); i++)
    {
        cout<<out[i];
    }
	printf("hello world\n");
	return 0;
}
