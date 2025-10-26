#ifndef INOTIFICATION_H
#define INOTIFICATION_H

#include <string>
using namespace std;

class INotification {
    public:
        virtual string getContent() = 0;
        virtual ~INotification() {}
};

#endif