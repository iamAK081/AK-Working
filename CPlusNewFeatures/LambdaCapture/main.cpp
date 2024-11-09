#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv)
{
    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {4,3,2};
    
auto pushintovec = [v1,&v2](int m)
                    {
                        for(auto &vv : v1)
                        {
                            cout<<vv;
                        }
                        v2.push_back(m);
                    };
                    
    pushintovec(20);
    cout<<endl;
    
    for(auto &vv : v2)
    {
        cout<<vv;
    }

	printf("hello world\n");
	return 0;
}
