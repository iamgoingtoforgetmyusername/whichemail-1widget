#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//#include "retrieveEmail.h"
//#include "setEmail.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 //   ui->setGeometry(AlignCenter());
    ui->tryagainButton->hide();
    ui->email->hide();
    ui->lineEdit->setFocus();
    connect(ui->OKbutton, SIGNAL(clicked()), this, SLOT(getAcctNo()));
  //  connect(ui, &MainWindow::setEmail, ui->email, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAcctNo()
{
    QString whatWasEntered = ui->lineEdit->text();

    QRegExp re("[^A-Za-z0-9\\s]");
        if (re.indexIn(whatWasEntered) != (-1)){
            ui->email->setText("cannot contain special characters");
            ui->tryagainButton->show();
        }
        else {
    //        QString retrievedEmail = retrieveEmail(whatWasEntered);
            retrieveEmail(whatWasEntered);
       //     ui->email->setText(retrievedEmail);
        //    std::string returnedValue = retrievedEmail.toUtf8().constData();
      //      std::cout << returnedValue << std::endl;
        }
}

QString MainWindow::retrieveEmail(QString acctinput){

    QString retrievedEmail;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "EMAILPW");
        db.setDatabaseName("/home/me/Documents/passwordsDB.db");

     //   bool ifError = db.open();
        QSqlQuery query(db);

    if (!db.open()){
        QMessageBox errorMessage;
        errorMessage.setWindowTitle("error");
        errorMessage.setText("error opening DB");
        errorMessage.exec();
            qDebug() << "error opening DB\n"
                     << query.lastError();
        ui->closebutton->click();
        return "can't open DB";
   //  std::cout << "can't open DB" << std::endl;
    }

  //  std::string acctinput_str = acctinput.toUtf8().constData();
  //  std::cout << acctinput_str << std::endl;
 /*   QString seeIfItExists = "SELECT EXISTS (SELECT EMAIL from EMAILPW WHERE ACCOUNT = '" + acctinput + "');";

query.exec(seeIfItExists);
 //   if (query.isSelect()){
//if (query.isNull(""))
  //  std::cout << "isnull" << std::endl;
    query.next();
    QVariant isItValid = query.value(0);
        if (!query.isValid()){
        QMessageBox doesntExist;
        doesntExist.setWindowTitle("DNE");
        doesntExist.setText("does not exist");
        doesntExist.exec();
        qDebug() << "not able to find acct\n"
                 << query.lastError();
        ui->closebutton->click();
        return "not able to find acct";
        }
       else {
//    }
//else{
std::cout << "test" << std::endl; */
    QString sqlCommand = "SELECT EMAIL from EMAILPW WHERE ACCOUNT = '" + acctinput + "';";

       query.prepare(sqlCommand);

        if(query.exec(sqlCommand))
           {
            query.next();
            if (!query.isValid()){
                ui->email->setText("not able to find acct");
                ui->tryagainButton->show();
       //     QMessageBox doesntExist;
       //     doesntExist.setWindowTitle("DNE");
         //   doesntExist.setText("does not exist");
           // doesntExist.exec();
            qDebug() << "not able to find account\n"
                     << query.lastError();
         //   ui->email->setText("not able to find acct");
        //    ui->closebutton->setFocus();  //doesn't focus on close button
            return "not able to find acct";
            }
           else {
            QString retrievedEmail = query.value(0).toString();
               ui->email->setText(retrievedEmail);
             //  ui->centralwidget->isActiveWindow();
               ui->closebutton->setDefault(true);
           }
}
  //  else setEmail(emailString);

    db.close();

  //  QString retrievedEmailQ = QString::fromStdString(retrievedEmail);
   // return retrievedEmailQ;
    return "maybe I will think of a way to make returning a string useful";
}

//void MainWindow::setEmail(const QString retrievedEmail){

//    ui->email->setText(retrievedEmail);
//}

