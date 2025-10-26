#ifndef EMAIL_STRATEGY_H
#define EMAIL_STRATEGY_H

#include "../models/INotificationStrategy.h"

class EmailStrategy : public INotificationStrategy {
    private:
        string emailId;

    public:

        EmailStrategy(string emailId) {
            this->emailId = emailId;
        }

        void sendNotification(string content) {
            // Simulate the process of sending an email notification, 
            // representing the dispatch of messages to users via email.​
            cout << "Sending email Notification to: " << emailId << "\n" << content;
        }
};

#endif