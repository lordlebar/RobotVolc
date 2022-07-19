#ifndef CONNEXION_DECONNEXION_H
#define CONNEXION_DECONNEXION_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "pince_robot.h"


class Connexion_Deconnexion : public QWidget
{
    Q_OBJECT
public:
     Connexion_Deconnexion(QWidget *parent = 0);
    ~Connexion_Deconnexion();
    void Initialisation();
//    bool OuvrirPince();
//    bool FermerPince();
    bool FermeturePince(int valeurF);
    bool HauteurPince(int valeur);

    bool Connexion();
    bool testConnexion();

    //----------------------envoie des trames
    bool Avancer();
    bool Reculer();
    bool Avancer_Droite();
    bool Avancer_Gauche();
    bool Reculer_Droite();
    bool Reculer_Gauche();

    bool AppuiBtnDirection(int valeur);
    bool BtnRelache();


//    bool AvancerManettes();
//    bool ReculerManettes();
//    bool Avancer_DroiteManettes();
//    bool Avancer_GaucheManettes();
//    bool Reculer_DroiteManettes();
//    bool Reculer_GaucheManettes();

//    bool AppuiBtnJoystick(int valueV);


    //--------------------Chekpoint
    void liredonne();
    QString latiS, longiS, date, heure;
    float lati, longi;
    QStringList list;
    QString Trame_Complete;
    QString Trame_Split;


private:
    bool TestConnexion = false; //vérifier l'etat de la connexion... soit vrai soit fausse.
    QSerialPort *serial;
    //QString Trame_Ouvrir_Pince = "$P,O,100,'Ouvrir la Pince (Relacher l'objet)',*""\n";
    //QString Trame_Fermer_Pince = "$P,F,000,'Fermer la Pince (Attraper l'objet)',*""\n";

    QString trame_Neutre = "$N,N,000,'Neutre (Le robot ne bouge pas)',*""\n";

    //-------------------------------------Pilotage IHM
    QString Trame_Avancer;
    QString Trame_Reculer;
    QString Trame_Avancer_Droite;
    QString Trame_Avancer_Gauche;
    QString Trame_Reculer_Droite;
    QString Trame_Reculer_Gauche;

//-------------------------------------Pilotage Manettes
    QString Trame_AvancerManettes;
    QString Trame_ReculerManettes;
    QString Trame_Avancer_DroiteManettes;
    QString Trame_Avancer_GaucheManettes;
    QString Trame_Reculer_DroiteManettes;
    QString Trame_Reculer_GaucheManettes;

    QString Trame_PinceManettes;
};

#endif // CONNEXION_DECONNEXION_H
