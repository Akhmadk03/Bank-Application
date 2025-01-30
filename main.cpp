#include <iostream>
#include "Bank.h"


using namespace std;

void displayMenu() {
    cout << "\n=== Bank Menu ===\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Display All Accounts\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void handleUserInput(Bank& bank) {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            double initialBalance;
            cout << "Enter initial balance for new account: ";
            cin >> initialBalance;
            bank.addAccount(initialBalance);
            break;
        }
        case 2: {
            int index;
            double amount;
            cout << "Enter account number: ";
            cin >> index;
            cout << "Enter deposit amount: ";
            cin >> amount;
            Account* account = bank.getAccount(index - 1);
            if (account) {
                account->deposit(amount);
            } else {
                cout << "Invalid account number." << endl;
            }
            break;
        }
        case 3: {
            int index;
            double amount;
            cout << "Enter account number: ";
            cin >> index;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            Account* account = bank.getAccount(index - 1);
            if (account && account->withdraw(amount)) {
                cout << "Withdrawal successful." << endl;
            } else {
                cout << "Invalid transaction." << endl;
            }
            break;
        }
        case 4: {
            bank.displayAccounts();
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

int main() {
    Bank bank;
    while (true) {
        displayMenu();
        handleUserInput(bank);
    }
    return 0;
}
