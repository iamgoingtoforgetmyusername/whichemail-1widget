# whichemail-1widget

This program asks for the name of an account and then tells you the email address associated with it. 

## Getting Started

For Linux:  
to compile:  
in terminal:  
qmake ./whichemail.pro  
make

If make gives you a similar error to this:
ui_mainwindow.h: In member function ‘void Ui_MainWindow::setupUi(QMainWindow*)’:  
ui_mainwindow.h:65:54: error: ‘PlaceholderText’ is not a member of ‘QPalette’  
         palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);

delete the 3 lines in the ui_mainwindow.h file that have "PlaceholderText" in them, e.g.  
palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);

There is also a SQLite database, but it currently only has one entry: "test".   You need to populate the database with accounts you have and the email addresses associated with them (or passwords, or other information associated with them, if you enter them in the database as the email address). The existing columns in the database are: ACCOUNT, EMAIL, PWHASH, and SALT .  The program will only return the EMAIL result, though.  
The database must be in the same directory as the compiled executable.

### Prerequisites

Linux. It was tested on Ubuntu 18.04 and Xubuntu 20.04.

You need to have the following installed: qmake (qt5-qmake), Qt (qt5-default), make, g++.  

also these libraries:

- libQt5Core.so.5
- libQt5Gui.so.5
- libQt5Sql.so.5
- libQt5Widgets.so.5
- libstdc++.so.6
- libgcc_s.so.1
- libc.so.6
- libpthread.so.0
- libm.so.6
- libdl.so.2
- libz.so.1
- libicui18n.sp.60
- libicuuc.so.60
- libdouble-conversion.so.1
- libglib-2.0.so.0
- ld-linux-x86_64.so.2
- libGL.so.1
- libpng16.so.16
- libharfbuzz.so.0
- libicudata.so.60
- libpcre.so.3
- libGLX.so.0
- libGLdispatch.so.0
- libfreetype.so.6
- libgraphiet2.so.3
- libX11.so.6
- libxcb.so.1
- libXau.so.6
- libXsmcp.so.6
- libbsd.so.0
- librt.so.1

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
- make a version that runs in a browser

## Acknowledgments

* people who wrote instructions and put them on the internet or answered questions in forums
* the QT documentation: https://doc.qt.io/qt-5/index.html
* this helped to understand how QT works: https://www.linux.org/threads/c-tutorial-create-qt-applications-without-qtcreator.18409/
