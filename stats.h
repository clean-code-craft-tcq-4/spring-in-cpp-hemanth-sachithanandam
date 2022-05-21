#include <vector>

struct Stats
{
    /* data */
    double average;
    double max;
    double min;
};

class IAlerter{
public:

};

class EmailAlert : public IAlerter{
public:
    bool emailSent;
    //constructor
    EmailAlert(){
    emailSent = false;
    }
};

class LEDAlert : public IAlerter{
public:
    bool ledGlows;
    //constructor
    LEDAlert(){
    ledGlows = false;
    }
};

class StatsAlerter {
public:
    double mT;
    std::vector<IAlerter*> alert;
    StatsAlerter(float maxThreshold,std::vector<IAlerter*> alerters)
    {
        mT = maxThreshold;
        alert = alerters;
    }
    void checkAndAlert(std::initializer_list<double> f_array);
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<double>& f_numbers);
}
