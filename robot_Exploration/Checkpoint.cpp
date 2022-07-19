#include "widget.h"
#include "ui_widget.h"
#include "connexion_deconnexion.h"



void Connexion_Deconnexion::liredonne()
{
    //---------------------------Reception trame --------------------//
    QByteArray data;
    QString dataReponse;
    QStringList ligne;

    // ------------- Avec Module de communication radio (Xbee) --------- //
//    data += serial->readAll();
//    list = (QString(data)).split("\n");

//    for(int i = 0 ; i < list.size() ; i++)
//    {
//        // extraire données
//        ligne = list[i].split(',');
//        if(list[i].contains(','))      //if(ligne[0] == "$GPRMC" && list[i].contains('*'))
//            /* utilisation Trame GPRMC
//            * car cette trame possède toute les
//            * informations necessaires a notre base
//            * de données (latitude, longitude, date, heure)*/
//        {
//            latiS = ligne[0];// + ligne[3];
//            lati = latiS.toFloat();
//            longiS = ligne[1];// + ligne[4];
//            longi = longiS.toFloat();
//            heure = ligne[2];
//            date = ligne[3];

//            Trame_Complete =  latiS + " , " + longiS + "," + heure + ", " + date + " , ";
//            Trame_Split = "Lati : " + latiS + " , Longi :  " + longiS + " , H :  " + heure + " , D :  " + date;
//        }
//    }
//    if(data == ""){
//        Trame_Complete = "Pas de données envoyer !";
//        Trame_Split = "ou trame non recevable ! format des trames : 56,567.987,876.876,87";

//    }

    // ------------------- test sans module radio ------------ //
      latiS = "543";
      lati = latiS.toFloat();
      longiS = "783";
      longi = longiS.toFloat();
      heure = "10";
      date = "220521";

      Trame_Complete = latiS + " , " + longiS + "," + heure + ", " + date + " , ";
      Trame_Split = "Lati : " + latiS + " , Longi :  " + longiS + " , H :  " + heure + " , D :  " + date;


}

void Widget::on_pushButton_Checkpoint_clicked()
{
    thread()->msleep(200);
    newConnexion->liredonne();
    ui->lineEdit_trameGPS->setText(newConnexion->Trame_Complete);
    ui -> lineEdit_trameGPS_2 -> setText(newConnexion->Trame_Split);

    qDebug() << "Latitude : " + newConnexion->latiS;
    qDebug() << "longitude : " + newConnexion->longiS;


    /*partie Ben sauvegarde dans la base de données
     * et affichage sur la carte... */
    if("Latitude : " + newConnexion->latiS != "Latitude : "){
        ui->label_geolocalisation->setText("Carte Fonctionnelle");
        view->load(QUrl("http://localhost:8888/RobotVolc/Robot_Live.php")); // local : http://localhost:8888/Robot_Live.php
        view->show();                                             // Lycée : http://172.20.13.250:8081/Robot_Live.php
        ui->Local_Layout->addWidget(view);
        view->setMaximumSize(565,355);
        view->show();

        QSqlQuery query1;

        if(query1.exec("SELECT MAX(`idCAMPAGNES`) FROM `campagnes`")) {
            qDebug() << "Ok - requete";

            while(query1.next()) {
                ID_Camp = query1.value(0).toInt();
            }


            //        if(query1.exec("SELECT MAX(`idWAYPOINTS`) FROM `waypoints`"))
            //        {
            //            qDebug() << "Ok - requete";

            //            while(query1.next())
            //            {
            //                ID_WayPoint = query1.value(0).toInt();
            //            }
            //        }

            query1.prepare("INSERT INTO `waypoints` (`Latitude`, `Longitude`, CAMPAGNES_idCAMPAGNES) "
                           "VALUES (:lat, :long, :camp)");
            query1.bindValue(":lat", newConnexion->lati);
            query1.bindValue(":long", newConnexion->longi);
            query1.bindValue(":camp", ID_Camp);

            query1.exec();



            if(!query1.exec())
            {
                ui->lineEdit_instruction_2->setText("Requete trame Non Effectué");
            }
            else
            {
                ui->lineEdit_instruction_2->setText("Requete Trame Effectué");
            }
        }

    }
    else
    {
        qDebug() << "Latitude else: " + newConnexion->latiS;
        qDebug() << "longitude else: " + newConnexion->longiS;
    }

}

