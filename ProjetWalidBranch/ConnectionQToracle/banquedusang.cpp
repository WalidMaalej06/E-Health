#include "banquedusang.h"


banqueDuSang::banqueDuSang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::banqueDuSang)
{
    ui->setupUi(this);
}

banqueDuSang::~banqueDuSang()
{
    delete ui;
}
