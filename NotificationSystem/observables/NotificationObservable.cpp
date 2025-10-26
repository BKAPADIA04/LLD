#ifndef NOTIFICATION_OBSERVABLE_H
#define NOTIFICATION_OBSERVABLE_H

#include "../models/IObservable.h"
#include "../models/INotification.h"

class NotificationObservable : public IObservable {
    private:
        vector<IObserver*> observers;
        INotification * currentNotification;

    public:
        NotificationObservable() {
            currentNotification = nullptr;
        }

        void addObserver(IObserver* observer) {
            observers.push_back(observer);
        }

        void removeObserver(IObserver* observer) {
            observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notifyObservers() {
            for(auto it : observers) {
                it->update();
            }
        }

        void setNotification(INotification* notification) {
            if (currentNotification != nullptr) {
                delete currentNotification;
            }

            currentNotification = notification;
            notifyObservers();
        }

        INotification* getNotification() {
            return currentNotification;
        }

        string getNotificationContent() {
            return currentNotification->getContent();
        }

        ~NotificationObservable() {
            if (currentNotification != NULL) {
                delete currentNotification;
            }
        }
};

#endif