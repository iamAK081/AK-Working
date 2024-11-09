#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void sort1s(vector<int> array, int n)
{
    
    for(int i = 0; i < n; i++)
    {
        if(array[i] > array[i+1])
        {
            array[i] ^= array[i+1];
            array[i+1] ^= array[i];
            array[i] ^= array[i+1];
            i = 0;
            int a = array[i];
            int b = array[i+1];
        }
    }
    
     for(int j = 0; j < n; j++)
    {
        std::cout<<array[j];
    }
}


int main(int argc, char **argv)
{
    vector<int> array {0,2,1,2,0}; int n = 5;
    sort1s(array,n);
    
    for(int i = 0; i < n; i++)
    {
        std::cout<<array[i];
    }
	printf("hello world\n");
	return 0;
}
