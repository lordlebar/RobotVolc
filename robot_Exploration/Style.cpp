#include "widget.h"
#include "ui_widget.h"

void Widget::on_pushButton_Envoyer_Color_Base_clicked()
{
    //----------------Style de la page
    setStyleSheet("Widget { background: rgba(122,214,197,1);  } "
                  "QTextEdit { border: 2px solid rgba(50,50,50,0.8); border-radius: 20%; background: rgba(240,240,240,0.4); color: rgba(50,50,50,0.8);}"
                  "QTextEdit#textEdit {border-radius: 20%; background: rgba(220,220,220,0.6); }"
                  "QTextEdit#textEdit_2 {border-radius: 30%; background: rgba(220,220,220,0.6); }"

                  "QPushButton { border-radius : 10px; background: rgba(255,255,255,0.7); border-right: 1px solid rgba(20,46,70,0.4);  border-bottom: 1px solid rgba(20,46,70,0.4); } "
                  "QPushButton:hover { background: rgba(230,230,230,0.5); color: rgba(30,30,30,0.8); }"
                  "QPushButton:pressed { color: white; border-radius : 12px;border: 0px; border-top: 1px solid rgba(20,46,70,0.4); border-left: 1px solid rgba(20,46,70,0.4); }"

                  "QLineEdit { background: rgba(230,230,230,0.5); border: 0.8px solid rgba(40,66,130,0.7); color: rgba(50,50,50,0.9); border-radius : 5px;}"
                  "QPixmap#mPixmap { border-radius : 20%; }");
}



void Widget::on_pushButton_Envoyer_Color_black_clicked()
{
    setStyleSheet("Widget { background: rgba(22, 19, 19,1);  } "
                  "QTextEdit { color: rgba(250,250,250,0.8); border: 2px solid rgba(250,250,250,0.8); border-radius: 20%; background: rgba(40,40,40,0.4); }"
                  "QTextEdit#textEdit {border-radius: 20%; background: rgba(20,20,20,0.6); }"
                  "QTextEdit#textEdit_2 {border-radius: 30%; background: rgba(20,20,20,0.6); }"

                  "QPushButton { color:rgba(190,190,190,0.8); border-radius : 10px; background: rgba(100,100,100,0.7); border-right: 1px solid rgba(90,90,90,0.4);  border-bottom: 1px solid rgba(90,90,90,0.4); } "
                  "QPushButton:hover { background: rgba(50,50,50,0.5); color: rgba(240,240,240,0.8); }"
                  "QPushButton:pressed { color: white; border-radius : 12px;border: 0px; border-top: 1px solid rgba(90,90,90,0.4); border-left: 1px solid rgba(90,90,90,0.4); }"

                  "QLineEdit { background: rgba(30,30,30,0.5); border: 0.8px solid rgba(110,110,110,0.7); color: rgba(250,250,250,0.9); border-radius : 5px;}"
                  "QLabel{color:rgba(190,190,190,0.8); }"
                  "QRadioButton{color:rgba(190,190,190,0.8);}"
                  "QGroupBox{color:rgba(190,190,190,0.8);}"
                  "QCheckBox{color:rgba(190,190,190,0.8);}");
}


void Widget::on_pushButton_Envoyer_Color_white_clicked()
{
    setStyleSheet("Widget { background: rgba(246, 249, 242 ,1) ;  } "
                  "QTextEdit { border: 2px solid rgba(50,50,50,0.8); border-radius: 20%; background: rgba(240,240,240,0.4); color: rgba(50,50,50,0.8);}"
                  "QTextEdit#textEdit {border-radius: 20%; background: rgba(220,220,220,0.6); }"
                  "QTextEdit#textEdit_2 {border-radius: 30%; background: rgba(220,220,220,0.6); }"

                  "QPushButton { border-radius : 10px; background: rgba(255,255,255,0.7); border-right: 1px solid rgba(20,46,70,0.4);  border-bottom: 1px solid rgba(20,46,70,0.4); } "
                  "QPushButton:hover { background: rgba(230,230,230,0.5); color: rgba(30,30,30,0.8); }"
                  "QPushButton:pressed { color: rgba(80,80,80,0.7); border-radius : 12px;border: 0px; border-top: 1px solid rgba(20,46,70,0.4); border-left: 1px solid rgba(20,46,70,0.4); }"

                  "QLineEdit { background: rgba(230,230,230,0.5); border: 0.8px solid rgba(40,66,130,0.7); color: rgba(50,50,50,0.9); border-radius : 5px;}");
}

void Widget::on_pushButton_Envoyer_Color_blue_clicked()
{
    setStyleSheet("Widget { background: rgba(55, 143, 255 ,1) ;  } "
                  "QTextEdit { border: 2px solid rgba(50,50,50,0.8); border-radius: 20%; background: rgba(240,240,240,0.4); color: rgba(50,50,50,0.8);}"
                  "QTextEdit#textEdit {border-radius: 20%; background: rgba(220,220,220,0.6); }"
                  "QTextEdit#textEdit_2 {border-radius: 30%; background: rgba(220,220,220,0.6); }"

                  "QPushButton { border-radius : 10px; background: rgba(255,255,255,0.7); border-right: 1px solid rgba(20,46,70,0.4);  border-bottom: 1px solid rgba(20,46,70,0.4); } "
                  "QPushButton:hover { background: rgba(230,230,230,0.5); color: rgba(30,30,30,0.8); }"
                  "QPushButton:pressed { color: white; border-radius : 12px;border: 0px; border-top: 1px solid rgba(20,46,70,0.4); border-left: 1px solid rgba(20,46,70,0.4); }"

                  "QLineEdit { background: rgba(230,230,230,0.5); border: 0.8px solid rgba(40,66,130,0.7); color: rgba(50,50,50,0.9); border-radius : 5px;}");
}

void Widget::on_pushButton_Envoyer_Color_rouge_clicked()
{
    setStyleSheet("Widget { background: rgba(219, 85, 85,1);  } "
                  "QTextEdit { border: 2px solid rgba(50,50,50,0.8); border-radius: 20%; background: rgba(240,240,240,0.4); color: rgba(50,50,50,0.8);}"
                  "QTextEdit#textEdit {border-radius: 20%; background: rgba(220,220,220,0.6); }"
                  "QTextEdit#textEdit_2 {border-radius: 30%; background: rgba(220,220,220,0.6); }"

                  "QPushButton { border-radius : 10px; background: rgba(255,255,255,0.7); border-right: 1px solid rgba(20,46,70,0.4);  border-bottom: 1px solid rgba(20,46,70,0.4); } "
                  "QPushButton:hover { background: rgba(230,230,230,0.5); color: rgba(30,30,30,0.8); }"
                  "QPushButton:pressed { color: white; border-radius : 12px;border: 0px; border-top: 1px solid rgba(20,46,70,0.4); border-left: 1px solid rgba(20,46,70,0.4); }"

                  "QLineEdit { background: rgba(230,230,230,0.5); border: 0.8px solid rgba(40,66,130,0.7); color: rgba(50,50,50,0.9); border-radius : 5px;}");
}


