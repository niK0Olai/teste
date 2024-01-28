#include "std_lib_facilities.h"


double acclY();
double velY(double initVelocityY, double time);
double posX(double initPositionX, double initVelocityX, double time);
double posY(double initPositionY, double initVelocityY, double time);
void printTime(double time);
double flightTime(double initVelocityY);

double getUserInputTheta();
double getUserInputInitVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double initVelocity);
double getVelocityY(double theta, double initVelocity);
vector<double> getVelocityVector(double theta, double initVelocity);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();
