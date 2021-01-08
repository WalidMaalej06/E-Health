/*#include "capteurson.h"
#include <QObject>
#include <QStringList>

Capteurtemp::Capteurtemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Capteurtemp)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch(ret)
    {
    case(0):qDebug() <<"arduino is available and connected to :"<<A.getarduino_port_name();
        break;
    case(1):qDebug() <<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
    case(-1):qDebug() <<"arduino is not available";
        break;

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(readSerial()));

}

Capteurtemp::~Capteurtemp()
{
    delete ui;
}

void Capteurtemp::readSerial()
{
    QString serialBuffer;
    QStringList bufferSplit = serialBuffer.split(",");
    if(bufferSplit.length()<3)
    {
        data = A.read_from_arduino();
        serialBuffer += QString::fromStdString(data.toStdString());

    }
    else
    {
        qDebug() << bufferSplit;
        Capteurtemp::update_lcdnumber(bufferSplit[1]);
        serialBuffer="";
    }
    qDebug() << "serial port works";
}

void Capteurtemp::update_lcdnumber(const QString sensor_reading)
{
    //ui->tempLcdNumber->display(sensor_reading);
}

*/

