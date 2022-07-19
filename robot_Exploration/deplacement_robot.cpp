#include "deplacement_robot.h"

#include "widget.h"
#include "ui_widget.h"
#include "connexion_deconnexion.h"


Deplacement_Robot::Deplacement_Robot(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Construction deplacement !";
}

Deplacement_Robot::~Deplacement_Robot()
{
    qDebug() << "Destruction deplacement !";
}

void Deplacement_Robot::returnTrame(int valeur)
{
    QString ValeurVitesse = QString::number(valeur);

    if(valeur >= 100)
    {
        Trame_Avancer = "$A,F," + ValeurVitesse +",'Avancer vers l'Avant',*""\n";
        Trame_Reculer ="$R,F," + ValeurVitesse +",'Reculer vers l'Arriere',*""\n";
        Trame_Avancer_Droite = "$A,D," + ValeurVitesse +",'Avancer vers la Droite',*""\n";
        Trame_Avancer_Gauche = "$A,G," + ValeurVitesse +",'Avancer vers la Gauche',*" "\n";
        Trame_Reculer_Droite = "$R,D," + ValeurVitesse +",'Reculer vers la Droite',*""\n";
        Trame_Reculer_Gauche = "$R,G," + ValeurVitesse +",'Reculer vers la Gauche',*" "\n";
    }
    else if(valeur < 100 && valeur >= 10)
    {
        Trame_Avancer = "$A,F,0" + ValeurVitesse +",'Avancer vers l'Avant',*""\n";
        Trame_Reculer ="$R,F,0" + ValeurVitesse +",'Reculer vers l'Arriere',*""\n";
        Trame_Avancer_Droite = "$A,D,0" + ValeurVitesse +",'Avancer vers la Droite',*""\n";
        Trame_Avancer_Gauche = "$A,G,0" + ValeurVitesse +",'Avancer vers la Gauche',*" "\n";
        Trame_Reculer_Droite = "$R,D,0" + ValeurVitesse +",'Reculer vers la Droite',*""\n";
        Trame_Reculer_Gauche = "$R,G,0" + ValeurVitesse +",'Reculer vers la Gauche',*" "\n";
    }
    else
    {
        Trame_Avancer = "$A,F,00" + ValeurVitesse +",'Avancer vers l'Avant',*""\n";
        Trame_Reculer = "$R,F,00" + ValeurVitesse +",'Reculer vers l'Arriere',*""\n";
        Trame_Avancer_Droite = "$A,D,00" + ValeurVitesse +",'Avancer vers la Droite',*""\n";
        Trame_Avancer_Gauche = "$A,G,00" + ValeurVitesse +",'Avancer vers la Gauche',*" "\n";
        Trame_Reculer_Droite = "$R,D,00" + ValeurVitesse +",'Reculer vers la Droite',*""\n";
        Trame_Reculer_Gauche = "$R,G,00" + ValeurVitesse +",'Reculer vers la Gauche',*" "\n";
    }
}



bool Connexion_Deconnexion::AppuiBtnDirection(int valeur)
{
    serial->open(QIODevice::ReadWrite);
    QString Valeur_Vitesse = QString::number(valeur);


    if(TestConnexion == true && serial->isOpen() == true)
    {
        if(valeur >= 100){
            Trame_Avancer = "$A,F," + Valeur_Vitesse +",'Avancer vers l'Avant',*""\n";
            Trame_Reculer ="$R,F," + Valeur_Vitesse +",'Reculer vers l'Arriere',*""\n";
            Trame_Avancer_Droite = "$A,D," + Valeur_Vitesse +",'Avancer vers la Droite',*""\n";
            Trame_Avancer_Gauche = "$A,G," + Valeur_Vitesse +",'Avancer vers la Gauche',*" "\n";
            Trame_Reculer_Droite = "$R,D," + Valeur_Vitesse +",'Reculer vers la Droite',*""\n";
            Trame_Reculer_Gauche = "$R,G," + Valeur_Vitesse +",'Reculer vers la Gauche',*" "\n";
        }
        else if(valeur < 100 && valeur >= 10)
        {
            Trame_Avancer = "$A,F,0" + Valeur_Vitesse +",'Avancer vers l'Avant',*""\n";
            Trame_Reculer ="$R,F,0" + Valeur_Vitesse +",'Reculer vers l'Arriere',*""\n";
            Trame_Avancer_Droite = "$A,D,0" + Valeur_Vitesse +",'Avancer vers la Droite',*""\n";
            Trame_Avancer_Gauche = "$A,G,0" + Valeur_Vitesse +",'Avancer vers la Gauche',*" "\n";
            Trame_Reculer_Droite = "$R,D,0" + Valeur_Vitesse +",'Reculer vers la Droite',*""\n";
            Trame_Reculer_Gauche = "$R,G,0" + Valeur_Vitesse +",'Reculer vers la Gauche',*" "\n";
        }
        else
        {
            Trame_Avancer = "$A,F,00" + Valeur_Vitesse +",'Avancer vers l'Avant',*""\n";
            Trame_Reculer ="$R,F,00" + Valeur_Vitesse +",'Reculer vers l'Arriere',*""\n";
            Trame_Avancer_Droite = "$A,D,00" + Valeur_Vitesse +",'Avancer vers la Droite',*""\n";
            Trame_Avancer_Gauche = "$A,G,00" + Valeur_Vitesse +",'Avancer vers la Gauche',*" "\n";
            Trame_Reculer_Droite = "$R,D,00" + Valeur_Vitesse +",'Reculer vers la Droite',*""\n";
            Trame_Reculer_Gauche = "$R,G,00" + Valeur_Vitesse +",'Reculer vers la Gauche',*" "\n";
        }
        return true;
    }
    else
    {
        return false;
    }

}
bool Connexion_Deconnexion::BtnRelache(){
    if(TestConnexion == true && serial->isOpen() == true){
        serial -> write(trame_Neutre.toLatin1());// N pour neutre le robot n'avance pas
        qDebug() << trame_Neutre;
        return true;
    }else{
        return false;
    }
}



void Widget::Slider_Direction()
{
    Slider_vitesse = ui->horizontalSlider_Vitesse->value();
    VitesseSlider = QString::number(Slider_vitesse);
    newDeplacement->returnTrame(Slider_vitesse);
    newConnexion->AppuiBtnDirection(Slider_vitesse);
    if(Slider_vitesse < 100 && newConnexion->AppuiBtnDirection(Slider_vitesse) == false)
    {
        ui->lineEdit_instruction-> setText("");
    }
}


void Widget::Bouton_Relache()
{
    if(newConnexion->BtnRelache() == true){
        ui->lineEdit_instruction-> setText("$N,N,000,'Neutre',*\n");
    }
}

//---------------------------------------------------------------------------Avancer

bool Connexion_Deconnexion::Avancer()
{
    serial->open(QIODevice::ReadWrite);

    if(TestConnexion == true && serial->isOpen() == true)
    {
        serial->write(Trame_Avancer.toLatin1());
        qDebug() << Trame_Avancer;

        return true;
    }
    else
    {
        return false;
    }
}

void Widget::on_pushButton_Direction_Avancer_pressed()
{
    Slider_Direction();
    if(newConnexion->Avancer() == true){
        ui->lineEdit_instruction-> setText(newDeplacement->Trame_Avancer);
    }
}
void Widget::on_pushButton_Direction_Avancer_released()
{
    Bouton_Relache();
}

//---------------------------------------------------------------------------Reculer

bool Connexion_Deconnexion::Reculer()
{
    serial->open(QIODevice::ReadWrite);

    if(TestConnexion == true && serial->isOpen() == true)
    {
        serial->write(Trame_Reculer.toLatin1());
        qDebug() << Trame_Reculer;
        return true;
    }
    else
    {
        return false;
    }
}

void Widget::on_pushButton_Direction_Reculer_pressed()
{
    Slider_Direction();
    if(newConnexion->Reculer() == true){
        ui->lineEdit_instruction-> setText(newDeplacement->Trame_Reculer);
    }
}
void Widget::on_pushButton_Direction_Reculer_released()
{
    Bouton_Relache();
}

//---------------------------------------------------------------------------Aller à Gauche

bool Connexion_Deconnexion::Avancer_Gauche()
{
    serial->open(QIODevice::ReadWrite);

    if(TestConnexion == true && serial->isOpen() == true)
    {
        serial->write(Trame_Avancer_Gauche.toLatin1());
        qDebug() << Trame_Avancer_Gauche;
        return true;
    }
    else
    {
        return false;
    }
}

bool Connexion_Deconnexion::Reculer_Gauche()
{
    serial->open(QIODevice::ReadWrite);

    if(TestConnexion == true && serial->isOpen() == true)
    {
        serial->write(Trame_Reculer_Gauche.toLatin1());
        qDebug() << Trame_Reculer_Gauche;
        return true;
    }
    else
    {
        return false;
    }
}

bool Widget::on_checkBox_Reculer_Gauche_stateChanged(int arg1)
{
    if(arg1 == 2){
        //qDebug() << arg1;
        ReculerGauche = true;
        return ReculerGauche;
    }else{
        //qDebug() << arg1;
        ReculerGauche = false;
        return ReculerGauche;
    }
}

void Widget::on_pushButton_Direction_Gauche_pressed()
{
    Slider_Direction();
    if(ReculerGauche == false && newConnexion->Avancer_Gauche() == true){
        //newConnexion->Avancer_Gauche();
        ui->lineEdit_instruction-> setText(newDeplacement->Trame_Avancer_Gauche);
    }else if(ReculerGauche == true && newConnexion->Reculer_Gauche() == true){
        ui->lineEdit_instruction-> setText(newDeplacement->Trame_Reculer_Gauche);
        //newConnexion->Reculer_Gauche();
    }
}
void Widget::on_pushButton_Direction_Gauche_released()
{
    Bouton_Relache();
}

//---------------------------------------------------------------------------Aller à Droite
bool Connexion_Deconnexion::Avancer_Droite()
{
    serial->open(QIODevice::ReadWrite);

    if(TestConnexion == true && serial->isOpen() == true)
    {
        serial->write(Trame_Avancer_Droite.toLatin1());
        qDebug() << Trame_Avancer_Droite;
        return true;
    }
    else
    {
        return false;
    }
}

bool Connexion_Deconnexion::Reculer_Droite()
{
    serial->open(QIODevice::ReadWrite);

    if(TestConnexion == true && serial->isOpen() == true)
    {
        serial->write(Trame_Reculer_Droite.toLatin1());
        qDebug() << Trame_Reculer_Droite;
        return true;
    }
    else
    {
        return false;
    }
}

bool Widget::on_checkBox_Reculer_Droite_stateChanged(int arg1)
{
    if(arg1 == 2){
        ReculerDroite = true;
        return ReculerDroite;
    }else{
        ReculerDroite = false;
        return ReculerDroite;
    }
}

void Widget::on_pushButton_Direction_Droite_pressed()
{
    Slider_Direction();
    if( ReculerDroite == false && newConnexion->Avancer_Droite() == true){
        ui->lineEdit_instruction-> setText(newDeplacement->Trame_Avancer_Droite);
    }
    else if(  ReculerDroite == true && newConnexion->Reculer_Droite() == true){
        ui->lineEdit_instruction-> setText(newDeplacement->Trame_Reculer_Droite);
    }
}
void Widget::on_pushButton_Direction_Droite_released()
{
    Bouton_Relache();
}
