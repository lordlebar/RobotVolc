#include "identification.h"
#include "ui_identification.h"
#include "widget.h"
#include "ui_widget.h"


Identification::Identification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Identification)
{
    ui->setupUi(this);

}

Identification::~Identification()
{
    delete ui;
}

bool Identification::on_pushButton_valider_clicked()
{
    NomPilote = ui->lineEdit->text();
    QSite = ui->lineEdit_2->text();

    if(NomPilote != "" && QSite != ""){
        QSqlQuery query;
        query.prepare("INSERT INTO `campagnes` (`pilote`, `site`) "                             // Pour remettre autoIncremente a 1 :
                      "VALUES (:pilote, :site)");                                           //ALTER TABLE campagnes AUTO_INCREMENT=1
        query.bindValue(":pilote", NomPilote );
        query.bindValue(":site", QSite );
        query.exec();
        if(!query.exec())
        {
            ui->lineEdit_Etat->setText("Requete Non Effectué, Réessayer...");
        }else{
            ui->lineEdit_Etat->setText("Requete Effectué, Vous pouvez fermer cette page...");
            affichage = "Nom pilote : "+ NomPilote + " , " + "  Site : " + QSite;
        }
        return true;
    }
    else{
        ui->lineEdit_Etat->setText("Nom ou Site non accepter.");
        return false;
    }

    connect(ui->pushButton_valider, SIGNAL(clicked()), window(), SLOT(close()));

}


void Widget::on_pushButton_clicked()
{
    newIdentification->show();

    ui->pushButton->hide();
    ui->pushButton_VoirNomSite->show();

}


void Widget::on_pushButton_VoirNomSite_clicked()
{
    QString Nom_pilote = newIdentification->NomPilote;
    QString Site = newIdentification->QSite;
    if(newIdentification->on_pushButton_valider_clicked() == true)
    {
        ui->label_Nom_Site->setText(newIdentification->affichage);
        ui->pushButton_VoirNomSite->hide();
        ui->lineEdit_Connecter-> setText("Connecter et Loguer");
    }

}

