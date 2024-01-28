

#include "std_lib_facilities.h"
#include "canonball.h"
#include "utilities.h"


void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main() {
    //testDeviation(posX(0.0,50.0,5.0), 250.0, 0.001, "posX(0.0,50.0,5.0)");
    playTargetPractice();
    

    
    
    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (compareOperand-toOperand<=maxError) {
        cout << name << " holder" << endl;
    } else {
        cout << name << " holder ikke" << endl;
    }
}  
