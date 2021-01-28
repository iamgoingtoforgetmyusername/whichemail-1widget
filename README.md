# whichemail-static

This program asks for the name of an account and then tells you the email address associated with it. 

## Getting Started

TODO

For Linux:  
to compile:  
in terminal:  
make

There is also a SQLite database, but it currently only has one entry: "test".   You need to populate the database with accounts you have and the email addresses associated with them (or passwords, or other information associated with them, if you enter them in the database as the email address). The existing columns in the database are: ACCOUNT, EMAIL, PWHASH, and SALT .  The program will only return the EMAIL result, though.  
The database must be in the same directory as the compiled executable.

### Prerequisites

Linux. It was tested on Ubuntu 18.04.

depends on these libraries:
TODO


## Built With

QT Creator. Database with SQLite3.

## Usage

can be run from terminal  
Although the database is set up with a password column, the program will only return the EMAIL result.  
Account names cannot contain special characters. Spaces are OK.  
When it asks, enter the name of an account.  
It should return the email address associated with that account.  

## Roadmap

- DB currently isn't relevant for anyone but me  
- make it work with hashed passwords
- make a version for macs

## Author

me 

## Acknowledgments

* people who wrote instructions and put them on the internet or answered questions in forums
* the QT documentation: https://doc.qt.io/qt-5/index.html
* this helped to understand how QT works: https://www.linux.org/threads/c-tutorial-create-qt-applications-without-qtcreator.18409/
