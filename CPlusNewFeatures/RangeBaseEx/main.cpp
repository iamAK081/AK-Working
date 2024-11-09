#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Range based : C++11 indroduce new features for iterator over the container known as range based for loop 
//Syntax : 

int main(int argc, char **argv)
{
    //itreator to the whole array
    vector<int> v { 1,2,3,4,5};
    
    for(auto &a : v)
    {
        cout<<a;
    }
    
    cout<<endl<<"interator based initialzed brace list" <<endl;
    //interator based initialzed brace list
    for(auto &b : {1,2,3,4,5,6})
    {
        cout<<b;
    }
    
    cout<<endl<<"Iterator over Array\n";
    int array[] = {7,8,9,0};
    for(auto &aa : array)
    {
        cout<<aa;
    }
    
    cout<<"Printing the String Character\n";
    string str = "geekforgeek\n";
    for(auto &s : str)
    {
        cout<<s;
    }
    
    cout<<"\nPrint the element in map\n";
    map<int,int> ma ({{1,1},{2,2},{3,3}});
    for(auto &m : ma)
    {
        cout<<"First" <<m.first<<"Second" <<m.second <<endl;
    }
    
    cout<<"C++17 feature map\n";
    for(auto & [key,val] : ma)
    {
        cout<<"Key" <<key <<"value" <<val <<endl;
    }
	printf("hello world\n");
	return 0;
}
