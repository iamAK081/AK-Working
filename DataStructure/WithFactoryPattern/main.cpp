#include <stdio.h>
#include<iostream>
using namespace std;

enum vechileType {TWOWHEELER,THREEWHEELER,FOURWHEELER};


class Vechile
{
public:
    virtual ~Vechile() {};
    virtual void vechileInfo() = 0;
};

class TwoWheeler : public Vechile
{
public:
    virtual ~TwoWheeler() {};
    void vechileInfo() override { cout<<"Two Wheeler"; };    
};

class ThreeWheeler : public Vechile
{
public:
    virtual ~ThreeWheeler() {};
    void vechileInfo() override { cout<<"Three Wheeler"; };
    
};

class FourWheeler : public Vechile
{
public:
    virtual ~FourWheeler() {};
    void vechileInfo() override { cout<<"Four Wheeler"; };
};

class VechileFactory
{
public:
    virtual ~VechileFactory() {};
    Vechile* GetVechileInfo(vechileType type)
    {
        if(type == vechileType::TWOWHEELER)
            return new TwoWheeler();
        if(type == vechileType::THREEWHEELER)
            return new ThreeWheeler();
        if(type == vechileType::FOURWHEELER)
            return new FourWheeler();       
        
        return nullptr;
    }
private:
    Vechile *m_vechileInfo;
    
};

class Client
{
    VechileFactory *m_vFactory;
public:
    virtual ~Client() {
        cout<<"Client Destractor\n";
        delete m_vFactory;
        };
    Vechile* GetVechileInfoFromFactory(vechileType type)
    {
        m_vFactory = new VechileFactory();
        return m_vFactory->GetVechileInfo(type);
    }
};





int main(int argc, char **argv)
{
    Client client;
    Vechile *vechile = client.GetVechileInfoFromFactory(vechileType::FOURWHEELER);
    vechile->vechileInfo();
	printf("hello world\n");
	return 0;
}
