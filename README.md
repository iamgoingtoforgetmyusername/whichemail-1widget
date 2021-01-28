# whichemail-1widget

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
- linux-vdso.so.1
- libQt5Widgets.so.5
- libQt5Gui.so.5
- libQt5Sql.so.5
- libQt5Core.so.5
- libstdc++.so.6
- libgcc_s.so.1
- libc.so.6
- libpthread.so.0
- libm.so.6
- libGL.so.1
- libpng16.so.16
- libharfbuzz.so.0
- libz.so.1
- libicui18n.sp.60
- libicuuc.so.60
- libdouble-conversion.so.1
- libdl.so.2
- libglib-2.0.so.0
- ld-linux-x86_64.so.2
- libGLX.so.0
- libGLdispatch.so.0
- libfreetype.so.6
- libgraphiet2.so.3
- libcudata.so.60
- libpcre.so.3
- libX11.so.6
- libscb.so.1
- libXau.so.6
- libXsmcp.so.6

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
