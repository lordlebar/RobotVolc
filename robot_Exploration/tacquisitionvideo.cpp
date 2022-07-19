#include "tacquisitionvideo.h"
#include "widget.h"
#include "ui_widget.h"

TAcquisitionVideo::TAcquisitionVideo(QObject *parent) : QThread { parent } , mVideoCap { ID_CAMERA }
{

}

void TAcquisitionVideo::run()
{
    extinction = false;
    if(mVideoCap.isOpened())
    {
        while(!extinction)
        {
            mVideoCap >> mFrame;
            flip(mFrame, mFrame, 1);
            if(!mFrame.empty())
            {
                mPixmap = cvMatToQPixmap(mFrame);
                emit newPixmapCaptured();
            }
        }
    }else{

    }
}


QImage TAcquisitionVideo::cvMatToQImage( const cv::Mat &inMat )
{
    switch ( inMat.type() )
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_ARGB32 );

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_RGB888 );

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_Grayscale8 );
#else
        static QVector<QRgb>  sColorTable;

        // only create our color table the first time
        if ( sColorTable.isEmpty() )
        {
            sColorTable.resize( 256 );

            for ( int i = 0; i < 256; ++i )
            {
                sColorTable[i] = qRgb( i, i, i );
            }
        }

        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_Indexed8 );

        image.setColorTable( sColorTable );
#endif

        return image;
    }

    default:
        qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
        break;
    }

    return QImage();
}

QPixmap TAcquisitionVideo::cvMatToQPixmap( const cv::Mat &inMat )
{
    return QPixmap::fromImage( cvMatToQImage( inMat ) );
}

void Widget::on_pushButton_DemarrageVideo_clicked()
{
    QString stopvideo = ui->pushButton_DemarrageVideo->text();
    if(TestConnexion == false && stopvideo == "Démarrer la capture vidéo")
    {
        mOpenCV_videoCapture->extinction = false;
        mOpenCV_videoCapture -> start(QThread::HighestPriority);
        ui->pushButton_DemarrageVideo->setText("Stopper la capture vidéo");
    }
    else if(TestConnexion == false && stopvideo == "Stopper la capture vidéo")
    {
        mOpenCV_videoCapture->extinction = true;
        ui->pushButton_DemarrageVideo->setText("Démarrer la capture vidéo");
    }
    else{
        qDebug() << "Non connecter";
    }

}
