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
private:
        int startWidth;
        int startHeight;
        unsigned int numOfStartPoints;
        unsigned int pointSize;
        std::vector<std::pair<int, int>> points;
        std::vector<std::pair<int, int>> startPoints;
protected:
        void paintEvent(QPaintEvent*) override;
        void mousePressEvent(QMouseEvent *e) override;
signals:
        void mousePressed(const QPoint&);

};

#endif // GRAPH_H
