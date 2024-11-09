#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> v {1,2,3,4,5,6,7,8};
    //print element in the vector using lambda
    for_each(v.begin(),v.end(), [](int i)
    {
        cout<< i;
    }
    );
    
    cout<<endl;
    
    //return first lement of the vector which is grater than 4
    
    vector<int>::iterator p = find_if(v.begin(),v.end(),[](int i)
    {
        return i > 4;
    }
    );
    
     cout<<*p <<endl;
    
    //count numbers grater than 5 or equal to 5;
    int cout_5 = count_if(v.begin(),v.end(),[](int i)
    {
      return i> 5;
    }
    );
    
    cout<<cout_5;
    
    
	printf("hello world\n");
	return 0;
}
