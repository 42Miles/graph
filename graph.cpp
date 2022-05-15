#include "graph.h"

Graph::Graph(QWidget *parent)
    : QWidget{parent},
      numOfStartPoints{10},
      pointSize{18},
      startHeight{height()},
      startWidth{width()}
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

void Graph::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    QPen pen;
    pen.setColor(Qt::white);

    QBrush brush;
    brush.setColor(QColor(32, 32, 32));
    brush.setStyle(Qt::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    drawPoints(&painter);

    painter.end();
}

void Graph::mousePressEvent(QMouseEvent *e)
{
    const QPoint pos = e->pos();
    int x = pos.x() - 10;
    int y = pos.y() - 10;
    std::pair<int, int> mousePos(x, y);

    if(e->button() == Qt::LeftButton)
    {
        startPoints.push_back(mousePos);
        points.push_back(mousePos);
    }
    else if(e->button() == Qt::RightButton)
    {
        for(size_t i = 0; i < points.size(); ++i)
        {
            std::pair<int, int> maxPoint(points[i].first + pointSize/2, points[i].second + pointSize/2);
            std::pair<int, int> minPoint(points[i].first - pointSize/2, points[i].second - pointSize/2);
            if((mousePos.first >= minPoint.first && mousePos.first <= maxPoint.first)
                    &&
                mousePos.second >= minPoint.second && mousePos.second <= maxPoint.second)
            {
                qDebug("Delete");
                points.erase(std::remove(points.begin(), points.end(), points[i]), points.end());
                startPoints.erase(std::remove(startPoints.begin(), startPoints.end(), startPoints[i]), startPoints.end());
            }
        }
    }

    repaint();
    emit mousePressed( pos );
}

void Graph::generatePoints()
{
    QRandomGenerator *rg = QRandomGenerator::global();
    for(size_t i = 0; i < numOfStartPoints; ++i)
    {
        int x = rg->bounded(0, width() * 0.9);
        int y = rg->bounded(0, height() * 0.9);
        startPoints.push_back(std::pair<int, int>(x, y));
    }
    points = startPoints;
}

void Graph::drawPoints(QPainter *painter)
{
    for(size_t i = 0; i < startPoints.size(); ++i)
    {
        int x = //(width()- startWidth)/2+
                startPoints[i].first;
        int y = //(height()- startHeight)/2
                startPoints[i].second;
        painter->drawEllipse(x, y, pointSize, pointSize);
        //std::cout << i << " x: " << x << std::endl;
        //std::cout << i << " y: " << y << std::endl;
        points[i].first = x;
        points[i].second = y;
    }
}

void Graph::setPoint()
{
    QPoint mousePos = this->mapFromGlobal(QCursor::pos());
    startPoints.push_back(std::pair<int, int>(mousePos.x(), mousePos.y()));
    points.push_back(std::pair<int, int>(mousePos.x(), mousePos.y()));
}

void Graph::removePoints()
{
    startPoints.clear();
    points.clear();
    repaint();
}
