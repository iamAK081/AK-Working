#include <stdio.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(int i = 0; i < arr.length;i++)
        printf("%d",arr.A[i]);
}

int main(int argc, char **argv)
{
    Array arr;
    printf("Enter the size of an array:");
    scanf("%d",&arr.size);
	
    arr.A = new int[arr.size * sizeof(int)];
    arr.length = 0;
    
    printf("Enter the number of numbers");
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        arr.A[i] = i + 1;       
    }
    
    arr.length = n;
    
    Display(arr);
    
	return 0;
}
