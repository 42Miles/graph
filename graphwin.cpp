#include "graphwin.h"
#include <iostream>

GraphWin::GraphWin(QWidget *parent)
    : QWidget{parent}
{
    setBaseSize(600, 400);
    setStyleSheet("background-color:#323232;");

    VLayout = new QVBoxLayout();
    HTopLayout = new QHBoxLayout();
    HBottomLayout = new QHBoxLayout();
    graph = new Graph();

    setLayout(VLayout);
    VLayout->addLayout(HTopLayout);
    VLayout->addWidget(graph);
    VLayout->addLayout(HBottomLayout);

    pointsLabel = new QLabel;

    pointsLabel->setText("number of points: " + QString::number(graph->getNumOfPoints()));
    pointsLabel->setStyleSheet("color: #FFFFFF");
    pointsLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    HTopLayout->addWidget(pointsLabel);

    clear.setText("Clear");
    close.setText("Close");

    clear.setStyleSheet("QPushButton {background-color: #323232; color: white;}");
    close.setStyleSheet("QPushButton {background-color: #323232; color: white;}");

    QWidget::connect(&close, SIGNAL(clicked()), this, SLOT(closeSlot()));
    QWidget::connect(&clear, SIGNAL(clicked()), this, SLOT(clearSlot()));
    HBottomLayout->addStretch();
    HBottomLayout->addWidget(&clear);
    HBottomLayout->addWidget(&close);
}

GraphWin::~GraphWin()
{
    delete VLayout;
    delete pointsLabel;
    delete HTopLayout;
    delete HBottomLayout;
    delete graph;
}

void GraphWin::closeSlot()
{
    exit(0);
}
void GraphWin::clearSlot()
{
    graph->removePoints();
}




