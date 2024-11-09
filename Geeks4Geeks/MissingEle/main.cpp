#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> arr = {1,2,3,5};
    
    int n = arr.size() + 1;
    int s = (n * (n + 1)) /2;
    int sum = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    
    int m = sum - s;
    
    
	printf("hello world\n");
	return 0;
}
