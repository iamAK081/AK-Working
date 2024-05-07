#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int findTheLargest(vector<int> array,int n)
{
    int max = array[0];
    for(int i = 0; i < n; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    
    return max;
}
int firstRepat(vector<int> array, int n)
{
    vector<int>temp; int out;
    for(int i = 0; i < n; i++)
    {
        temp.push_back(0);
    }
    
    for(int i = 0; i < n; i++)
    {
        temp[array[i]]++;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(temp[array[i]] > 1)
        {
            out = array[i];
            break;
        }
       
    }
    return out;
}
int main(int argc, char **argv)
{
    
    vector<int> array {10, 5, 3, 4, 3, 5, 6};
    
    cout<<firstRepat(array,8);
	printf("hello world\n");
	return 0;
}
