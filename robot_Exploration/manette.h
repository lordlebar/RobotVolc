#ifndef MANETTE_H
#define MANETTE_H

#include <QThread>
#include <SDL.h>
#include <QByteArray>

#include "connexion_deconnexion.h"
#include "deplacement_robot.h"


// ELEMENT pour le type: 0->bouton, 1->axe, 2->hat
// NUM pour le numéro 0 à 14 pour les boutons  0 à 5 pour axes
// VALEUR pour valeur 1,0 pour appuyé ou relaché sur les boutons, -32768 à 32767 pour un axe; 1,2,4,8 pour action sur hat sinon 0 pour relacher

//enum ManetteCommandes
//{
//    BOUTON=0,
//    AXE=1,
//    HAT=2,
//    BOUTON_AUTORISER_DEPLACEMENT=5,
//    BOUTON_AUTORISER_PINCE=4,
//    AXE_DIRECTION=2,
//    AXE_SENS=5,
//    AXE_VITESSE=4,
//    AXE_BAISSER_PINCE=1,
//    AXE_FERMER_PINCE=3
//};

enum ManetteCommandes // manette PS4
{
    BOUTON=0,
    AXE=1,
    HAT=2,
    BOUTON_AUTORISER_DEPLACEMENT=5,
    BOUTON_AUTORISER_PINCE=4,
    AXE_DIRECTION=0,
    AXE_AVANCER=5,
    AXE_RECULER=4,
    //AXE_VITESSE=4,
    AXE_BAISSER_PINCE=3,
    AXE_FERMER_PINCE=2
};

enum ManetteCommandesPS3 // manette PS3
{
    BOUTON1=0,
    AXE1=1,
    HAT1=2,
    BOUTON_AUTORISER_DEPLACEMENT1=16,
    BOUTON_AUTORISER_PINCE1=0,
    AXE_DIRECTION1=0,
    BUTTON_AVANCER=9,
    BUTTON_RECULER=8,
    AXE_VITESSE=1,
    AXE_BAISSER_PINCE1=3,
    AXE_FERMER_PINCE1=2
};

class Manette : public QThread
{

    Q_OBJECT
public:
    Manette(QWidget *parent = nullptr);
    bool init();
    bool thread_abort;
    void returnTrameManettes(int valeur);

    QString Trame_AvancerManettes;
    QString Trame_ReculerManettes;
    QString Trame_Avancer_DroiteManettes;
    QString Trame_Avancer_GaucheManettes;
    QString Trame_Reculer_DroiteManettes;
    QString Trame_Reculer_GaucheManettes;


signals:
    void manetteAction(int element, int num, int valeur);
protected:
    void run() override;
private:
     SDL_Joystick *pJoystick=NULL;
     int element;
     int num;
     int valeur;
};


#endif // MANETTE_H
