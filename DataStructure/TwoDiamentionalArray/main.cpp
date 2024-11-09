#include <stdio.h>

void sort(int *array,int n)
{
   int sorted = 1;
  for(int i = 0; i < n; i++)
  {
      sorted =0;
      for(int j = 0; j < n -1; j++)
      {
          if(array[i] > array[j +1])
          {
              array[j] ^= array[j+1];
              array[i+1] ^= array[j];
              array[i] ^= array[j+1];
              sorted =1;
          }
      }
  }
}

int main(int argc, char **argv)
{
    int arrary[] = {1,2,3,1,2,3};
    sort(arrary,6);
    int *a[3];
    for(int i = 0 ; i< 3; i ++)
    {
        a[i] = new int [4];
    }
    
       
    for(auto i = 0 ; i < 3; i++)
    {
        for(auto j = 0; j <4; j++)
        {
            printf("%d\n", a[i][j]);
        }
    }
	printf("hello world\n");
	return 0;
}
