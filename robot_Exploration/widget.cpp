#include "widget.h"
#include "ui_widget.h"
#include "identification.h"
#include "ui_identification.h"
#include "connexion_deconnexion.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_pushButton_Envoyer_Color_Base_clicked();

    //-------------------------------------------------construit une nouvelle connexion
    newConnexion = new Connexion_Deconnexion();
    newConnexion->Initialisation();

    //----------------------------------Cette fonction permet de se deconnecter ou de se connecter et Carte Geolocalisation
    view = new QWebEngineView();
    on_pushButton_Connection_clicked();

    //----------------------------------------------Construction de la Pince
    newPince = new Pince_Robot();
    //on_pushButton_OuvrirFermer_Pince_clicked();
    connect(ui->verticalSlider_Hauteur_Pince,SIGNAL(valueChanged(int)),ui->label_Hauteur_Pince,SLOT(setNum(int)));//Hauteur Pince
    connect(ui->horizontalSliderFermeturePince,SIGNAL(valueChanged(int)),ui->label_4,SLOT(setNum(int)));//Fermer Pince

    //------------------------------------------------construction deplacement robot
    newDeplacement = new Deplacement_Robot();
    connect(ui->horizontalSlider_Vitesse,SIGNAL(valueChanged(int)),ui->label_Vitesse,SLOT(setNum(int)));//Vitesse

    //------------------------------------------------Joystick en arriere plan Thread
    newJoystick = new Manette(this);

    if(newJoystick->init() == true){
        newJoystick -> start();
        qDebug() << "manettes connecter !";
        connect(newJoystick,SIGNAL(manetteAction(int ,int ,int)), this, SLOT(lireManette(int ,int ,int)));
    }
    else
    {
        delete newJoystick;
        newJoystick = NULL;
        qDebug() << "manettes detruite car non connecter !";

    }


    //------------------------------------------------Camera en arriere plan Thread OpenCV
    mOpenCV_videoCapture = new TAcquisitionVideo(this);
    connect(mOpenCV_videoCapture, &TAcquisitionVideo::newPixmapCaptured,this , [&]()
    {
        QPixmap tailleVideo = mOpenCV_videoCapture->Pixmap().scaled(591,381);
        ui->OpenCvFrame->setPixmap(tailleVideo);
    });


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("RobotVolc"); // local : RobotVolc  // lycée : site1
    db.setHostName("127.0.0.1"); // Local : 127.0.0.1 ou localhost // au lycée : 172.20.13.250
    db.setPort(8889); // Local : 8889 // lycée : 3306 ou 8081
    db.setUserName("AdminRobot"); // Local : AdminRobot // local : root // Lycée : etudiant1
    db.setPassword(""); // Local :     // Local : root // Lycée : 1234


    if(db.open())
    {
        qDebug() << " ok ";
        ui->lineEdit_connecte_BDD_2->setText("BDD C"); // Connecté
    }
    else
    {
        ui->lineEdit_connecte_BDD_2->setText("BDD N C"); // non Connecté
        qDebug() << db.lastError();
    }

    newIdentification = new Identification();

    ui->pushButton_VoirNomSite->hide();

    //----------------------------------------------------Réception des trames pour dans la table robotlive
    montimer = new QTimer;
    connect(montimer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    montimer -> start(5000);

}

Widget::~Widget()
{
//    mOpenCV_videoCapture -> extinction = true;
//    newJoystick -> thread_abort = true;
    delete mOpenCV_videoCapture;
    delete newJoystick;
    delete montimer;
    qDebug() << "destruction de la fenetre";
    delete ui;

}


void Widget::TimerSlot()
{
    newConnexion->liredonne();

    QString requete = "UPDATE `robotlive` SET `Longitude` = " + newConnexion->longiS + ", `Latitude` = " + newConnexion->latiS;
    //UPDATE `robotlive` SET `Longitude`= 0.789,`Latitude`= 10.789

    QSqlQuery query;
    query.prepare(requete);
    query.exec();

    if(!query.exec()){
        ui->lineEdit_Requete_Robot->setText(" R NE "); // Error Requete
    }
    else{
        ui->lineEdit_Requete_Robot->setText(" R E "); // Requete effectuer
    }
}



