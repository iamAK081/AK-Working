#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int findMissingElementInArray(std::vector<int> array,int n)
{
    int sum = 0;
   
    int total_sum = n * (n + 1) /2;
    for(int i = 0; i < n; i++)
        total_sum -= array[i];
    
    
  //  int missing = total_sum - sum;
    return total_sum;
}

int main(int argc, char **argv)
{
    
    vector<int> array {1, 2, 4, 6, 3, 7, 8};
    std::cout<<findMissingElementInArray(array,8);
	printf("hello world\n");
	return 0;
}
