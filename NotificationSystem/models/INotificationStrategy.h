#ifndef INOTIFICATION_STRATEGY_H
#define INOTIFICATION_STRATEGY_H

#include <string>
#include <iostream>
using namespace std;

class INotificationStrategy {
    public:    
        virtual void sendNotification(string content) = 0;
};

#endif