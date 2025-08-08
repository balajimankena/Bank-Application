#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
public:
    int accountNumber;
    string name;
    double balance;

    Account(int accNo, string accName, double accBalance) {
        accountNumber = accNo;
        name = accName;
        balance = accBalance;
    }
};

class Bank {
private:
    vector<Account> accounts;
    const string filename = "bank_data.txt";

    void saveToFile() {
        ofstream file(filename);
        for (auto &acc : accounts) {
            file << acc.accountNumber << " " << acc.name << " " << acc.balance << "\n";
        }
    }

    void loadFromFile() {
        accounts.clear();
        ifstream file(filename);
        int accNo;
        string accName;
        double accBalance;
        while (file >> accNo >> accName >> accBalance) {
            accounts.emplace_back(accNo, accName, accBalance);
        }
    }

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.accountNumber == accNo) {
                return &acc;
            }
        }
        return nullptr;
    }

public:
    Bank() {
        loadFromFile();
    }

    void createAccount() {
        int accNo;
        string accName;
        double initialDeposit;
        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter name: ";
        cin >> accName;
        cout << "Enter initial deposit: ";
        cin >> initialDeposit;
        accounts.emplace_back(accNo, accName, initialDeposit);
        saveToFile();
        cout << "Account created successfully!\n";
    }

    void deposit() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (acc) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc->balance += amount;
            saveToFile();
            cout << "Deposit successful. New balance: " << acc->balance << "\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdraw() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (acc) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > acc->balance) {
                cout << "Insufficient funds.\n";
            } else {
                acc->balance -= amount;
                saveToFile();
                cout << "Withdrawal successful. New balance: " << acc->balance << "\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    void balanceInquiry() {
        int accNo;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (acc) {
            cout << fixed << setprecision(2);
            cout << "Account Number: " << acc->accountNumber
                 << "\nName: " << acc->name
                 << "\nBalance: " << acc->balance << "\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    void transactionHistory() {
        cout << "----- Transaction History -----\n";
        cout << fixed << setprecision(2);
        for (auto &acc : accounts) {
            cout << "Account: " << acc.accountNumber
                 << " | Name: " << acc.name
                 << " | Balance: " << acc.balance << "\n";
        }
    }
};

int main() {
    Bank bank;
    int choice;
    do {
        cout << "\n----- Bank Application -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Balance Inquiry\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.deposit(); break;
            case 3: bank.withdraw(); break;
            case 4: bank.balanceInquiry(); break;
            case 5: bank.transactionHistory(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
