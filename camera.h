#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>

class Camera : public QCamera
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CAMERA_H
