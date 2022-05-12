#ifndef GRAPHWIN_H
#define GRAPHWIN_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class GraphWin : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWin(QWidget *parent = nullptr);
    ~GraphWin();
private:
    QLabel *pointsLabel;
    QLabel *numOfPoints;
    QVBoxLayout *VLayout;

signals:

};

#endif // GRAPHWIN_H
