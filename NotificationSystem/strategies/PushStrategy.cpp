#ifndef Push_STRATEGY_H
#define Push_STRATEGY_H

#include "../models/INotificationStrategy.h"

class PushStrategy : public INotificationStrategy {
    public:

        void sendNotification(string content) {
            // Simulate the process of sending an email notification, 
            // representing the dispatch of messages to users via email.​
            cout << "Sending push Notification : \n" << content;
        }
};

#endif