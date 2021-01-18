#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <string>
//#include <QEventLoop>
#include <QRegExp>
#include <QMessageBox>
#include <sqlite3.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
 //   QString getAcctNo();
    QString retrieveEmail(QString);
 //   void setEmail(QString);
    int callback (void*, int, char**, char**);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void getAcctNo();

//signals:
  //  void setEmail(QString);

};
#endif // MAINWINDOW_H
