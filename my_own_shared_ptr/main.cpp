#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T>
class my_own_shared_ptr
{
private:
    int* m_count;
    T* m_ptr;
public:
    int get_count()
    {
        return (m_count == nullptr) ? 0 : *m_count;
    }
    
     my_own_shared_ptr(T* ptr = nullptr) : m_ptr(ptr)
    {
        m_count =new int(1);
    }
    
    my_own_shared_ptr(const my_own_shared_ptr& obj) : m_ptr(obj.m_ptr)
    {
        m_count = obj.m_count;
        if(m_count != nullptr)
            *(m_count)++;
    }
    
    void operator=(const my_own_shared_ptr& obj)
    {
        if(this->m_ptr != obj.m_ptr)
        {
            release();
        }
          m_ptr = obj.m_ptr;
          if(m_count != nullptr)
             *(m_count)++;           
        
    }
    
    release()
    {
        if(m_count != nullptr)
        {
            *(m_count)--;        
        
            if(*m_count == 0)
            {
                delete m_ptr;
                m_ptr = nullptr;
                
                delete m_count;
                m_count = nullptr;
            }
        }
        
    }
    ~my_own_shared_ptr()
    {
        release();
    }
    
    my_own_shared_ptr(my_own_shared_ptr &&obj) = delete;
    my_own_shared_ptr& operator=(my_own_shared_ptr &&obj) = delete;
};
int main(int argc, char **argv)
{
    my_own_shared_ptr<int> ptr1(new int(42));
    my_own_shared_ptr<int> ptr2 = ptr1;

    std::cout << "ptr1 use count: " << ptr1.get_count() << std::endl;
    std::cout << "ptr2 use count: " << ptr2.get_count() << std::endl;
	printf("hello world\n");
	return 0;
}
