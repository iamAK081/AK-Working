#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class my_unqiue_ptr
{
private:
    T* my_unique_ptr;
public:
    my_unqiue_ptr(T* ptr = nullptr) : my_unique_ptr(ptr)
    {
        
    }
    
    my_unqiue_ptr(const my_unqiue_ptr& obj) = delete;
    my_unqiue_ptr& operator=(const my_unqiue_ptr& obj) = delete;
    
    my_unqiue_ptr(my_unqiue_ptr &&obj)
    {
        my_unique_ptr = obj.my_unique_ptr;
        obj.my_unique_ptr = nullptr;
    }
    
    my_unqiue_ptr& operator=(my_unqiue_ptr &&obj)
    {
        if(this != &obj.my_unique_ptr)
        {
             delete my_unique_ptr;
             my_unique_ptr = obj.my_unique_ptr;
            obj.my_unique_ptr = nullptr;        
        }
        return *this;
    }
};

int main(int argc, char **argv)
{
    my_unqiue_ptr<int> ptr (new int(10));
	printf("hello world\n");
	return 0;
}
