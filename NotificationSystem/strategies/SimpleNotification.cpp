#ifndef SIMPLE_NOTIFICATION_H
#define SIMPLE_NOTIFICATION_H

#include "../models/INotification.h"

class SimpleNotification : public INotification {
    private:
        string text;

    public:
        SimpleNotification(string message) {
            this->text = message;   
        }

        string getContent() {
            return this->text;
        }
};

#endif