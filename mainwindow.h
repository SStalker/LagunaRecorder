#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAudioRecorder>
#include <QMediaRecorder>

#include "camera.h"
#include "viewfinder.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionStart_triggered();

    void on_actionStop_triggered();

    void on_actionSettings_triggered();

    void on_actionQuit_triggered();

    void on_actionStart_2_triggered();

    void on_actionStop_2_triggered();

    void Error(QMediaRecorder::Error);

    void stateChanged(QMediaRecorder::State);
    void statusChanged(QMediaRecorder::Status);

private:
    Ui::MainWindow *ui;
    //QAudioRecorder *recorder;

    Camera *cam;
    Viewfinder *viewfinder;
    QMediaRecorder *recorder;

};

#endif // MAINWINDOW_H
