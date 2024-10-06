#include <iostream>
#include <string>

using namespace std;

// Structure to hold bank account information
struct BankAccount {
    string accountHolderName;
    double balance;

    BankAccount() : balance(0.0) {} // Constructor to initialize balance
};

// Function prototypes
void createAccount(BankAccount& account);
void deposit(BankAccount& account);
void withdraw(BankAccount& account);
void checkBalance(const BankAccount& account);

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer
        cin.ignore();

        switch (choice) {
            case 1:
                createAccount(account);
                break;
            case 2:
                deposit(account);
                break;
            case 3:
                withdraw(account);
                break;
            case 4:
                checkBalance(account);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new bank account
void createAccount(BankAccount& account) {
    cout << "Enter account holder's name: ";
    getline(cin, account.accountHolderName);
    cout << "Account created successfully for " << account.accountHolderName << "!\n";
}

// Function to deposit money into the account
void deposit(BankAccount& account) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        account.balance += amount;
        cout << "Deposited " << amount << " successfully.\n";
    } else {
        cout << "Invalid amount! Please enter a positive number.\n";
    }
}

// Function to withdraw money from the account
void withdraw(BankAccount& account) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        cout << "Withdrew " << amount << " successfully.\n";
    } else {
        cout << "Invalid amount or insufficient balance!\n";
    }
}

// Function to check the account balance
void checkBalance(const BankAccount& account) {
    cout << "Current balance: " << account.balance << endl;
}
