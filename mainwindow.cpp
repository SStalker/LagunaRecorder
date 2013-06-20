#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QAudioEncoderSettings>
#include <QVideoEncoderSettings>
#include <QMediaRecorder>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cam = new Camera(this);


    QList<QByteArray> devices = cam->availableDevices();

    qDebug() << "Anzahl Geräte: " << devices.size();

    QByteArray device1 = devices.value(0);


    viewfinder = new Viewfinder;
    setCentralWidget(viewfinder);
    cam->setViewfinder(viewfinder);
    cam->setCaptureMode(QCamera::CaptureVideo);


    recorder = new QMediaRecorder(cam,this);

    recorder->setOutputLocation(QUrl::fromLocalFile("./test.mp4"));

    QVideoEncoderSettings videoSetting = recorder->videoSettings();

    videoSetting.setResolution(800,600);
    videoSetting.setQuality(QMultimedia::HighQuality);
    videoSetting.setFrameRate(30.0);
    videoSetting.setCodec("video/mpeg");
    recorder->setVideoSettings(videoSetting);

    QAudioEncoderSettings audioSetting = recorder->audioSettings();
    qDebug() << recorder->supportedAudioCodecs() << endl
             << recorder->supportedAudioSampleRates(audioSetting).size() << endl
             << recorder->supportedContainers() << endl
             << recorder->supportedFrameRates(videoSetting).size() << endl
             << recorder->supportedResolutions(videoSetting).size() << endl
             << recorder->supportedVideoCodecs() << endl;
    audioSetting.setCodec("audio/AMR");
    audioSetting.setQuality(QMultimedia::HighQuality);
    //recorder->setAudioSettings(audioSetting);

    connect(recorder,SIGNAL(stateChanged(QMediaRecorder::State)),SLOT(stateChanged(QMediaRecorder::State)));
    connect(recorder,SIGNAL(statusChanged(QMediaRecorder::Status)),SLOT(statusChanged(QMediaRecorder::Status)));
    connect(recorder,SIGNAL(error(QMediaRecorder::Error)),this,SLOT(Error(QMediaRecorder::Error)));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_actionStart_triggered()
{
    cam->start();
}

void MainWindow::on_actionStop_triggered()
{
    cam->stop();
}

void MainWindow::on_actionSettings_triggered()
{

}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionStart_2_triggered()
{
    // Start recording
    qDebug() << recorder->outputLocation().toString();
    recorder->record();
}

void MainWindow::on_actionStop_2_triggered()
{
    // Stop recording
    recorder->stop();
}

void MainWindow::Error(QMediaRecorder::Error error)
{
    qDebug() << "Fehler: " << error;
}

void MainWindow::stateChanged(QMediaRecorder::State state)
{
    qDebug() << "State: " << state;
}

void MainWindow::statusChanged(QMediaRecorder::Status status)
{
    qDebug() << "Status: " << status;
}
