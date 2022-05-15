#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QPainter>
#include <iostream>
#include <vector>
#include <utility>
#include <QRandomGenerator>
#include <QCursor>
#include <QMouseEvent>
#include <QDebug>


class Graph : public QWidget
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

    //getters:
    unsigned int getNumOfPoints();

    //funcs:
    void generatePoints();
    void drawPoints(QPainter *painter);
    void setPoint();
    void removePoints();
    void connectPoints(QPainter *painter);

private:
    unsigned int numOfStartPoints;
    unsigned int pointSize;
    std::vector<QPoint> points;
protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent *e) override;
signals:
    void mousePressed(const QPoint&);
    void numOfPointsChange();
};

#endif // GRAPH_H
