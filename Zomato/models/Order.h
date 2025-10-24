#ifndef ORDER_H
#define ORDER_H

#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include <vector>
using namespace std;

class Order {
protected:
    static int nextOrderId;
    int orderId;
    User *user;
    Restaurant *restaurant;
    vector<MenuItem> items;
    PaymentStrategy *paymentStrategy;  
    double total;
    string scheduled;

public:
    Order() {
        orderId = ++nextOrderId;
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
    }

    virtual ~Order() {
        cout << "Destroying Order ID: " << orderId << endl;
        items.clear();
        delete paymentStrategy;
    }

    bool processPayment() {
        if (paymentStrategy) {
            paymentStrategy->pay(total);
            return true;
        } else {
            cout << "Please choose a payment mode first" << endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    int getOrderId() const {
        return orderId;
    }

    void setUser(User* u) {
        user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setItems(const vector<MenuItem>& its) {
        items = its;
        total = 0;
        for (auto &i : items) {
            total += i.getPrice();
        }
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p) {
        paymentStrategy = p;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }
};

int Order::nextOrderId = 0;

#endif