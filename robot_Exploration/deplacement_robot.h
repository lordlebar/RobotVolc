#ifndef DEPLACEMENT_ROBOT_H
#define DEPLACEMENT_ROBOT_H

#include <QObject>
#include <QWidget>
#include <QDebug>

#include "connexion_deconnexion.h"


class Deplacement_Robot : public QWidget
{
public:
    Deplacement_Robot(QWidget *parent = nullptr);
    ~Deplacement_Robot();

    void returnTrame(int valeur);
    QString Trame_Avancer;
    QString Trame_Reculer;
    QString Trame_Avancer_Droite;
    QString Trame_Avancer_Gauche;
    QString Trame_Reculer_Droite;
    QString Trame_Reculer_Gauche;
};

#endif // DEPLACEMENT_ROBOT_H
