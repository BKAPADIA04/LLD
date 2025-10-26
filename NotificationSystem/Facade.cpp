#ifndef FACADE_H
#define FACADE_H

#include "services/NotificationService.cpp"
#include "observers/Logger.cpp"
#include "models/NotificationEngine.cpp"
#include "strategies/EmailStrategy.cpp"
#include "strategies/SMSStrategy.cpp"
#include "strategies/PushStrategy.cpp"
#include "models/INotification.h"
#include "strategies/SimpleNotification.cpp"
#include "decorators/SignatureDecorator.cpp"
#include "decorators/TimestampDecorator.cpp"

int main() {
    // Create NotificationService.
    NotificationService* notificationService = NotificationService::getInstance();

    // Get Observable
    NotificationObservable* notificationObservable = notificationService->getObservable();
   
    // Create Logger Observer
    Logger* logger = new Logger(notificationObservable);

    // Create NotificationEngine observers.
    NotificationEngine* notificationEngine = new NotificationEngine(notificationObservable);

    notificationEngine->addNotificationStrategy(new EmailStrategy("random.person@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("+91 9876543210"));
    notificationEngine->addNotificationStrategy(new PushStrategy());

    // Attach these observers.
    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    // Create a notification with decorators.
    INotification* notification = new SimpleNotification("Your order has been shipped!");
    notification = new TimestampDecorator(notification);
    notification = new SignatureDecorator(notification);
    
    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}

#endif