#ifndef PINCE_ROBOT_H
#define PINCE_ROBOT_H

#include <QObject>
#include <QWidget>
#include <QDebug>

#include "connexion_deconnexion.h"


class Pince_Robot : public QWidget
{
public:
    Pince_Robot(QWidget *parent = nullptr);
    ~Pince_Robot();
//    QString OuvrirPince();
//    QString FermerPince();
    QString fermerpince();
    QString hauteurPince();

private:
    QString Trame_Ouvrir_pince = "$P,O,100,'Ouvrir la Pince (Relacher l'objet)',*""\n";
    QString Trame_Fermer_Pince = "$P,F,000,'Fermer la Pince (Attraper l'objet)',*""\n";
    bool OuvrirFermer = true;
};

#endif // PINCE_ROBOT_H
