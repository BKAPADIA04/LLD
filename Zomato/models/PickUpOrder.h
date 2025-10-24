#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"
using namespace std;

class PickUpOrder : public Order {
private:
    string restaurantAddress;
    
public:
    PickUpOrder() : Order() {
        restaurantAddress = "";
    }

    string getType() const override {
        return "PickUp";
    }

    void setRestaurantAddress(const string& addr) {
        restaurantAddress = addr;
    }

    string getRestaurantAddress() const {
        return restaurantAddress;
    }
};

#endif