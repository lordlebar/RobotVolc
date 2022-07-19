#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>


namespace Ui {
class Identification;
}

class Identification : public QWidget
{
    Q_OBJECT

public:
    explicit Identification(QWidget *parent = nullptr);
    ~Identification();
    QString NomPilote;
    QString QSite;
    QString affichage;

public slots:
    bool on_pushButton_valider_clicked();

private:
    Ui::Identification *ui;


};

#endif // IDENTIFICATION_H
