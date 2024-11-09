#include <stdio.h>

int main(int argc, char **argv)
{
    int *p = new int[5];
    for(auto i = 0; i < 5; i++)
        p[i] = i;
    
    int *q = new int[10];
    for(auto i = 0; i < 5; i++)
        q[i] = p[i];
        
        delete [] p; 
        
        p = q;
        q = nullptr;
        
        for(auto i = 0; i < 5; i++)
            printf("%d", p[i]);
        
        
	printf("hello world\n");
	return 0;
}
