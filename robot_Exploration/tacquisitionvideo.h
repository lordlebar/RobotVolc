#ifndef TACQUISITIONVIDEO_H
#define TACQUISITIONVIDEO_H

#include <QThread>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <opencv2/opencv.hpp>


#define ID_CAMERA 0  // 0 Ma camera , 1 camera robot

class TAcquisitionVideo : public QThread
{
    Q_OBJECT
public:
    TAcquisitionVideo(QObject *parent = nullptr);

    QPixmap Pixmap() const{
        return mPixmap;
    }
    bool extinction;

signals:
    void newPixmapCaptured();
protected:
    void run() override;
private:
    QPixmap mPixmap; // Image de Qt
    cv::Mat mFrame; // Image de OpenCV
    cv::VideoCapture mVideoCap; // Capture de video

    QImage cvMatToQImage(const cv::Mat &inMat);
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);

};

#endif // TACQUISITIONVIDEO_H
