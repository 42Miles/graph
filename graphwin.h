#ifndef GRAPHWIN_H
#define GRAPHWIN_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <graph.h>

class GraphWin : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWin(QWidget *parent = nullptr);
    ~GraphWin();

public slots:
    void setNumOfPoints();
private:
    QLabel *pointsLabel;
    QLabel *numOfPointsLabel;
    QVBoxLayout *VLayout;
    QHBoxLayout *HTopLayout;
    QHBoxLayout *HBottomLayout;

    Graph *graph;

    QPushButton clear;
    QPushButton close;
private slots:
    void closeSlot();
    void clearSlot();
signals:
    void valueChange();

protected:
    //void mousePressEvent(QMouseEvent *e) override;
};

#endif // GRAPHWIN_H
