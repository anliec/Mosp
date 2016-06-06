#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include "mapscene.h"
#include "Pathfinder.h"

class MapWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapWidget(Map *mapSource, Living *widgetPlayer, QWidget *parent = 0);
    ~MapWidget();

signals:

protected slots:
    void resizeEvent(QResizeEvent * event);
    void mousePressEvent(QMouseEvent *eventPress);
    void mouseMoveEvent(QMouseEvent *eventMove);
    void leaveEvent(QEvent *e);

private:
    Living *player;
    Map* map;
    MapScene *mapScene;
};

#endif // MAPWIDGET_H
