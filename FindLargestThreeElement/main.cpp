#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int first,second,thrid;
    first = second = thrid = INT_MIN;
    
    int array[]{10,20,1,30,40,60};
    for(int i = 0; i < 6; i++)
    {
        if(array[i] > first)
        {
            thrid = second;
            second = first;
            first = array[i];
        }
        else if(array[i] > second && array[i] != first)
        {
            thrid = second;
            second = array[i];
        }
        else if(array[i] > thrid && array[i] != first && array[i] != second)
        {
            thrid = array[i];
        }
    }
	std::cout<<first<<"\t"<<second<<"\t"<<thrid;
	return 0;
}
