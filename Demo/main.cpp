#include <stdio.h>
// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


struct Demo
{
    Demo(char buffer[])
    {
        for (int i = 0; i < 4; i++)
            header[i] = buffer[i];      
        
        
        for (int i = 4; i < 8; i++)
        {
            lenOfData += atoi(buffer[i]);
        }
              
        int len = strlen(buffer);
        for (int i = 8; i < len; i++)
        {
            data += buffer[i];
        }        

    }
    char header[4];
    int lenOfData;
    string data;

    void operator<<(Demo &obj)
    {
        cout << obj.header << endl << obj.lenOfData << endl << obj.data;
    }

    void Display()
    {
        cout << header << endl << lenOfData << endl << data;
    }
};

//
//struct
//
////write a class - function
//template<class T>
//class Demo
//{
//private:
//    T a;
//    bool flag;
//public:
//    void Display()
//    {       
//        cout << a << endl;        
//    }
//};

int main()
{
   char buffer[] = "12340001a";
   // Demo *demo_ptr = (Demo*)buffer;
   // demo_ptr->header = "1234";
   // demo_ptr-

    Demo demo_ptr(buffer);
    demo_ptr.Display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
