#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include "IObserver.h"

#include <vector>
using namespace std;

class IObservable {
    public:
        virtual void addObserver(IObserver* observer) = 0;
        virtual void removeObserver(IObserver* observer) = 0;
        virtual void notifyObservers() = 0;  
};

#endif