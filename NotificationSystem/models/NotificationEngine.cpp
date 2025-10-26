#ifndef NOTIFICATION_ENGINE_H
#define NOTIFICATION_ENGINE_H

#include "IObserver.h"
#include "../observables/NotificationObservable.cpp"
#include "INotificationStrategy.h"

class NotificationEngine : public IObserver {
private:
    NotificationObservable* notificationObservable;
    vector<INotificationStrategy*> notificationStrategies;
    
public:
    NotificationEngine(NotificationObservable* observable) {
        this->notificationObservable = observable;
    }

    void addNotificationStrategy(INotificationStrategy* ns) {
        this->notificationStrategies.push_back(ns);
    }

    void update() {
        string notificationContent = notificationObservable->getNotificationContent();
        for(auto notificationStrategy : notificationStrategies) {
            notificationStrategy->sendNotification(notificationContent);
        }
    }
};

#endif