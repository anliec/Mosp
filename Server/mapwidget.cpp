#include "mapwidget.h"

MapWidget::MapWidget(Map *mapSource, Living *widgetPlayer, QWidget *parent): QGraphicsView(parent),player(widgetPlayer), map(mapSource)
{
    setMouseTracking(true); //to generate mouseMoveEvent whitout presing any button.
    mapScene = new MapScene(mapSource,parent);
    setScene(mapScene);
}

MapWidget::~MapWidget()
{
    delete mapScene;
}

void MapWidget::resizeEvent(QResizeEvent *event){
    QGraphicsView::resizeEvent(event);
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}

void MapWidget::mousePressEvent(QMouseEvent *eventPress)
{
    QPoint mouseOnScene = mapToScene(eventPress->pos()).toPoint();
    Coordinate mouse = mapScene->pointToCoordinate(mouseOnScene);
    Tile * t = map->at(mouse);
    if(t != nullptr && t->getType() == TILE_WALKABLE){
        Pathfinder pathfinder(player->getCoordinate(),mouse,*map);
        Move move(player);
        move.setPath(pathfinder.compute());
        map->applyMove(move);
        mapScene->emptyPath();
        mapScene->resetScene();
    }
}

void MapWidget::mouseMoveEvent(QMouseEvent *eventMove)
{
    QPoint mouseOnScene = mapToScene(eventMove->pos()).toPoint();
    Coordinate mouse = mapScene->pointToCoordinate(mouseOnScene);
    Tile * t = map->at(mouse);
    if(t != nullptr && t->getType() == TILE_WALKABLE){
        Pathfinder pathfinder(player->getCoordinate(),mouse,*map);
        mapScene->setPath(pathfinder.compute());
        mapScene->resetScene();
    }
    else{
        mapScene->emptyPath();
        mapScene->resetScene();
    }
}

void MapWidget::leaveEvent(QEvent *e){
    mapScene->emptyPath();
    mapScene->resetScene();
}
