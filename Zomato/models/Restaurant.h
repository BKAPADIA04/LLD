#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <string>
#include <iostream>
#include "MenuItem.h"
using namespace std;

class Restaurant {
private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem>menu;

public:
    Restaurant(const string &name, const string &location) {
        this->restaurantId = ++nextRestaurantId;
        this->name = name;
        this->location = location;
    }

    ~Restaurant() {
        cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
        menu.clear();
    }

    int getRestaurantId() {
        return restaurantId;
    }

    string getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    string getLocation() const {
        return location;
    }

    void setLocation(const string &location) {
        this->location = location;
    }

    const vector<MenuItem> &getMenu() const {
        return menu;
    }

    void addMenuItem(const MenuItem &item) {
        menu.push_back(item);
    }
};

int Restaurant::nextRestaurantId = 0;

#endif