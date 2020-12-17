#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMouseEvent>
#include <string.h>
#include <QMessageBox>
#include <QFileInfo>
#include <QStringList>
#include <QDateTime>
#include <QDebug>
#include <QFont>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    initDataBase();
    setWindowFlags(Qt::FramelessWindowHint);
//  this->setAttribute(Qt::WA_TranslucentBackground);   //设置背景透明
    QFont font("Microsoft YaHei",20,QFont::Bold - 75);
    ui->label_4->setFont(font);
    ui->label_4->setStyleSheet("color:white;");


}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = event->pos();
    }
}

void LoginWindow::mouseReleaseEvent(QMouseEvent *) {
    mousePressed = false;
}

void LoginWindow::mouseMoveEvent(QMouseEvent *event) {
    if (mousePressed && (event->buttons() && Qt::LeftButton)) {
        this->move(event->globalPos() - mousePoint);
        event->accept();
    }
}

void LoginWindow::on_Exit_clicked()
{
    this->reject();
}

void LoginWindow::on_Login_clicked( )
{

    if(verifyLogin(ui->username->text(),ui->password->text())){
        accept();
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("用户名或密码错误!"),QMessageBox::Yes);
              //如果还想清空用户名、密码框，并且光标自动跳转到用户名输入框，就继续下面
              ui->username->clear();
              ui->password->clear();
              ui->username->setFocus();//将光标移到用户名框内
    }
}

void LoginWindow::initDataBase()
{
    // 初始化数据库
    sql = QSqlDatabase::addDatabase("QODBC");
    sql.setHostName("(local)");//服务器名
    sql.setDatabaseName("QSQLServer2");//数据源名
    sql.setUserName("sa");//连接数据库用户名
    sql.setPassword("123456");//连接数据库密码

    if (!sql.open()) {
        qDebug("Sql connect failed.");
        qDebug() << sql.lastError().text();
        QMessageBox::warning(nullptr, "警告", "无法连接数据库");
    } else {
        qDebug("Sql connected.");
    }
}

bool LoginWindow::verifyLogin(const QString name, const QString password)
{
    QSqlQuery query;
    query.exec("select * from [user]");
    bool chekname=false;
    bool chekpassword=false;
    // 打印输出用户名和密码
    while (query.next()) {
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString()
                 << query.value(2).toString();
       chekname = (QString::compare(name,query.value(1).toString(),
                                         Qt::CaseSensitive) == 0);
       chekpassword = (QString::compare(password,query.value(2).toString(),
                                             Qt::CaseSensitive) == 0);

        if(chekname&&chekpassword){
            return true;
        }
    }
    return false;
}

