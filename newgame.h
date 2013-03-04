#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>


namespace Ui {
class NewGame;
}

class NewGame : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewGame(QWidget *parent = 0);
    ~NewGame();
    
private slots:
    void on_OK_clicked();

    void on_le_pl_2_textEdited(const QString &arg1);
    void on_le_pl_3_textEdited(const QString &arg1);
    void on_le_pl_4_textEdited(const QString &arg1);
    void on_le_pl_5_textEdited(const QString &arg1);
    void on_le_pl_6_textEdited(const QString &arg1);
    void on_le_pl_7_textEdited(const QString &arg1);
    void on_le_pl_8_textEdited(const QString &arg1);
    void on_le_pl_9_textEdited(const QString &arg1);

private:
    Ui::NewGame *ui;
};

#endif // NEWGAME_H
