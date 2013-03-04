#include "mainw.h"
#include "ui_mainw.h"
#include "newgame.h"

MainW::MainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainW)
{
    ui->setupUi(this);




}

MainW::~MainW()
{
    delete ui;
}

void MainW::on_actionNew_Game_triggered()
{
    NewGame nGame;
    nGame.setModal(false);
    nGame.exec();
    //NewGame *nGame=new NewGame;
    //nGame->show();

}

void MainW::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::database("connection");

    this->gam=new QSqlQueryModel();
    gam->setQuery("select * from game;",db);
    ui->tableView->setModel(gam);

    //===выборка имен в вектор====================
    QSqlQuery nm;
    nm=db.exec("pragma table_info(game)");
    QVector<QString> lst;
    while (nm.next())
    {
        lst.push_back(nm.value(1).toString());
    }
    //QMessageBox::information(this,"",lst[0]+" "+lst[1]);
    //==========================


}
