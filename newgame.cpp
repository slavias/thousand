#include "newgame.h"
#include "ui_newgame.h"
#include "sql_heads.h"

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
    //====HIDE!!!===================
    ui->label_3->hide();
    ui->le_pl_3->hide();
    ui->label_4->hide();
    ui->le_pl_4->hide();
    ui->label_5->hide();
    ui->le_pl_5->hide();
    ui->label_6->hide();
    ui->le_pl_6->hide();
    ui->label_7->hide();
    ui->le_pl_7->hide();
    ui->label_8->hide();
    ui->le_pl_8->hide();
    ui->label_9->hide();
    ui->le_pl_9->hide();
    ui->label_10->hide();
    ui->le_pl_10->hide();

}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_OK_clicked()
{
    //===fill list name==============
    QVector<QString> name;
    name.push_back(ui->le_pl_1->text());
    name.push_back(ui->le_pl_2->text());
    name.push_back(ui->le_pl_3->text());
    name.push_back(ui->le_pl_4->text());
    name.push_back(ui->le_pl_5->text());
    name.push_back(ui->le_pl_6->text());
    name.push_back(ui->le_pl_7->text());
    name.push_back(ui->le_pl_8->text());
    name.push_back(ui->le_pl_9->text());
    name.push_back(ui->le_pl_10->text());
    name.push_back("");
    //===========================
    if(name[1].isEmpty()){
        QMessageBox::information(this,"error","введите пожалуйста не меньше двух игроков");
        return;
    }
    //===============================

    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE","connection");
    db.setDatabaseName("1000.db");
    if (!db.open())    {
        QMessageBox::critical(this,"fuck!!!",db.lastError().text());
    }
    //======================

    db.exec("create table game (id int, name text, point int);");
    int i=1;
    QString temp;
    while (!name[i-1].isEmpty())    {
        temp="insert into game values("+QString::number(i)+", '"+name[i-1]+"', 0);";
        db.exec (temp);
        i++;
    }

    this->close();

}

void NewGame::on_le_pl_2_textEdited(const QString &arg1)
{
    ui->label_3->setVisible(true);
    ui->le_pl_3->setVisible(true);
    if(ui->le_pl_2->text().size()==0){
        ui->label_3->hide();
        ui->le_pl_3->hide();
    }
}

void NewGame::on_le_pl_3_textEdited(const QString &arg1)
{
    ui->label_4->setVisible(true);
    ui->le_pl_4->setVisible(true);
    if(ui->le_pl_3->text().size()==0){
        ui->label_4->hide();
        ui->le_pl_5->hide();
    }
}

void NewGame::on_le_pl_4_textEdited(const QString &arg1)
{
    ui->label_5->setVisible(true);
    ui->le_pl_5->setVisible(true);
    if(ui->le_pl_4->text().size()==0){
        ui->label_5->hide();
        ui->le_pl_5->hide();
    }
}

void NewGame::on_le_pl_5_textEdited(const QString &arg1)
{
    ui->label_6->setVisible(true);
    ui->le_pl_6->setVisible(true);
    if(ui->le_pl_5->text().size()==0){
        ui->label_6->hide();
        ui->le_pl_6->hide();
    }
}

void NewGame::on_le_pl_6_textEdited(const QString &arg1)
{
    ui->label_7->setVisible(true);
    ui->le_pl_7->setVisible(true);
    if(ui->le_pl_6->text().size()==0){
        ui->label_7->hide();
        ui->le_pl_7->hide();
    }
}

void NewGame::on_le_pl_7_textEdited(const QString &arg1)
{
    ui->label_8->setVisible(true);
    ui->le_pl_8->setVisible(true);
    if(ui->le_pl_7->text().size()==0){
        ui->label_8->hide();
        ui->le_pl_8->hide();

    }
}

void NewGame::on_le_pl_8_textEdited(const QString &arg1)
{
    ui->label_9->setVisible(true);
    ui->le_pl_9->setVisible(true);
    if(ui->le_pl_8->text().size()==0){
        ui->label_9->hide();
        ui->le_pl_9->hide();

    }
}

void NewGame::on_le_pl_9_textEdited(const QString &arg1)
{
    ui->label_10->setVisible(true);
    ui->le_pl_10->setVisible(true);
    if(ui->le_pl_9->text().size()==0){
        ui->label_10->hide();
        ui->le_pl_10->hide();
    }
}
