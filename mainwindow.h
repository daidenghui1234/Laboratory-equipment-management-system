#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "equipment.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_s_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase sql;
    void initDataBase();
protected:
    void closeEvent(QCloseEvent *event);    //捕捉窗口关闭信号之后将文件写入本地
private:
    void initTable_1();
    void outputOneEqu_1(Equipment *cur,int n);
    void initTable_2();
    void outputOneEqu_2(Equipment *cur, int n);
    void initTable_3();
    void outputOneEqu_3(RepairD *rep, int n);

    bool writetodatebase(const QString &databasename, const Equipment &equi);
    int getNumber(const QString &dataname, const QString tmp);
    void getDevice(const QString &dataname, const QString tmp);
    std::vector<Equipment> equipment;
    void timeshow();
    void intttable();

    bool RepairDevice(RepairD &rep);
    int getDeviceNumber(const QString name);

    int getRepaircol();
    void setRepair();

    bool endRepair(RepairD &rep);
    bool Scrap(RepairD &rep);
    void initTab_4();
    void outputOneEqu_scrap(RepairD &rep,int n);
    int getScrapnum();
};

#endif // MAINWINDOW_H
