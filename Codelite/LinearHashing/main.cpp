#include <stdio.h>

//Linear formulat h(x) = (h(x) + f(i)) % 10 where i is index - h(x) = x%10

int Hash(int x)
{
    return x%10;
}

int linearPro(int H[],int x)
{
    int index = Hash(x);
    int i = 0;
    while(H[(index + i) % 10] != 0)
        i++;
    return (index + i) % 10;
}

int insert(int A[],int k)
{
    int index = Hash(k);
    if(A[index] != 0)
        index = linearPro(A,k);
    A[index] = k;
    return 0;
}

int search(int H[],int key)
{
    int index = Hash(key);
    int i = 0;
    while(H[(index+i) % 10] != key)
        i++;
        
        return (index + i) % 10;
}
int main(int argc, char **argv)
{
    int A[5];
    for(int i = 0; i < 5; i++)
        A[i] = 0;
    insert(A,10);
    insert(A,20);
    insert(A,30);
    insert(A,4);
    
    int i = search(A,30);
    
	printf("hello world\n");
	return 0;
}
