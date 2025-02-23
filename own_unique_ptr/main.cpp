#include <stdio.h>
#include <iostream>
using namespace std;
template<typename T>
class my_unique_ptr
{
private:
    T* m_ptr;
public:
    my_unique_ptr(T* ptr = nullptr) : m_ptr(ptr)
    {
        
    }
    
    my_unique_ptr(const my_unique_ptr &obj) = delete;
    my_unique_ptr& operator=(const my_unique_ptr &obj) = delete;
    
    my_unique_ptr(my_unique_ptr &&obj)
    {
        m_ptr == obj.m_ptr;
        obj.m_ptr = nullptr;
    }
    
    my_unique_ptr& operator=(my_unique_ptr &&obj)
    {
        if(&obj.m_ptr != this)
        {
            delete obj.m_ptr;
             m_ptr = obj.m_ptr;
            obj.m_ptr = nullptr;
        }
       
        
        return *this;
    }
    
    T& operator*()
    {
        return *m_ptr;
    }
    
    T* operator->()
    {
        return m_ptr;
    }
    
    ~my_unique_ptr()
    {
        if(m_ptr != nullptr)
        {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }
};

int main(int argc, char **argv)
{
    my_unique_ptr<int> obj (new int(43));
    std::cout<<"value:"<<*obj<<std::endl;
	printf("hello world\n");
	return 0;
}
