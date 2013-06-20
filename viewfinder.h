#ifndef VIEWFINDER_H
#define VIEWFINDER_H

#include <QtMultimediaWidgets/QCameraViewfinder>

class Viewfinder : public QCameraViewfinder
{
    Q_OBJECT
public:
    explicit Viewfinder(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // VIEWFINDER_H
