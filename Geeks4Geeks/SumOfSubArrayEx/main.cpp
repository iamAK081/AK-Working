#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> SubOfSubArray(vector<int> array, int n,int s)
{
    int i = 0, j = 0;
    int sum = 0;
    sum += array[i];
    
    while(i < n)
    {
        if(sum == s)
        {
            return {j+1,i+1};
        }
        if(sum < s)
        {
            i++;
            sum += array[i];
        }
        else
        {
            if(sum > s && i == j)
            {
                i++;
                j++;
                sum = array[j];
            }
            else if(sum >s)
            {
                sum -= array[j];
                j++;
            }
        }
    }
    
    return {-1};
}

int main(int argc, char **argv)
{
    vector<int> array {1,2,7,8,9};
    int n = 5;
    
    vector<int> out = SubOfSubArray(array,n,9);
    for(int i = 0; i < out.size(); i++)
    {
        cout<<out[i] <<endl;
    }
    
	printf("hello world\n");
	return 0;
}
