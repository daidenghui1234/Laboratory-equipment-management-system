#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipment.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化数据库
    initDataBase();
    intttable();
    connect(ui->comboBox_s,&QComboBox::currentTextChanged,this,&MainWindow::timeshow);
    connect(ui->toolBox,&QToolBox::currentChanged,this,&MainWindow::intttable);
    connect(ui->toolBox_2,&QToolBox::currentChanged,this,&MainWindow::initTable_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDataBase()
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
        button=QMessageBox::question(this,QStringLiteral("退出程序"),QStringLiteral("确认退出程序"),QMessageBox::Yes|QMessageBox::No);
        if(button==QMessageBox::No)
        {
            event->ignore(); // 忽略退出信号，程序继续进行
        }
        else if(button==QMessageBox::Yes)
        {
            event->accept(); // 接受退出信号，程序退出
        }
}


bool MainWindow::writetodatebase(const QString &databasename, const Equipment &equi)
{
    QSqlQuery query;
    QString tmp = QString("INSERT INTO [dbo].[%11]([device_name], [device_number],"
                          " [model_number], [device_spec], [device_price], "
                          "[device_quantity], [buy_date], [device_producer], "
                          "[device_purchaser], [device_lot]) VALUES "
                          "('%1', '%2', '%3',"
                          " '%4', %5, '%6', '%7',"
                          " '%8', '%9', '%10');")
            .arg(equi.device_name).arg(equi.device_number).arg(equi.model_number)
            .arg(equi.device_spec).arg(equi.device_price).arg(equi.device_quantity)
            .arg(equi.buy_date).arg(equi.device_producer).arg(equi.device_purchaser)
            .arg(equi.device_lot).arg(databasename);
    return query.exec(tmp);
}

void MainWindow::on_pushButton_2_clicked()
{
    Equipment newEqu;
    newEqu.device_name = ui->LineEdit->text();
    newEqu.device_number = ui->LineEdit_2->text();
    newEqu.model_number = ui->LineEdit_3->text();
    newEqu.device_spec = ui->LineEdit_4->text();
    newEqu.device_price = ui->LineEdit_5->text().toFloat();
    newEqu.device_quantity= ui->LineEdit_6->text();
    newEqu.buy_date= ui->dateEdit->text();
    newEqu.device_producer = ui->LineEdit_8->text();
    newEqu.device_purchaser = ui->LineEdit_9->text();
    newEqu.device_lot = ui->LineEdit_lot->text();
    writetodatebase(QString("device"),newEqu);
    if(writetodatebase(QString("device_copy1"),newEqu)){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("设备添加完成"),QMessageBox::Yes);
    }
}
void MainWindow::initTable_1()
{
    ui->tableWidget_1->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格不可编辑
//    ui->tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置表格整行选中
    ui->lineEdit_s_dn->hide();
    ui->dateEdit->show();
    //设置表头
    int width = ui->tableWidget_1->width();
    ui->tableWidget_1->setColumnCount(11);      //设置列数
    ui->tableWidget_1->setColumnWidth(0, static_cast<int>(round(width * 0.06)));
    ui->tableWidget_1->setColumnWidth(1, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(2, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(3, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(4, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(5, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(6, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(7, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(8, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(9, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(10, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->setColumnWidth(11, static_cast<int>(round(width * 0.15)));
    ui->tableWidget_1->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
//    headText<<"1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
//    headText << "名称" << "设备号" << "型号" << "规格" << "单价" << "数量" << "购置日期" << "生产商家" << "购买人" ;
    headText << QStringLiteral("序号") << QStringLiteral("名称") << QStringLiteral("设备号")<< QStringLiteral("型号")
             << QStringLiteral("规格") << QStringLiteral("单价") << QStringLiteral("数量") << QStringLiteral("购置日期")
              << QStringLiteral("生产商家") << QStringLiteral("购买人")<< QStringLiteral("批次") <<QStringLiteral("所在机房");
    ui->tableWidget_1->setHorizontalHeaderLabels(headText);
    ui->tableWidget_1->horizontalHeader()->setStyleSheet("QHeaderView::section{background:whitesmoke;}");
    ui->tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_1->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_1->setAlternatingRowColors(true);
    ui->tableWidget_1->verticalHeader()->setVisible(false);
    ui->tableWidget_1->horizontalHeader()->setStretchLastSection(true);

    //设置行高
    ui->tableWidget_1->setRowCount(0);    //设置行数
}

void MainWindow::initTable_2()
{
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格不可编辑
    //    ui->tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置表格整行选中

        int width = ui->tableWidget_2->width();
        ui->tableWidget_2->setColumnCount(11);      //设置列数
        ui->tableWidget_2->setColumnWidth(0, static_cast<int>(round(width * 0.06)));
        ui->tableWidget_2->setColumnWidth(1, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(2, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(3, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(4, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(5, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(6, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(7, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(8, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(9, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->setColumnWidth(10, static_cast<int>(round(width * 0.15)));
    //    ui->tableWidget_2->setColumnWidth(11, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(25);

        QStringList headText;

        headText << QStringLiteral("序号") << QStringLiteral("名称") << QStringLiteral("设备号")<< QStringLiteral("型号")
                 << QStringLiteral("规格") << QStringLiteral("单价") << QStringLiteral("数量") << QStringLiteral("购置日期")
                  << QStringLiteral("生产商家") << QStringLiteral("购买人")<< QStringLiteral("批次") <<QStringLiteral("所在机房");
        ui->tableWidget_2->setHorizontalHeaderLabels(headText);
        ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:whitesmoke;}");
        ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableWidget_2->setAlternatingRowColors(true);
        ui->tableWidget_2->verticalHeader()->setVisible(false);
        ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

        //设置行高
        ui->tableWidget_2->setRowCount(0);    //设置行数
}
void MainWindow::outputOneEqu_1(Equipment *cur, int n)
{
    QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(n+1));   //序号
        QTableWidgetItem *itemDevice_name =new QTableWidgetItem(cur->device_name);
        QTableWidgetItem *itemDevice_number = new QTableWidgetItem(cur->device_number);
        QTableWidgetItem *itemModel_number = new QTableWidgetItem(cur->model_number);
        QTableWidgetItem *itemDevice_spec = new QTableWidgetItem(cur->device_spec);
        QTableWidgetItem *itemDevice_price = new QTableWidgetItem(QString("%1").arg(cur->device_price));
        QTableWidgetItem *itemDevice_quantity = new QTableWidgetItem(cur->device_quantity);
        QTableWidgetItem *itemBuy_date = new QTableWidgetItem(cur->buy_date );
        QTableWidgetItem *itemDevice_producer = new QTableWidgetItem(cur->device_producer);
        QTableWidgetItem *itemDevice_purchaser = new QTableWidgetItem(cur->device_purchaser);
        QTableWidgetItem *itemDevice_lot = new QTableWidgetItem(cur->device_lot);


        ui->tableWidget_1->setItem(n,0,itemDeviceID);
        ui->tableWidget_1->setItem(n,1,itemDevice_name);
        ui->tableWidget_1->setItem(n,2,itemDevice_number);
        ui->tableWidget_1->setItem(n,3,itemModel_number);
        ui->tableWidget_1->setItem(n,4,itemDevice_spec);
        ui->tableWidget_1->setItem(n,5,itemDevice_price);
        ui->tableWidget_1->setItem(n,6,itemDevice_quantity);
        ui->tableWidget_1->setItem(n,7,itemBuy_date);
        ui->tableWidget_1->setItem(n,8,itemDevice_producer);
        ui->tableWidget_1->setItem(n,9,itemDevice_purchaser);
        ui->tableWidget_1->setItem(n,10,itemDevice_lot);
}

void MainWindow::outputOneEqu_2(Equipment *cur, int n)
{
    QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString("%1").arg(cur->id));   //序号
        QTableWidgetItem *itemDevice_name =new QTableWidgetItem(cur->device_name);
        QTableWidgetItem *itemDevice_number = new QTableWidgetItem(cur->device_number);
        QTableWidgetItem *itemModel_number = new QTableWidgetItem(cur->model_number);
        QTableWidgetItem *itemDevice_spec = new QTableWidgetItem(cur->device_spec);
        QTableWidgetItem *itemDevice_price = new QTableWidgetItem(QString("%1").arg(cur->device_price));
        QTableWidgetItem *itemDevice_quantity = new QTableWidgetItem(cur->device_quantity);
        QTableWidgetItem *itemBuy_date = new QTableWidgetItem(cur->buy_date);
        QTableWidgetItem *itemDevice_producer = new QTableWidgetItem(cur->device_producer);
        QTableWidgetItem *itemDevice_purchaser = new QTableWidgetItem(cur->device_purchaser);
        QTableWidgetItem *itemDevice_lot = new QTableWidgetItem(cur->device_lot);


       ui->tableWidget_2->setItem(n,0,itemDeviceID);
       ui->tableWidget_2->setItem(n,1,itemDevice_name);
       ui->tableWidget_2->setItem(n,2,itemDevice_number);
       ui->tableWidget_2->setItem(n,3,itemModel_number);
       ui->tableWidget_2->setItem(n,4,itemDevice_spec);
       ui->tableWidget_2->setItem(n,5,itemDevice_price);
       ui->tableWidget_2->setItem(n,6,itemDevice_quantity);
       ui->tableWidget_2->setItem(n,7,itemBuy_date);
       ui->tableWidget_2->setItem(n,8,itemDevice_producer);
       ui->tableWidget_2->setItem(n,9,itemDevice_purchaser);
       ui->tableWidget_2->setItem(n,10,itemDevice_lot);
}

void MainWindow::initTable_3()
{
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格不可编辑
        int width = ui->tableWidget_3->width();
        ui->tableWidget_3->setColumnCount(7);      //设置列数
        ui->tableWidget_3->setColumnWidth(0, static_cast<int>(round(width * 0.1)));
        ui->tableWidget_3->setColumnWidth(1, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_3->setColumnWidth(2, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_3->setColumnWidth(3, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_3->setColumnWidth(4, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_3->setColumnWidth(5, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_3->setColumnWidth(5, static_cast<int>(round(width * 0.15)));
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(25);

        QStringList headText;

        headText << QStringLiteral("序号") << QStringLiteral("设备名") << QStringLiteral("维修费") << QStringLiteral("维修编号")
                 << QStringLiteral("责任人")<< QStringLiteral("修理厂家") << QStringLiteral("数量");
        ui->tableWidget_3->setHorizontalHeaderLabels(headText);
        ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{background:whitesmoke;}");
        ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_3->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableWidget_3->setAlternatingRowColors(true);
        ui->tableWidget_3->verticalHeader()->setVisible(false);
        ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);

        //设置行高
        ui->tableWidget_3->setRowCount(0);    //设置行数
}

void MainWindow::outputOneEqu_3(RepairD *rep, int n)
{
    QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(n+1));   //序号
    QTableWidgetItem *itemDevice_name =new QTableWidgetItem(rep->name);
    QTableWidgetItem *itemCost = new QTableWidgetItem(rep->price);
    QTableWidgetItem *itemDevice_number = new QTableWidgetItem(QString("%1").arg(rep->num));
    QTableWidgetItem *itemMan = new QTableWidgetItem(rep->personliable);
    QTableWidgetItem *itemIden = new QTableWidgetItem(rep->id);
    QTableWidgetItem *itemVender = new QTableWidgetItem(rep->repairdept);

   ui->tableWidget_3->setItem(n,0,itemDeviceID);
   ui->tableWidget_3->setItem(n,1,itemDevice_name);
   ui->tableWidget_3->setItem(n,2,itemCost);
   ui->tableWidget_3->setItem(n,3,itemIden);
   ui->tableWidget_3->setItem(n,4,itemMan);
   ui->tableWidget_3->setItem(n,5,itemVender);
   ui->tableWidget_3->setItem(n,6,itemDevice_number);
}

int MainWindow::getNumber(const QString &dataname, const QString tmp)
{
    QSqlQuery query;
    query.exec(QString("select COUNT(*) from device where"
                       " %1 = '%2'")
               .arg(dataname).arg(tmp));
    query.next();
    return query.value(0).toInt();
}

void MainWindow::getDevice(const QString &dataname, const QString tmp)
{
    QSqlQuery query;
    int i = 0;
    QString temp = QString("select * from device where"
                          " %1 = '%2'")
                  .arg(dataname).arg(tmp);
    query.exec(temp);
    qDebug() << temp;
    while(query.next()){
        Equipment eq;
        eq.id = query.value(0).toInt();
        eq.device_name = query.value(1).toString();
        eq.device_number = query.value(2).toString();
        eq.model_number = query.value(3).toString();
        eq.device_spec = query.value(4).toString();
        eq.device_price = query.value(5).toFloat();
        eq.device_quantity = query.value(6).toString();
        eq.buy_date = query.value(7).toString();
        eq.device_producer = query.value(8).toString();
        eq.device_purchaser = query.value(9).toString();
        eq.device_lot = query.value(10).toString();
        outputOneEqu_1(&eq,i);
        i++;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    initTable_2();
    int i = 0;
    QSqlQuery query;
    query.exec(QString("select count(*) from device;"));
    query.next();
    int n = query.value(0).toInt();
    ui->tableWidget_2->setRowCount(n);

    query.exec(QString("SELECT * FROM [dbo].[device]"));
    while (query.next()) {
        Equipment eq;
        eq.id = query.value(0).toInt();
        eq.device_name = query.value(1).toString();
        eq.device_number = query.value(2).toString();
        eq.model_number = query.value(3).toString();
        eq.device_spec = query.value(4).toString();
        eq.device_price = query.value(5).toFloat();
        eq.device_quantity = query.value(6).toString();
        eq.buy_date = query.value(7).toString();
        eq.device_producer = query.value(8).toString();
        eq.device_purchaser = query.value(9).toString();
        eq.device_lot = query.value(10).toString();
        outputOneEqu_2(&eq,i);
        i++;
    }
}

// 查询
void MainWindow::on_pushButton_s_clicked()
{
    initTable_1();
    QString select = ui->comboBox_s->currentText();
    qDebug() << select;
    QString tmp;
    int n;
    if(select==QString("购置日期")){
        tmp = ui->dateEdit->dateTime().toString("yyyy-MM-dd");
        n = getNumber(QString("buy_date"),tmp);
        ui->tableWidget_1->setRowCount(n);
        getDevice(QString("buy_date"),tmp);
    }
    if(select==QString("设备名称")){
        tmp = ui->lineEdit_s_dn->text();
        n = getNumber(QString("device_name"),tmp);
        ui->tableWidget_1->setRowCount(n);
        getDevice(QString("device_name"),tmp);
    }
    if(select==QString("购买人")){
        tmp = ui->lineEdit_s_dn->text();
        n = getNumber(QString("device_purchaser"),tmp);
        ui->tableWidget_1->setRowCount(n);
        getDevice(QString("device_purchaser"),tmp);
    }
}

void MainWindow::timeshow()
{
    QString select = ui->comboBox_s->currentText();
    if(select==QString("购置日期")){
        ui->dateEdit->show();
        ui->lineEdit_s_dn->hide();
    }
    if(select==QString("设备名称")){
        ui->dateEdit->hide();
        ui->lineEdit_s_dn->show();
    }
    if(select==QString("购买人")){
        ui->dateEdit->hide();
        ui->lineEdit_s_dn->show();
    }
}

void MainWindow::intttable()
{
    initTable_1();
    initTable_2();
    initTable_3();
    initTab_4();
}

bool MainWindow::RepairDevice(RepairD &rep)
{
    int n = getDeviceNumber(rep.name);
    qDebug() << "设备数量： " << n ;
    if(n < rep.num){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("保修数量超出库存"),QMessageBox::Yes);
        return false;
    }else{
        QSqlQuery query;
        QString temp = QString("INSERT INTO [dbo].[repair]([id], [name], [price], [personliable], "
                               "[repairdept], [number], [lot]) VALUES "
                               "('%1', '%2', '%3', '%4', '%5', %6, '%7');")
                      .arg(rep.id).arg(rep.name).arg(rep.price).
                arg(rep.personliable).arg(rep.repairdept).arg(rep.num).arg(rep.lot);
        query.exec(temp);
        qDebug() << temp;
        temp = QString("UPDATE [dbo].[device] SET  [device_quantity] = '%1'"
                       " WHERE [device_name] = '%2';")
                .arg(n-rep.num).arg(rep.name);
        qDebug() << temp;
        return query.exec(temp);
    }
}

int MainWindow::getDeviceNumber(const QString name)
{
    QSqlQuery query;
    query.exec(QString("select device_quantity "
                       "from device where device_name "
                       "= '%1'").arg(name));
    query.next();
    return query.value(0).toInt();
}

int MainWindow::getRepaircol()
{
    QSqlQuery query;
    query.exec(QString("SELECT COUNT(*) from repair"));
    query.next();
    return query.value(0).toInt();
}

void MainWindow::setRepair()
{
    QSqlQuery query;
    query.exec(QString("SELECT * from repair"));
    int i = 0;
    while(query.next())
    {
        RepairD rep;
        rep.id = query.value(0).toString();
        rep.name = query.value(1).toString();
        rep.price = query.value(2).toString();
        rep.personliable = query.value(3).toString();
        rep.repairdept = query.value(4).toString();
        rep.num = query.value(5).toInt();
        rep.lot = query.value(6).toString();
        outputOneEqu_3(&rep,i);
        i++;
    }
}

bool MainWindow::endRepair(RepairD &rep)
{
    QSqlQuery query;
    QString tmp = QString("SELECT number from repair "
                          "where repair.id = '%1' "
                          "and name = '%2' ")
            .arg(rep.id).arg(rep.name);
    query.exec(tmp);
    query.next();
    // 2222
    int num = query.value(0).toInt();
    if(rep.num > num){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("超出数量值"),QMessageBox::Yes);
        return false;
    }
    int n = getDeviceNumber(rep.name);
    tmp = QString("UPDATE [dbo].[repair] SET [number] = %1 "
                  " WHERE [id] = '%2';")
            .arg(num-rep.num).arg(rep.id);
    query.exec(tmp);
    tmp = QString("UPDATE [dbo].[device] SET  [device_quantity] = '%1'"
                   " WHERE [device_name] = '%2';")
            .arg(n+rep.num).arg(rep.name);
    return query.exec(tmp);
}

void MainWindow::on_pushButton_5_clicked()
{
    RepairD rep;
    rep.id = ui->LineEdit_r_iden_1->text();
    rep.name = ui->LineEdit_r_name_1->text();
    rep.price = ui->LineEdit_r_money_1->text();
    rep.personliable = ui->LineEdit_r_peo_1->text();
    rep.repairdept = ui->LineEdit_r_pro_1->text();
    rep.num = ui->LineEdit_r_num_1->text().toInt();
    rep.lot = ui->LineEdit_r_lot->text();
    if(rep.num <=0){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("请输入数量"),QMessageBox::Yes);
        return;
    }
    if(rep.name == QString("") ||
            rep.price == QString("")||
            rep.personliable == QString("") ||
            rep.repairdept == QString("") ||
            rep.lot == QString("")){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("请不要空行"),QMessageBox::Yes);
        return;
    }
    if(RepairDevice(rep))
    {
        QMessageBox::warning(this,tr("warning"),QStringLiteral("保修提交成功"),QMessageBox::Yes);
    }
}



// 送修
void MainWindow::on_pushButton_8_clicked()
{
    ui->tableWidget_3->setRowCount(getRepaircol());
    setRepair();
}

// 完成维修
void MainWindow::on_pushButton_6_clicked()
{
    RepairD rep;
    rep.name = ui->LineEdit_r_name_2->text();
    rep.personliable = ui->LineEdit_r_peo_2->text();
    rep.repairdept = ui->LineEdit_r_pro_2->text();
    rep.num = ui->LineEdit_r_num_2->text().toInt();
    rep.id = ui->LineEdit_r_iden_2->text();
    if(endRepair(rep)){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("维修完成"),QMessageBox::Yes);
    }
}

//报废函数

bool MainWindow::Scrap(RepairD &rep)
{
    QSqlQuery query;

    QString tmp;
    int num = getDeviceNumber(rep.name);
    if(num < rep.num){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("数量错误"),QMessageBox::Yes);
        return false;
    }

    tmp = QString("UPDATE [dbo].[device] SET  [device_quantity] = '%1'"
                  " WHERE [device_name] = '%2';")
           .arg(num-rep.num).arg(rep.name);
    query.exec(tmp);
    tmp = QString("INSERT INTO [dbo].[Scrap]"
                          "([name], [num], [batch],"
                          " [data], [tip]) VALUES "
                          "('%1', %2, '%3', '%4', '%5')")
            .arg(rep.name).arg(rep.num).arg(rep.lot).arg(rep.time).arg(rep.tiptxt);
    qDebug() << tmp;

    return query.exec(tmp);
}

void MainWindow::initTab_4()
{
    ui->tableWidget_scrap->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格不可编辑
//    ui->tableWidget_scrap->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置表格整行选中
    //设置表头
    int width = ui->tableWidget_scrap->width();
    ui->tableWidget_scrap->setColumnCount(6);      //设置列数
    ui->tableWidget_scrap->setColumnWidth(0, static_cast<int>(round(width * 0.06)));
    ui->tableWidget_scrap->setColumnWidth(1, static_cast<int>(round(width * 0.188)));
    ui->tableWidget_scrap->setColumnWidth(2, static_cast<int>(round(width * 0.188)));
    ui->tableWidget_scrap->setColumnWidth(3, static_cast<int>(round(width * 0.188)));
    ui->tableWidget_scrap->setColumnWidth(4, static_cast<int>(round(width * 0.188)));
    ui->tableWidget_scrap->setColumnWidth(5, static_cast<int>(round(width * 0.188)));

    ui->tableWidget_scrap->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << QStringLiteral("序号") << QStringLiteral("设备名称") << QStringLiteral("数量")<< QStringLiteral("批次")
             << QStringLiteral("报废日期") << QStringLiteral("备注") ;
    ui->tableWidget_scrap->setHorizontalHeaderLabels(headText);
    ui->tableWidget_scrap->horizontalHeader()->setStyleSheet("QHeaderView::section{background:whitesmoke;}");
    ui->tableWidget_scrap->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_scrap->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_scrap->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_scrap->setAlternatingRowColors(true);
    ui->tableWidget_scrap->verticalHeader()->setVisible(false);
    ui->tableWidget_scrap->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::outputOneEqu_scrap(RepairD &rep,int n)
{
    QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(n+1));   //序号
    QTableWidgetItem *itemDevice_name =new QTableWidgetItem(rep.name);
    QTableWidgetItem *itemDevice_number = new QTableWidgetItem(QString("%1").arg(rep.num));
    QTableWidgetItem *itemRemark = new QTableWidgetItem(rep.tiptxt);
    QTableWidgetItem *itemscrapDate = new QTableWidgetItem(rep.time);
    QTableWidgetItem *itemDevice_lot = new QTableWidgetItem(rep.lot);


   ui->tableWidget_scrap->setItem(n,0,itemDeviceID);
   ui->tableWidget_scrap->setItem(n,1,itemDevice_name);
   ui->tableWidget_scrap->setItem(n,2,itemDevice_number);
   ui->tableWidget_scrap->setItem(n,3,itemDevice_lot);
   ui->tableWidget_scrap->setItem(n,4,itemscrapDate);
   ui->tableWidget_scrap->setItem(n,5,itemRemark);
}

int MainWindow::getScrapnum()
{
    QSqlQuery query;
    QString tmp;
    tmp = QString("SELECT COUNT(*) FROM [dbo].[Scrap]");
    query.exec(tmp);
    query.next();
    return query.value(0).toInt();
}

// 报废
void MainWindow::on_pushButton_9_clicked()
{
    RepairD rep;
    rep.name = ui->LineEdit_scrap_dn->text();
    rep.num = ui->LineEdit_scrap_num->text().toInt();
    rep.lot = ui->LineEdit_scrap_lot->text();
    rep.time = ui->dateTimeEdit->text();
    rep.tiptxt = ui->LineEdit_scrap_mess->text();
    if(Scrap(rep)){
        QMessageBox::warning(this,tr("warning"),QStringLiteral("报废提交完成"),QMessageBox::Yes);
    }
}

// 查询报废
void MainWindow::on_pushButton_11_clicked()
{
    int total = getScrapnum();
    ui->tableWidget_scrap->setRowCount(total);
    QSqlQuery query;
    QString tmp;
    tmp = QString("SELECT * FROM [dbo].[Scrap]");
    query.exec(tmp);
    int i = 0;
    while(query.next()){
        RepairD rep;
        rep.id = query.value(0).toInt();
        rep.name = query.value(1).toString();
        rep.num = query.value(2).toInt();
        rep.lot = query.value(3).toString();
        rep.time = query.value(4).toString();
        rep.tiptxt = query.value(5).toString();
        outputOneEqu_scrap(rep,i);
        i++;
    }
}
