WebATM
WebATM is a web-based ATM simulator built with C++ and the Crow framework, using SQLite for data storage. It supports basic banking operations such as checking balances, depositing funds, and withdrawing funds.

Features
Check Balance
Deposit Funds
Withdraw Funds
Prerequisites
C++14 compatible compiler
SQLite3
Crow Framework
Setup
1. Clone the Repository
bash
Copy code
git clone https://github.com/yourusername/WebATM.git
cd WebATM
2. Download Crow
bash
Copy code
wget https://raw.githubusercontent.com/CrowCpp/Crow/master/include/crow_all.h -O crow_all.h
3. Build the Project
bash
Copy code
g++ ATMSimulator.cpp sqlite3.c -o WebATM -std=c++14
4. Run the Application
bash
Copy code
./WebATM
API Endpoints
Check Balance
http
Copy code
GET /check_balance/<account_number>
Deposit Funds
http
Copy code
POST /deposit/<account_number>/<amount>
Withdraw Funds
http
Copy code
POST /withdraw/<account_number>/<amount>
