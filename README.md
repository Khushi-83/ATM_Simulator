**ATM_Simulator**

ATM_Simulator is a web-based ATM simulator built with C++ and the Crow framework, using SQLite for data storage. 
It supports basic banking operations such as checking balances, depositing funds, and withdrawing funds.

**Features**
1. Check Balance
2. Deposit Funds
3. Withdraw Funds
   
**Prerequisites**
1. C++14 compatible compiler
2. SQLite3
3. Crow Framework
   
**Setup**

1. Clone the Repository:
git clone https://github.com/Khushi-83/ATM_Simulator

cd ATM_Simulator

3. Download Crow:
wget https://raw.githubusercontent.com/CrowCpp/Crow/master/include/crow_all.h -O crow_all.h

5. Build the Project:
g++ ATMSimulator.cpp sqlite3.c -o WebATM -std=c++14

7. Run the Application:
   ./ATM_Simulator
   
**API Endpoints**
Check Balance:
GET /check_balance/<account_number>

Deposit Funds:
POST /deposit/<account_number>/<amount>

Withdraw Funds:
POST /withdraw/<account_number>/<amount>

**License**: <br>
MIT License

**Acknowledgments**: <br>
Crow Framework: CrowCpp <br>
SQLite: SQLite
