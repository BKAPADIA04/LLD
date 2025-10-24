#ifndef USER_H
#define USER_H

#include <string>
#include "Cart.h"
using namespace std;

class User {
private:
    int userId;
    string name;
    string address;
    Cart *cart;

public:
    User(int id, const string &name, const string &address) {
        this->userId = id;
        this->name = name;
        this->address = address;
        this->cart = new Cart();
    }

    ~User() {
        delete cart;
    }

    int getUserId() const {
        return userId;
    }

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    Cart* getCart() const {
        return cart;
    }

    void setAddress(const string &newAddress) {
        address = newAddress;
    }

    void setName(const string &newName) {
        name = newName;
    }
};

#endif