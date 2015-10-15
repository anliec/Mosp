#ifndef MAPSCENE_H
#define MAPSCENE_H

#define SCENE_UD 100

#include <QWidget>
#include <QGraphicsScene>
#include "Map.h"
#include <QSize>
#include <QPen>
#include <QBrush>

class MapScene : public QGraphicsScene
{
public:
    MapScene(Map * map, QObject *parent =0);
    ~MapScene();

    void drawTile(Tile &tile);
    void drawLiving(Living *living);
    void drawPath(Coordinate c);
    void drawTileScare(Coordinate c, QBrush Brush, QPen pen);

    Map* getMap();
    Coordinate pointToCoordinate(QPoint point);

    void setPath(const std::vector<Coordinate> &pathToset);
    std::vector<Coordinate> getPath();
    void emptyPath();

public slots:
    void resetScene();
    void updateSize();

private:
    Map * map;
    QSize size;
    QBrush brushWalkable;
    QBrush brushUnwalkable;
    QBrush brushViewBlocking;
    QBrush brushPath;
    QPen penBoundary;
    std::vector<Coordinate> path;
};

#endif // MAPSCENE_H
