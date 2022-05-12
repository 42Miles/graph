#include "graphwin.h"

GraphWin::GraphWin(QWidget *parent)
    : QWidget{parent}
{
    setBaseSize(600, 400);
    setStyleSheet("background-color:#565656;");

    VLayout = new QVBoxLayout(this);
    //VLayout->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(VLayout);
    pointsLabel = new QLabel;
    pointsLabel->setText("number of points: ");
    pointsLabel->setStyleSheet("color: #FFFFFF");

    VLayout->addWidget(pointsLabel);
}

GraphWin::~GraphWin()
{
    delete numOfPoints;
    delete VLayout;
    delete pointsLabel;
}
