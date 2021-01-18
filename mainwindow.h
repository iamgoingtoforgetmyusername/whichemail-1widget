#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QRegExp>
#include <QMessageBox>
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
    QString retrieveEmail(QString);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void getAcctNo();

};
#endif // MAINWINDOW_H
