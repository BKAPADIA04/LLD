#ifndef INOTIFICATION_DECORATOR_H
#define INOTIFICATION_DECORATOR_H

#include "INotification.h"
using namespace std;

class INotificationDecorator : public INotification {
    protected:
        INotification* notification;
    
    public:
        INotificationDecorator(INotification* notification) {
            this->notification = notification;
        }

        virtual ~INotificationDecorator() {
            delete notification;
        }
};

#endif
