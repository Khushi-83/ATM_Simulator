#include "crow_all.h"
#include <unordered_map>
#include <string>
#include <sstream>

class ATM {
private:
    std::unordered_map<int, double> accounts;

public:
    ATM() {
        accounts[1234] = 1000.0;
        accounts[5678] = 500.0;
    }

    bool authenticate(int accountNumber) {
        return accounts.find(accountNumber) != accounts.end();
    }

    double checkBalance(int accountNumber) {
        return accounts[accountNumber];
    }

    void deposit(int accountNumber, double amount) {
        accounts[accountNumber] += amount;
    }

    bool withdraw(int accountNumber, double amount) {
        if (accounts[accountNumber] >= amount) {
            accounts[accountNumber] -= amount;
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    crow::SimpleApp app;
    ATM atm;

    CROW_ROUTE(app, "/check_balance/<int>")
    ([&atm](int accountNumber){
        crow::json::wvalue result;
        if (atm.authenticate(accountNumber)) {
            result["balance"] = atm.checkBalance(accountNumber);
        } else {
            result["error"] = "Invalid account number!";
        }
        return crow::response(result);
    });

    CROW_ROUTE(app, "/deposit/<int>/<double>")
    ([&atm](int accountNumber, double amount){
        crow::json::wvalue result;
        if (atm.authenticate(accountNumber)) {
            atm.deposit(accountNumber, amount);
            result["balance"] = atm.checkBalance(accountNumber);
            result["message"] = "Deposit successful!";
        } else {
            result["error"] = "Invalid account number!";
        }
        return crow::response(result);
    });

    CROW_ROUTE(app, "/withdraw/<int>/<double>")
    ([&atm](int accountNumber, double amount){
        crow::json::wvalue result;
        if (atm.authenticate(accountNumber)) {
            if (atm.withdraw(accountNumber, amount)) {
                result["balance"] = atm.checkBalance(accountNumber);
                result["message"] = "Withdrawal successful!";
            } else {
                result["error"] = "Insufficient funds!";
            }
        } else {
            result["error"] = "Invalid account number!";
        }
        return crow::response(result);
    });

    app.port(8080).multithreaded().run();
}
