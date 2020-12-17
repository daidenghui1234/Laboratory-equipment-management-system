#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QString>
class Equipment
{
public:
    Equipment();

    QString device_name;
    QString device_number;    //设备号
    QString model_number;     //型号
    QString device_spec;      //规格
    float device_price;     //单格
    QString device_quantity;   //数量
    QString buy_date;
    QString device_producer;
    QString device_purchaser;
    QString device_lot;     //当相同品牌、批次设备入库时设置该变量，否则默认为1
    int id;
    QString device_user;
};

class RepairD
{
public:
    RepairD();

    QString id;
    QString name;
    QString price;
    QString personliable;
    QString repairdept;
    int num;
    QString lot;
    QString time;
    QString tiptxt;
};

#endif // EQUIPMENT_H
