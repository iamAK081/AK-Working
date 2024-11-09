#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sub_array_index1(vector<int> array,int n,int s)
{
    int i = 0; int j = 0;
    int sum = 0;
     sum += array[i];    
    while(i < n)
    {         
        if(sum == s)
        {
            return {j+1,i+1};
        }
        else if(sum < s)
        {
            i++;
            sum += array[i];
        }
        else
        {
            if(sum > s && i == j)                  
            {
                j++;  
                i++;      
                sum = array[i];
            }
            else if(sum > s)
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
    vector<int> arr{5,3,4}; int n = 3, s = 7;
    vector <int> out1 = sub_array_index1(arr,n,s);
    for(int i = 0; i < out1.size(); i++)
    {
        std::cout<<out1[i];
    }
    
	printf("hello world\n");
	return 0;
}
