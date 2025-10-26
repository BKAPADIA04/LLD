#ifndef SMS_STRATEGY_H
#define SMS_STRATEGY_H

#include "../models/INotificationStrategy.h"

class SMSStrategy : public INotificationStrategy {
    private:
        string phone;

    public:

        SMSStrategy(string phoneNo) {
            this->phone = phoneNo;
        }

        void sendNotification(string content) {
            // Simulate the process of sending an email notification, 
            // representing the dispatch of messages to users via email.​
            cout << "Sending SMS Notification to: " << phone << "\n" << content;
        }
};

#endif