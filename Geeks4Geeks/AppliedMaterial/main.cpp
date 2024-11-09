#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#include <iomanip>
using namespace std;

const int MAX_TEMP = 90;
const int MIN_TEMP = 30;
const int EVERY_MIN = 2;
const int EVERY_HRS = 6;
const int NO_OF_BUILD = 4;

struct TempratureRecord
{
    time_t time_stamp;
    vector<float> temp;
};

class TempratureMonitor
{
private:
    vector<TempratureRecord> m_record;
public:
     void SartMonitor()
     {
        TempratureRecord record;
        record.time_stamp = 0;
        time (&record.time_stamp);
         record.temp.resize(NO_OF_BUILD);
         
         for(int i = 0; i < NO_OF_BUILD; i++)
         {
             record.temp[i] = GenerateTemp(MIN_TEMP,MAX_TEMP);
         }
         
         m_record.push_back(record);
         cout<<"Monitor Started recording the Temp" <<endl;
        printf ("The current local time is: %s", ctime (&record.time_stamp));
        for (auto &rec : record.temp)
        {
            cout << fixed << setprecision(2) << rec;
        }   
      }
     
     float GenerateTemp(float min,float max)
     {
         return min + rand()/(RAND_MAX / (max - min));
     }
     
     void ConsolidatedTemp()
     {
        time_t currentTime = time(nullptr);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &currentTime);  // Use ctime_s
        /*time (&rawtime);
         printf ("The current local time is: %s", ctime (&rawtime));
         cout<<endl; */
         
         cout<<"Time A   B   C   D"<<endl;
         
         for(auto &rec : m_record)
         {
            if (difftime(currentTime, rec.time_stamp) <= 240)
            {
             printf ("%s", ctime (&rec.time_stamp));
             cout<<"/t";
             cout << fixed << setprecision(2);
             cout<<rec.temp[0]<<"\t";
             cout<<rec.temp[1]<<"\t";
             cout<<rec.temp[2]<<"\t";
             cout<<rec.temp[3];   
            }
                    
         }
         cout<<endl;
     }

};


int main(int argc, char **argv)
{
    unique_ptr<TempratureMonitor> temp_mon(new TempratureMonitor());
    
    std::thread start([&]()
    {
        while(true)
        {
            temp_mon->SartMonitor();
             std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        
    });
    
    std::thread ConsolidatedTemp([&]()
    {
        while(true)
        {
            temp_mon->ConsolidatedTemp();
             std::this_thread::sleep_for(std::chrono::minutes(2));
        }
        
    });
    
    start.join();
    ConsolidatedTemp.join();
    
	printf("hello world\n");
	return 0;
}
