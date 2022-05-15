#include "graph.h"

Graph::Graph(QWidget *parent)
    : QWidget{parent},
      numOfStartPoints{10},
      pointSize{10}
{
    setMinimumSize(600, 400);
    setStyleSheet("background-color:black;");
    setAttribute(Qt::WA_StyledBackground);
    generatePoints();
}

Graph::~Graph()
{

}

unsigned int Graph::getNumOfPoints()
{
    return points.size();
}

//This function performs everything related to drawing
void Graph::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    QBrush brush;
    brush.setColor(QColor(32, 32, 32));
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    //first, the points are connected,
    //and only then they are drawn,
    //so that the line does not overlap the points
    connectPoints(&painter);
    drawPoints(&painter);

    //this line sends a signal about
    //a change in the number of points
    emit numOfPointsChange();

    painter.end();
}

//this function adds and deletes points
void Graph::mousePressEvent(QMouseEvent *e)
{
    //getting the mouse click position
    const QPoint pos = e->pos();
    //this line is needed to shift the mouse position
    //to its corner
    QPoint mousePos(pos.x()-5, pos.y()-5);

    if(e->button() == Qt::LeftButton)
        points.push_back(mousePos);
    else if(e->button() == Qt::RightButton)
    {
        for(size_t i = 0; i < points.size(); ++i)
        {
            QPoint maxPoint(points[i].x() + pointSize,
                            points[i].y() + pointSize);
            QPoint minPoint(points[i].x() - pointSize,
                            points[i].y() - pointSize);

            //this construction checks whether the user has clicked on the point
            //and when user click on a point, it deletes this point
            if((mousePos.x() >= minPoint.x() && mousePos.x() <= maxPoint.x())
                &&
                mousePos.y() >= minPoint.y() && mousePos.y() <= maxPoint.y())
            {
                points.erase(
                            std::remove(points.begin(), points.end(), points[i]), points.end());
            }
        }
    }

    repaint();
    emit mousePressed( pos );
}
//this function creates starting points
//in random places on the screen
void Graph::generatePoints()
{
    QRandomGenerator *rg = QRandomGenerator::global();
    for(size_t i = 0; i < numOfStartPoints; ++i)
    {
        int x = rg->bounded(0, width());
        int y = rg->bounded(0, height());
        points.push_back(QPoint(x, y));
    }
}

//this function is responsible for drawing points
void Graph::drawPoints(QPainter *painter)
{
    painter->setPen(Qt::white);
    for(size_t i = 0; i < points.size(); ++i)
        painter->drawEllipse(points[i], pointSize, pointSize);
}

//This function connects all points with green lines
void Graph::connectPoints(QPainter *painter)
{
    painter->setPen(Qt::green);

    for(size_t i = 0; i < points.size(); ++i)
        if(i < points.size() - 1)
            painter->drawLine(points[i], points[i+1]);
}

void Graph::removePoints()
{
    points.clear();
    repaint();
}

