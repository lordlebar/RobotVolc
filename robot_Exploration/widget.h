#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QWebEngineView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <qsignalmapper.h>
#include <QSignalMapper>

#include "pince_robot.h"
#include "connexion_deconnexion.h"
#include "deplacement_robot.h"
#include "manette.h"
#include "tacquisitionvideo.h"
#include "identification.h"

#include <QtSql>
#include <QSqlDatabase>


QT_BEGIN_NAMESPACE
namespace Ui {  class Widget;}
QT_END_NAMESPACE

//class TAcquisitionVideo;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    void Affichage_Trame_Manettes();


private slots:
    //----------------------------------------------------Different style de page
    void on_pushButton_Envoyer_Color_black_clicked();
    void on_pushButton_Envoyer_Color_white_clicked();
    void on_pushButton_Envoyer_Color_blue_clicked();
    void on_pushButton_Envoyer_Color_rouge_clicked();
    void on_pushButton_Envoyer_Color_Base_clicked();


    //--------------------------------------------------------------------------------------Connexion avec le Robot
    void on_pushButton_Connection_clicked(); // Connection/Deconnexion


    //-----------------------------------------------------------------------------------------------Pince du Robot
    //void on_pushButton_OuvrirFermer_Pince_clicked(); // etat de l'ouverture et fermeture pince pince
    void on_verticalSlider_Hauteur_Pince_valueChanged(int value); //etat Hauteur de la pince
    void on_horizontalSliderFermeturePince_valueChanged(int valueF); //etat fermeture de la pince


    //-----------------------------------------------------------------------------------------Déplacement du Robot
    void Slider_Direction();
    void Bouton_Relache();

    void on_pushButton_Direction_Avancer_pressed(); // Avancer
    void on_pushButton_Direction_Avancer_released();// Avancer relacher

    void on_pushButton_Direction_Reculer_pressed(); // Reculer
    void on_pushButton_Direction_Reculer_released(); // Reculer relacher

    bool on_checkBox_Reculer_Gauche_stateChanged(int arg1); // Avancer / Reculer vers la gauche
    void on_pushButton_Direction_Gauche_pressed(); // Gauche
    void on_pushButton_Direction_Gauche_released(); // Gauche relacher

    bool on_checkBox_Reculer_Droite_stateChanged(int arg1); // Avancer / Reculer vers la droite
    void on_pushButton_Direction_Droite_pressed(); // Droite
    void on_pushButton_Direction_Droite_released(); // Droite relacher


    //-----------------------------------------------------------------------------------------CheckPoint
    void on_pushButton_Checkpoint_clicked();

    //--------------------------------identification
    void on_pushButton_clicked();

    //---------------------------------------------Démarrarer vidéo camera
    void on_pushButton_DemarrageVideo_clicked();

    //------------------------------------------voir le nom du pilote et le site d'expedition
    void on_pushButton_VoirNomSite_clicked();

    //---------------------------------------------------Timer Carte robot
    void TimerSlot();

    //--------------------------------------------------Recupération action Manettes
    int lireManette(int Element ,int Num,int Valeur);
    void Slider_Vitesse_Manette(int ValeurVitesse);

private:
    Ui::Widget *ui;


    //--------------------------------------------------------------------------------------Connexion avec le Robot
    Connexion_Deconnexion *newConnexion;
    bool TestConnexion = false;


    //-----------------------------------------------------------------------------------------Pince du Robot
    Pince_Robot *newPince;
    bool test = false;
    QString Valeur_hauteur_QStr;
    QString Valeur_Fermeture_QStr;


    //-----------------------------------------------------------------------------------------Déplacement du Robot
    Deplacement_Robot *newDeplacement;
    int Slider_vitesse;
    QString VitesseSlider;
    bool ReculerGauche;
    bool ReculerDroite;

    int Slider_vitesseManette;
    QString VitesseSliderManette;
    int Vitesse;

    //---------------------------------------Joystick
    Manette *newJoystick;


    //------------------------------Affichage de la Maps
    QWebEngineView *view;


    //--------------------------------------Bse de données
    QSqlDatabase db;
    int ID_WayPoint;
    int ID_Camp;


    //--------------------------------------Identification Pilote et site
    Identification *newIdentification;


    //--------------------------------------Camera
    TAcquisitionVideo *mOpenCV_videoCapture;

    //--------------------------------Démarrage timer ( MAPS.php)
    QTimer *montimer;

    bool Inverser;
    int VitesseGD;


};
#endif // WIDGET_H


