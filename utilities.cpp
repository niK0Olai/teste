
#include "utilities.h"
#include "std_lib_facilities.h"


double randomWithLimits(int low, int high) {
    random_device rd;
    default_random_engine generator(rd());  
    uniform_real_distribution<double> distribution(low, high);

    double number = distribution(generator);

    return number;
}
