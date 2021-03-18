#include "simpson_integration.h"
#include <iostream>
#include <chrono>

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::milliseconds;
using chrono::time_point;

int getMilisecondsBetweenTwoTimePoints(time_point<high_resolution_clock> t1, time_point<high_resolution_clock> t2);

int main()
{
    double a, b, c, x1, x2;
    int n, p;

    cout << "Please type value for variable A:" << endl;
    cin >> a;

    cout << "Please type value for variable B:" << endl;
    cin >> b;
    
    cout << "Please type value for variable C:" << endl;
    cin >> c;
    
    cout << "Please type value for x1:" << endl;
    cin >> x1;
    
    cout << "Please type value for x2:" << endl;
    cin >> x2;

    cout << "Please type no. of threads:" << endl;
    cin >> p;

    cout << "Please type no. of integration intervals:" << endl;
    cin >> n;


    SimpsonIntegration simpsonIntegrationParallel(a, b, c, x1, x2, n, p);
    
    time_point<high_resolution_clock> startTimeParallel = high_resolution_clock::now();
    simpsonIntegrationParallel.count();
    time_point<high_resolution_clock> endTimeParallel = high_resolution_clock::now();

    cout << "Tp = " << getMilisecondsBetweenTwoTimePoints(startTimeParallel, endTimeParallel) << "ms" << endl;
    cout << "Result parallel: " << simpsonIntegrationParallel.getResult() << endl;


    SimpsonIntegration simpsonIntegrationSingleThread(a, b, c, x1, x2, n, 1);
    
    time_point<high_resolution_clock> startTimeSingleThread = high_resolution_clock::now();
    simpsonIntegrationSingleThread.count();
    time_point<high_resolution_clock> endTimeSingleThread = high_resolution_clock::now();

    cout << "Ts = " << getMilisecondsBetweenTwoTimePoints(startTimeSingleThread, endTimeSingleThread) << "ms" << endl;
    cout << "Result single: " << simpsonIntegrationSingleThread.getResult() << endl;

    return 0;
}

int getMilisecondsBetweenTwoTimePoints(time_point<high_resolution_clock> t1, time_point<high_resolution_clock> t2) {
    auto duration = duration_cast<milliseconds>(t2 - t1);

    return duration.count();
}
