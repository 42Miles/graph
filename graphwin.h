#ifndef GRAPHWIN_H
#define GRAPHWIN_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <graph.h>

class GraphWin : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWin(QWidget *parent = nullptr);
    ~GraphWin();
private:
    QLabel *pointsLabel;
    QVBoxLayout *VLayout;
    QHBoxLayout *HTopLayout;
    QHBoxLayout *HBottomLayout;
    Graph *graph;

    QPushButton clear;
    QPushButton close;
private slots:
    void closeSlot();
    void clearSlot();

};

#endif // GRAPHWIN_H
