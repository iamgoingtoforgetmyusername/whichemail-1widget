#include "mainwindow.h"
//#include "retrieveEmail.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(500,400,303,164);
    w.show();

 //   if (w.centralWidget()->widget->isHidden()){
 //   QString acctName = w.getAcctNo();
   // std::string utf8_acctno = acctName.toUtf8().constData();
//std::cout << "test" << utf8_acctno << std::endl;
 //   }
    return a.exec();
}
