#include "stats.h"
#include <algorithm>
#include <numeric>
namespace Statistics {
    Stats ComputeStatistics(const std::vector<double>& f_numbers) {
        //Implement statistics here
        Stats var_1;
        sort(f_numbers.begin(), f_numbers.end());

        var_1.max = *max_element(f_numbers.begin(), f_numbers.end());
        var_1.min = *min_element(f_numbers.begin(), f_numbers.end());
        var_1.average = std::accumulate(f_numbers.begin(), f_numbers.end(),0.0)/f_numbers.size();
        return var_1;
    }
}

void StatsAlerter::checkAndAlert(std::initializer_list<double> f_array)
{
    std::vector<IAlerter*> alerters;
    float maxThreshold;
    StatsAlerter l_stats_obj(maxThreshold,alerters);
    for(int i=0;i<sizeof(f_array);i++)
    {
        if(f_array[i]>=l_stats_obj.mT)
        {
            l_stats_obj.alert[0]->emailSent=true;
            l_stats_obj.alert[1]->ledGlows=true;
        }
    }
}
