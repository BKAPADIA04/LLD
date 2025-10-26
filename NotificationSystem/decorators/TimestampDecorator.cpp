#ifndef TIMESTAMP_DECORATOR_H
#define TIMESTAMP_DECORATOR_H

#include "../models/INotificationDecorator.h"

class TimestampDecorator : public INotificationDecorator {
    public:
        TimestampDecorator(INotification *notification) : INotificationDecorator(notification) {}

        string getContent() {
            return "[2025-26-10 15:30:00]" + notification->getContent();
        }
};

#endif