#include <stdio.h>
#include<iostream>
using namespace std;

template<class T>
class my_shared_ptr
{
private:
    T* m_ptr;
    int m_count;
    
public:
   int get_count()
   {
       return (m_count == 0) ? 0: m_count;
   }
   
   my_shared_ptr(T* ptr = nullptr)
   {
       m_ptr = ptr;
       m_count = new int(1);
   }
   
    my_shared_ptr(const my_shared_ptr &obj)
   {
       m_ptr = obj.m_ptr;
       m_count = obj.m_count;
       if(m_count !=0)
           m_count++;
   }
   
   void operator= (const my_shared_ptr &obj)
   {
       if(obj.m_ptr != this)
           release();
           
       m_ptr = obj.m_ptr;
       m_count = obj.m_count;
       if(m_count != 0)
       {
           m_count++;
       }
           
      
   }
   
   T& operator*()
   {
       return *m_ptr;
   }
   
   T* operator->()
   {
       return m_ptr;
   }

  void release()
  {
      if(m_count != 0)
       m_count--;
       
      if(m_count == 0)
      {
          delete m_ptr;
          m_ptr = nullptr;
          m_count = 0;
          
      }
  }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
