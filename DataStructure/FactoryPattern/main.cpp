#include <stdio.h>
#include<iostream>
using namespace std;

class Vechile
{
public:
    virtual ~Vechile() {};
    virtual void vechileInfo() = 0;
};

class FourWheeler : public Vechile
{
public:
    virtual ~FourWheeler() {};
    void vechileInfo() override { cout<<"Four Wheeler"; };
};

class ThreeWheeler : public Vechile
{
public:
    virtual ~ThreeWheeler() {};
    void vechileInfo() override { cout<<"Three Wheeler"; };
};

class TwoWheeler : public Vechile
{
public:
    virtual ~TwoWheeler() {};
    void vechileInfo() override { cout<<"Two Wheeler"; };
};


//Clinet code need to recompile if any vechile is add
//with Factory Pattern
class Client
{
public:
    virtual ~Client() {};
    Vechile* GetVechileInfo(int type)
    {
        if(type == 1)
            m_vechile = new FourWheeler();
        else if(type ==2)
            m_vechile = new TwoWheeler();
    }
private:
 Vechile * m_vechile;
};

int main(int argc, char **argv)
{
    Client cl;
    Vechile *vechile = cl.GetVechileInfo(1);
    vechile->vechileInfo();
	printf("hello world\n");
	return 0;
}
