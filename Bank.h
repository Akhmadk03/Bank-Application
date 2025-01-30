#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"
#include <iostream>

using namespace std;

class Bank {
private:
    vector<Account> accounts;

public:
    void addAccount(double initialBalance) {
        accounts.emplace_back(initialBalance);
    }

    Account* getAccount(int index) {
        if (index >= 0 && index < accounts.size()) {
            return &accounts[index];
        }
        return nullptr;
    }

    void displayAccounts() const {
        for (int i = 0; i < accounts.size(); ++i) {
            cout << "Account " << i + 1 << ": Balance $" << accounts[i].getBalance() << endl;
        }
    }
};

#endif
