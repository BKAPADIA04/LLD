#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "MenuItem.h"
#include "Restaurant.h"

class Cart{
private:
    vector<MenuItem> items;
    Restaurant *restaurant;

public:
    Cart() {
        restaurant = nullptr;
    }

    ~Cart() {
        items.clear();
        restaurant = nullptr;
    }

    void addItem(const MenuItem &item) {
        if(!restaurant) {
            cerr << "Cart: Set a restaurant before adding items." << endl;
            return;
        }
        items.push_back(item);
    }

    double getTotalCost() const {
        double sum = 0;
        for (const auto& it : items) {
            sum += it.getPrice();
        }
        return sum;
    }

    void clear() {
        items.clear();
        restaurant = nullptr;
    }

    bool isEmpty() const {
        return items.empty();
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setRestaurant(Restaurant* res) {
        if(restaurant && restaurant != res) {
            cerr << "Cart: Changing restaurant. Clearing existing items." << endl;
        }
        restaurant = res;
    }


};

#endif