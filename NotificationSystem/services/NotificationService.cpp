#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include "../models/INotification.h"
#include "../observables/NotificationObservable.cpp"
#include <vector>


class NotificationService {
private:
    NotificationObservable* observable;
    static NotificationService* instance;
    vector<INotification*> notifications;

    NotificationService() {
        // private constructor
        observable = new NotificationObservable();
    }

public:
    static NotificationService* getInstance() {
        if(instance == nullptr) {
            instance = new NotificationService();
        }
        return instance;
    }

    // Expose the observable so observers can attach.
    NotificationObservable* getObservable() {
        return observable;
    }

    // Creates a new Notification and notifies observers.
    void sendNotification(INotification* notification) {
        notifications.push_back(notification); // history
        observable->setNotification(notification);
    }

    ~NotificationService() {
        delete observable;
    }
};

NotificationService* NotificationService::instance = nullptr;

#endif