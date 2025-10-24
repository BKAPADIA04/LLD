#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
private:
    string mobile;

public:
    UpiPaymentStrategy(const string &mobile) {
        this->mobile = mobile;
    }

    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using UPI from mobile: " << mobile << endl;
    }
};

#endif