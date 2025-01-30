#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance > 0 ? initialBalance : 0) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

#endif
