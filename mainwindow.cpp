#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tryagainButton->hide();
    ui->email->hide();
    ui->lineEdit->setFocus();
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
            retrieveEmail(whatWasEntered);
        }
}

QString MainWindow::retrieveEmail(QString acctinput){

    QString retrievedEmail;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "EMAILPW");
    db.setDatabaseName("passwordsDB.db");

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
    }

    QString sqlCommand = "SELECT EMAIL from EMAILPW WHERE ACCOUNT = '" + acctinput + "';";

    query.prepare(sqlCommand);

    if(query.exec(sqlCommand)) {
        query.next();
        if (!query.isValid()){
             ui->email->setText("not able to find acct");
             ui->tryagainButton->show();
             qDebug() << "not able to find account\n"
                     << query.lastError();
            return "not able to find acct";
        }
        else {
            QString retrievedEmail = query.value(0).toString();
            ui->email->setText(retrievedEmail);
            ui->closebutton->setDefault(true);
        }
}

    db.close();

    return "maybe I will think of a way to make returning a string useful";
}

