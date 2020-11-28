#ifndef BANQUEDUSANG_H
#define BANQUEDUSANG_H

#include <QDialog>

namespace Ui {
class banqueDuSang;
}

class banqueDuSang : public QDialog
{
    Q_OBJECT

public:
    explicit banqueDuSang(QWidget *parent = nullptr);
    ~banqueDuSang();

private:
    Ui::banqueDuSang *ui;
};

#endif // BANQUEDUSANG_H
