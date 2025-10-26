#ifndef LOGGER_H
#define LOGGER_H

#include "../models/IObserver.h"
#include "../observables/NotificationObservable.cpp"
#include <iostream>

class Logger : public IObserver {
    private:
        NotificationObservable* notificationObservable;

    public:
        Logger(NotificationObservable* notificationObservable) {
            this->notificationObservable = notificationObservable;
        }

        void update() {
            cout << "Logging New Notification : \n" << notificationObservable->getNotificationContent();
        }
};

#endif