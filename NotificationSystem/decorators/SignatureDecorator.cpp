#ifndef SIGNATURE_DECORATOR_H
#define SIGNATURE_DECORATOR_H

#include "../models/INotificationDecorator.h"

class SignatureDecorator : public INotificationDecorator {
    public:
        SignatureDecorator(INotification *notification) : INotificationDecorator(notification) {}

        string getContent() {
            return "Bhavya Kapadia" + notification->getContent();
        }
};

#endif