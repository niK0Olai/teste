#include "canonball.h"
#include "utilities.h"
#include "cannonball_viz.h"
#include "std_lib_facilities.h"
#include <iostream>
#include <cmath>


double acclY() {
    return -9.81;    
}


double velY(double initVelocityY, double time) {
    double FartY = initVelocityY + acclY() * time;
    return FartY;
}

double posX(double initPositionX, double initVelocityX, double time){
    double pos = initPositionX + initVelocityX *time;
    return pos;
}

double posY(double initPositionY, double initVelocityY, double time) {
    double pos = initPositionY + initVelocityY *time + (acclY()* std::pow(time,2))/ 2;
    return pos;
}


void printTime(double time) {
    int hours = static_cast<int>(time / 3600);
    int minutes = static_cast<int>(std::fmod(time / 60, 60));
    int seconds = static_cast<int>(std::fmod(time, 60));

    std::cout << "Time: " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds" << std::endl;
}

double flightTime(double initVelocityY) {
    double time = -2*initVelocityY/acclY();
    return time;
}



double getUserInputTheta() {
    double theta;
    cout << "Angi utgangsvinkel (grader):";
    cin >> theta;
    return theta;
}

double getUserInputInitVelocity() {
    double vel;
    cout << "Angi startfart:";
    cin >> vel;
    return vel;
}

double degToRad(double deg) {
    double rad;
    rad = deg*M_PI/180;
    return rad;
}


double getVelocityX(double theta, double initVelocity){
    double velX;
    velX = initVelocity*cos(theta);
    return velX;
}

double getVelocityY(double theta, double initVelocity) {
    double velY;
    velY = initVelocity*sin(theta);
    return velY;
}

vector<double> getVelocityVector(double theta, double initVelocity) {
    double velX = getVelocityX(theta, initVelocity);
    double velY = getVelocityY(theta, initVelocity);
    vector<double> v = {velX, velY};
    return v;
}

double getDistanceTraveled(double velocityX, double velocityY) {
    double timeOfFlight = flightTime(velocityY);
    double distanceTraveled = posX(0,velocityX, timeOfFlight);

    return distanceTraveled;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    double distanceDifference = distanceTraveled - distanceToTarget;
    return distanceDifference;
}

void playTargetPractice() {
    int trys = 10;
    double target = randomWithLimits(100, 1000);
    double deg;
    double initVelocity;
    double velocityX = 0;
    double velocityY = 0;

    cout << "Blinken er " << target << " unna" << endl;
    cout << "Du har " << 10 << " fors0k igjen" << endl;
    for (int i = 1;i < trys;i++) {
        
        
        cout << "Velg en vinkel: ";
        cin >> deg;
        cout << "Velg en utgangsfart: ";
        cin >> initVelocity;

        double theta = degToRad(deg);

        //vector<double> v = getVelocityVector(double theta, double initVelocity);
        double velocityX = getVelocityX(theta, initVelocity);
        double velocityY = getVelocityY(theta, initVelocity);

        if (abs(targetPractice(target,velocityX,velocityY)) <= 5){
            cout << "Du traff maalet og vant" << endl;
            exit(0);
        }
        cannonBallViz(target, 1000, velocityX, velocityY, 100);
        cout << "Du skjot " << getDistanceTraveled(velocityX,velocityY) << " meter. " << abs(targetPractice(target,velocityX,velocityY)) << " meter unna maalet" << endl;
        printTime(flightTime(velocityY));
        cout << "Du har " << 10-i << " fors0k igjen" << endl;
    }

    cout << "Du tapte :(" << endl;
}
