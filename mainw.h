#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include "sql_heads.h"

namespace Ui {
class MainW;
}

class MainW : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainW(QWidget *parent = 0);
    ~MainW();
    
private slots:
    void on_actionNew_Game_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainW *ui;

    QSqlQueryModel *gam;

};

#endif // MAINW_H
