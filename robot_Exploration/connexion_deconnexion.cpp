#include "connexion_deconnexion.h"
#include "pince_robot.h"
#include "widget.h"
#include "ui_widget.h"


Connexion_Deconnexion::Connexion_Deconnexion(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Construction de la connexion";

}

Connexion_Deconnexion::~Connexion_Deconnexion(){
    serial -> write(trame_Neutre.toLatin1());
    qDebug() << "Destruction Connexion ! ";
}

void Connexion_Deconnexion::Initialisation(){//------------------------Initialisation de la connexion
    serial = new QSerialPort(this);
    serial->setPortName("/dev/tty.URT1");  // test maison
    //serial->setPortName("/dev/tty.usbserial-AQ01BCNR"); // ls /dev/tty*  /dev/tty.usbserial-AQ01BCNR     /dev/tty.usbserial-DN01IW7N
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

bool Connexion_Deconnexion::Connexion(){ // ------------envoie des données Xbee de la connexion
    serial->open(QIODevice::ReadWrite);

    if(serial->isOpen() == true && TestConnexion == false){
        serial -> write(trame_Neutre.toLatin1());
        serial -> write("$P,H,050,'Hauteur Pince',*""\n"); // Initialisation de la Hauteur de la pince a 50%
        serial -> write("P,F,000,'Fermer la Pince',*"); // La pince est totalement ouverte
        qDebug() << trame_Neutre;
        qDebug() << "Connecter !";
        thread()->msleep(200);
        TestConnexion = true;
        connect(serial, SIGNAL(readyRead()),this,SLOT(serialReceived()));
        return true;
    }
    else{
        thread()->msleep(200);
        qDebug() << "Non Connecter !";
        serial->close();
        TestConnexion = false;
        return false;
    }
}

bool Connexion_Deconnexion::testConnexion(){
    serial->open(QIODevice::ReadWrite);

    if(serial->isOpen() == true){
        return true;
    }else{
        return false;
    }
}

void Widget::on_pushButton_Connection_clicked() // ----------------------------Bouton Connection
{
    if(newConnexion->Connexion() == true && TestConnexion == false){
        ui->lineEdit_Connecter->setText("Connecter !");
        ui->lineEdit_Connecter_Instruction->setText("Vous pouvez Piloter le robot !");
        ui->lineEdit_instruction->setText("$N,N,000,'Neutre',*\n");

        ui->label_geolocalisation->setText("Carte Fonctionnelle");
        view->load(QUrl("http://localhost:8888/RobotVolc/Robot_Live.php")); // local : http://localhost:8888/RobotVolc/Robot_Live.php
        view->show();                                             // Lycée : http://172.20.13.250:8081/Robot_Live.php
        ui->Local_Layout->addWidget(view);
        view->setMaximumSize(565,355);
        view->show();

        ui->pushButton_Connection->setText("Deconnexion");

        ui->pushButton_DemarrageVideo->show();

        ui->pushButton->show();

    }else{
        ui->lineEdit_Connecter->setText("Non Connecter !");
        ui->lineEdit_Connecter_Instruction->setText("Connecter un module de communication et cliquez sur Connexion !");

        //ui->pushButton_OuvrirFermer_Pince->setText("Fermer Pince (Attraper)");
        ui->lineEdit_instruction->setText(" ");
        ui->pushButton_Connection->setText("Connexion");

        ui->label_geolocalisation->setText("Robot non connecter ! Carte Non Fonctionnelle");

        view->load(QUrl("http://localhost:8888/RobotVolc/FailCarteIHM.php"));
        view->show();
        ui->Local_Layout->addWidget(view);
        view->setMaximumSize(565,355);
        view->show();

        ui->pushButton_DemarrageVideo->hide();

        ui->pushButton->hide();
        ui->pushButton_VoirNomSite->hide();
        ui->label_Nom_Site->setText(" ");

    }
}







