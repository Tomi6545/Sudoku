#pragma once
//
// Created by 21caog1bif on 16.06.23.
//
#include <QThread>

#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QMainWindow>
#include "ui_startwindow.h"

class StartWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = Q_NULLPTR);
    ~StartWindow() override;

private:
    Ui::StartWindow *ui;


private slots:
    void startClicked();

};



