#include "pince_robot.h"
#include "connexion_deconnexion.h"
#include "widget.h"
#include "ui_widget.h"

Pince_Robot::Pince_Robot(QWidget *parent) : QWidget(parent){
    qDebug() << "Construction de la pince";
}


Pince_Robot::~Pince_Robot(){
    qDebug() << "Destruction de la pince";
}

//QString Pince_Robot::OuvrirPince(){
//    return Trame_Ouvrir_pince;
//}

//QString Pince_Robot::FermerPince(){
//    return Trame_Fermer_Pince;
//}

// // --------------------------------------------------envoie des données Xbee si la pince est utilisé---------------------//

//bool Connexion_Deconnexion::OuvrirPince()
//{
//    serial->open(QIODevice::ReadWrite);

//    if(TestConnexion == true && serial->isOpen() == true)
//    {
//        serial->write(Trame_Ouvrir_Pince.toLatin1());
//        qDebug() << Trame_Ouvrir_Pince;
//        return true;
//    }
//    else
//    {
//        return false;
//    }

//}
//bool Connexion_Deconnexion::FermerPince()
//{
//    serial->open(QIODevice::ReadWrite);

//    if(TestConnexion == true && serial->isOpen() == true)
//    {
//        serial->write(Trame_Fermer_Pince.toLatin1());
//        qDebug() << Trame_Fermer_Pince;
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

bool Connexion_Deconnexion::FermeturePince(int valeurF)
{
    serial->open(QIODevice::ReadWrite);

    QString Valeur_Fermeture_QStr = QString::number(valeurF);
    QString Trame_Fermeture_Pince;

    if(TestConnexion == true && serial->isOpen() == true)
    {
        if(valeurF >= 100){
            Trame_Fermeture_Pince = "$F,P," + Valeur_Fermeture_QStr +",'Fermer Pince',*""\n";
        }
        else if(valeurF < 100 && valeurF >= 10)
        {
            Trame_Fermeture_Pince = "$F,P,0" + Valeur_Fermeture_QStr +",'Fermer Pince',*""\n";
        }
        else
        {
            Trame_Fermeture_Pince = "$F,P,00" + Valeur_Fermeture_QStr +",'Fermer Pince',*""\n";
        }

        serial->write(Trame_Fermeture_Pince.toLatin1());
        qDebug() << Trame_Fermeture_Pince;
        return true;
    }
    else
    {
        return false;
    }
}


bool Connexion_Deconnexion::HauteurPince(int valeur)
{
    serial->open(QIODevice::ReadWrite);

    QString Valeur_hauteur_QStr = QString::number(valeur);
    QString Trame_Hauteur_Pince;

    if(TestConnexion == true && serial->isOpen() == true)
    {
        if(valeur >= 100){
            Trame_Hauteur_Pince = "$P,H," + Valeur_hauteur_QStr +",'Hauteur Pince',*""\n";
        }
        else if(valeur < 100 && valeur >= 10)
        {
            Trame_Hauteur_Pince = "$P,H,0" + Valeur_hauteur_QStr +",'Hauteur Pince',*""\n";
        }
        else
        {
            Trame_Hauteur_Pince = "$P,H,00" + Valeur_hauteur_QStr +",'Hauteur Pince',*""\n";
        }

        serial->write(Trame_Hauteur_Pince.toLatin1());
        qDebug() << Trame_Hauteur_Pince;
        return true;
    }
    else
    {
        return false;
    }
}

// -----------------------------------------------Fin envoie des données Xbee si la pince est utilisé--------------------//


// -----------------------------------------------Affichage des données Vérifier sur l'IHM--------------------//

//void Widget::on_pushButton_OuvrirFermer_Pince_clicked()
//{
//    thread()->msleep(200);
//    if(test == true && newConnexion->OuvrirPince() == true )
//    {
//        ui->lineEdit_instruction->setText(newPince->OuvrirPince());
//        ui->pushButton_OuvrirFermer_Pince->setText("Fermer la Pince ( Attraper )");
//        test = false;
//    }
//    else if(test == false && newConnexion->FermerPince() == true)
//    {
//        ui->lineEdit_instruction->setText(newPince->FermerPince());
//        ui->pushButton_OuvrirFermer_Pince->setText("Ouvrir la Pince ( Relacher )");
//        test = true;
//    }
//    else
//    {
//        ui->lineEdit_instruction->setText("");
//    }
//}

void Widget::on_horizontalSliderFermeturePince_valueChanged(int valueF)
{
    if(valueF <= 100 && newConnexion->FermeturePince(valueF) == true)
    {
        Valeur_Fermeture_QStr = QString::number(valueF);
        qDebug() << Valeur_Fermeture_QStr;
        if(valueF >= 100 ){
            QString Trame_Fermeture_Pince = "$F,P," + Valeur_Fermeture_QStr +",'Fermer Pince',*""\n";
            ui->lineEdit_instruction-> setText(Trame_Fermeture_Pince);
        }
        else if(valueF < 100 && valueF >= 10)
        {
            QString Trame_Fermeture_Pince = "$F,P,0" + Valeur_Fermeture_QStr +",'Fermer Pince',*""\n";
            ui->lineEdit_instruction-> setText(Trame_Fermeture_Pince);
        }
        else
        {
            QString Trame_Fermeture_Pince = "$F,P,00" + Valeur_Fermeture_QStr +",'Fermer Pince',*""\n";
            ui->lineEdit_instruction-> setText(Trame_Fermeture_Pince);
        }
    }
    else
    {
        ui->lineEdit_instruction-> setText("");
    }

}


void Widget::on_verticalSlider_Hauteur_Pince_valueChanged(int value)
{
    if(value <= 100 && newConnexion->HauteurPince(value) == true)
    {
        Valeur_hauteur_QStr = QString::number(value);
        qDebug() << Valeur_hauteur_QStr;
        if(value >= 100 ){
            QString Trame_Hauteur_Pince = "$P,H," + Valeur_hauteur_QStr +",'Hauteur Pince',*""\n";
            ui->lineEdit_instruction-> setText(Trame_Hauteur_Pince);
        }
        else if(value < 100 && value >= 10)
        {
            QString Trame_Hauteur_Pince = "$P,H,0" + Valeur_hauteur_QStr +",'Hauteur Pince',*""\n";
            ui->lineEdit_instruction-> setText(Trame_Hauteur_Pince);
        }
        else
        {
            QString Trame_Hauteur_Pince = "$P,H,00" + Valeur_hauteur_QStr +",'Hauteur Pince',*""\n";
            ui->lineEdit_instruction-> setText(Trame_Hauteur_Pince);
        }
    }
    else
    {
        ui->lineEdit_instruction-> setText("");
    }
}

// -----------------------------------------------Fin Affichage des données Vérifier sur l'IHM--------------------//
