#include "manette.h"
#include "widget.h"
#include "ui_widget.h"
//https://alexandre-laurent.developpez.com/tutoriels/sdl/joysticks/
#include <QDebug>

Manette::Manette(QWidget *parent)
    : QThread(parent)
{

}

bool Manette::init()
{
    SDL_Init(SDL_INIT_JOYSTICK);
    pJoystick = SDL_JoystickOpen(0);
    if(pJoystick)
    {
        qDebug()<<"joystick ok";
        qDebug()<<"Informations du joystick";
        qDebug()<<"Nom : " << SDL_JoystickName(pJoystick);
        qDebug()<<"Nombre d'axes :"<< SDL_JoystickNumAxes(pJoystick);
        qDebug()<<"Nombre de boutons :" << SDL_JoystickNumButtons(pJoystick);
        SDL_JoystickEventState(SDL_ENABLE);
        return true;
    }
    else
    {
        qDebug()<<"manette non connectée";
        return false;
    }

}


void Manette::run()
{
    thread_abort=false;

    while (!thread_abort)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if ( event.type == SDL_JOYAXISMOTION )
            {
                // Mouvement d'un axe
                element = ManetteCommandes::AXE;
                num = event.jaxis.axis;
                valeur = event.jaxis.value / 320 ; //+ 102;
                //valeur /= 2;

                if (valeur > 10 || valeur < -10)
                {
                    qDebug() << "element : " << element << "num :" << num << "valeur :" << valeur << "\n";
                    emit manetteAction(element,num,valeur);
                }
            }
            else if ( event.type == SDL_JOYBUTTONDOWN || event.type == SDL_JOYBUTTONUP )
            {
                // Bouton appuyé ou relâché
                // Nous devons donc utiliser le champ jbutton
                if ( event.jbutton.state == SDL_PRESSED )
                {
                    element=ManetteCommandes::BOUTON;
                    num=event.jbutton.button;
                    valeur=1; //bouton appuyé
                    qDebug() << "element : " << element << "num :" << num  << "valeur :" << valeur << "\n";

                    emit manetteAction(element,num,valeur);
                }
                else if ( event.jbutton.state == SDL_RELEASED )
                {
                    element=ManetteCommandes::BOUTON;
                    num=event.jbutton.button;
                    valeur=0; //bouton relâché
                    qDebug() << "element : " << element << "num :" << num  << "valeur :" << valeur << "\n";

                    emit manetteAction(element,num,valeur);
                }
            }
        }
    }
}

void Widget::Slider_Vitesse_Manette(int ValeurVitesse)
{
    ValeurVitesse = Vitesse;
    qDebug() << "Vitesse Manette : " << Vitesse;
    VitesseSlider = QString::number(Vitesse);
    newDeplacement->returnTrame(Vitesse);
    newConnexion->AppuiBtnDirection(Vitesse);
    if(Vitesse < 100 && newConnexion->AppuiBtnDirection(Vitesse) == false)
    {
        ui->lineEdit_instruction-> setText("");
    }
}


int Widget::lireManette(int  Element, int  Num, int Valeur)
{
    Vitesse = Valeur;

    if(TestConnexion == false)
    {

        if(Vitesse > 100){
            Vitesse -= 2;
        }
        if(Vitesse < -100)
        {
            Vitesse += 2;
        }

        //--------------------------------------------------------Avancer
        if(Num == AXE_AVANCER && Element == AXE && Vitesse > -99)
        {
            Vitesse += 102;
            Vitesse /=2;
            Vitesse -= 1;
            Slider_Vitesse_Manette(Vitesse);
            if(newConnexion->Avancer() == true)
            {
                ui->lineEdit_instruction-> setText(newDeplacement->Trame_Avancer);
            }
            Inverser = true;
        }

        //--------------------------------------------------------Reculer
        if(Num == AXE_RECULER && Element == AXE && Vitesse > -99)
        {
            Vitesse += 102;
            Vitesse /=2;
            Vitesse -= 1;
            Slider_Vitesse_Manette(Vitesse);
            if(newConnexion->Reculer() == true)
            {
                ui->lineEdit_instruction-> setText(newDeplacement->Trame_Reculer);
            }
            Inverser = false;
        }

        //--------------------------------------------------------Avancer Droite
        if(Num == AXE_DIRECTION && Element == AXE && Vitesse > 10 && Inverser == true)
        {
            Slider_Vitesse_Manette(Vitesse);
            if(newConnexion->Avancer_Droite() == true)
            {
                ui->lineEdit_instruction-> setText(newDeplacement->Trame_Avancer_Droite);
            }
        }

        //--------------------------------------------------------Reculer Droite
        else if(Num == AXE_DIRECTION && Element == AXE && Vitesse > 10 && Inverser == false)
        {
            Slider_Vitesse_Manette(Vitesse);
            if(newConnexion->Reculer_Droite() == true)
            {
                ui->lineEdit_instruction-> setText(newDeplacement->Trame_Reculer_Droite);
            }
        }
        //--------------------------------------------------------Avancer Gauche
        if(Num == AXE_DIRECTION && Element == AXE && Vitesse < -10 && Inverser == true)
        {
            Vitesse *= -1;

            Slider_Vitesse_Manette(Vitesse);
            if(newConnexion->Avancer_Gauche() == true)
            {
                ui->lineEdit_instruction-> setText(newDeplacement->Trame_Avancer_Gauche);
            }
        }

        //--------------------------------------------------------Reculer Gauche
        else if (Num == AXE_DIRECTION && Element == AXE && Vitesse < -10 && Inverser == false)
        {
            Vitesse *= -1;

            Slider_Vitesse_Manette(Vitesse);
            if(newConnexion->Reculer_Gauche() == true)
            {
                ui->lineEdit_instruction-> setText(newDeplacement->Trame_Reculer_Gauche);
            }
        }



        //----------------------------------    Remet au Neutre quand les trames de deplacement revienne a 0
        if( ((Num == AXE_AVANCER) || (Num == AXE_RECULER) ) && Element == AXE && Vitesse < -99)
        {
            ui->lineEdit_instruction->setText("$N,N,000,'Neutre',*");
            newConnexion->BtnRelache();
        }
        if( Valeur > -20 && Valeur < 20 && Element == AXE && Num == AXE_DIRECTION )
        {
            ui->lineEdit_instruction->setText("$N,N,000,'Neutre',*");
            newConnexion->BtnRelache();
        }



        if( Num == AXE_BAISSER_PINCE && Element == AXE && Vitesse )
        {
            Vitesse += 102;
            Vitesse /= 2;
            qDebug() << "hauteur pince : " << Vitesse;
            if(newConnexion->HauteurPince(Vitesse) == true)
            {
                QString Vstr = QString::number(Vitesse);
                QString HauteurPince = "$P,H,"+ Vstr +",'Hauteur Pince',*";
                ui->lineEdit_instruction->setText(HauteurPince);
            }
        }

        if(Num == AXE_FERMER_PINCE && Element == AXE && Vitesse)
        {
            Vitesse += 102;
            Vitesse /= 2;
            qDebug() << "fermeture pince : " << Vitesse;
            if(newConnexion->FermeturePince(Vitesse) == true)
            {
                QString Fstr = QString::number(Vitesse);
                QString FermerPince = "$F,P,"+ Fstr +",'Fermer Pince',*";
                ui->lineEdit_instruction->setText(FermerPince);
            }
        }

        if(Num == 2  && Element == BOUTON && Valeur == 1)
        {
            on_pushButton_Checkpoint_clicked();
        }

        if(Num == 3  && Element == BOUTON && Valeur == 1)
        {
            on_pushButton_DemarrageVideo_clicked();
        }

        if(Num == 15  && Element == BOUTON && Valeur == 1)
        {
            on_pushButton_clicked();
        }

        if(Num == 5  && Element == BOUTON && Valeur == 1){
            on_pushButton_Connection_clicked();
        }

        //-----------------------------------------------------------//Couleur
        if(Num == 4  && Element == BOUTON && Valeur == 1){
            on_pushButton_Envoyer_Color_Base_clicked();
        }
        if(Num == 12  && Element == BOUTON && Valeur == 1){
            on_pushButton_Envoyer_Color_rouge_clicked();
        }
        if(Num == 14  && Element == BOUTON && Valeur == 1){
            on_pushButton_Envoyer_Color_black_clicked();
        }
        if(Num == 13  && Element == BOUTON && Valeur == 1){
            on_pushButton_Envoyer_Color_white_clicked();
        }
        if(Num == 11  && Element == BOUTON && Valeur == 1){
            on_pushButton_Envoyer_Color_blue_clicked();

        }

        return Vitesse;
    }
    else
    {
        return false;
    }
}
