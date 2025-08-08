# Bank-Application – File-Based Banking Management System in C++
This project is a menu-driven banking management system written in **C++** using object-oriented programming principles.   It allows users to create accounts, deposit and withdraw money, check balances, and view transaction history.   All account data is stored in a text file for **persistent storage** between program runs.

## Features
- **Create Account** – Add a new customer account with an initial deposit.
- **Deposit** – Add money to an existing account.
- **Withdraw** – Remove money from an account (with insufficient funds check).
- **Balance Inquiry** – Check account details and current balance.
- **Transaction History** – View all stored accounts with their balances.
- **File Persistence** – Data is stored in `bank_data.txt` for long-term storage.

## Technologies & Tools
- **Language:** C++
- **Concepts:** Classes, File Handling, Vectors
- **IDE:** Any C++ compiler (G++, VS Code, Code::Blocks, etc.)

## How It Works
1. On startup, the program loads account data from `bank_data.txt`.
2. Users can perform various banking operations via a menu.
3. All changes are saved back to the file after each transaction.

## File Structure
Bank-Application/
│
├── code/
│ └── bank_application.cpp # Main source code
├── docs/
│ └── sample_output.txt # Example run of the program
└── bank_data.txt # File storing account information

## Sample Output
See [`docs/sample_output.txt`](docs/sample_output.txt) for an example program run.

## Author
C N Sri Balaji Vara Prasad Mankena
