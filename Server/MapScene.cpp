#include "MapScene.h"

MapScene::MapScene(Map * mapScene, QObject * parent): QGraphicsScene(parent), map(mapScene)
{
    updateSize();
    penBoundary = QPen(QColor(0,0,0));
    brushWalkable = QBrush(QColor(240,240,240));
    brushUnwalkable = QBrush(QColor(50,50,50));
    brushViewBlocking = QBrush(QColor(0,0,0));
    brushPath = QBrush(QColor(50,50,255));

    resetScene();
}

MapScene::~MapScene()
{
    path.empty();
}

void MapScene::drawTile(Tile *tile){

    QBrush activeBrush;
    switch(tile->getType()){
    case TILE_WALKABLE:
        activeBrush = brushWalkable;
        break;
    case TILE_UNWALKABLE:
        activeBrush = brushUnwalkable;
        break;
    case TILE_VIEW_BLOCKING:
        activeBrush = brushViewBlocking;
        break;
    }
    drawTileScare(tile->getCoordinate(),activeBrush,penBoundary);

}

void MapScene::drawPath(Coordinate c)
{
    drawTileScare(c,brushPath,penBoundary);
}

void MapScene::drawTileScare(Coordinate c, QBrush Brush, QPen pen)
{
    int x = c.getX()*SCENE_UD;
    int y = c.getY()*SCENE_UD;
    addRect(x,y,SCENE_UD ,SCENE_UD ,pen, Brush);
}

void MapScene::drawLiving(Living *living)
{
    int x = living->getCoordinate().getX()*SCENE_UD;
    int y = living->getCoordinate().getY()*SCENE_UD;
    addEllipse(x,y,SCENE_UD ,SCENE_UD ,QPen(QColor(10,10,10)), QBrush(QColor(255,0,0)));
}

void MapScene::resetScene(){
    this->clear();
    this->setSceneRect(0,0,SCENE_UD*size.width(),SCENE_UD*size.height());
    this->setBackgroundBrush(brushUnwalkable);

    ///Draw the case:
    for(int x=0 ; x<size.width() ; x++){
        for(int y=0 ; y<size.height() ; y++){
            drawTile(map->at(Coordinate(x,y)));
        }
    }

    ///Draw Path:
    for(unsigned int i=0 ; i<path.size() ; i++){
        drawPath(path.at(i));
    }

    ///Draw the Livings:
    //if there are one or more living on the tile we draw them:
    for(int x=0 ; x<size.width() ; x++){
        for(int y=0 ; y<size.height() ; y++){
            for(unsigned int i=0 ; i<map->at(Coordinate(x,y))->getLivings().size() ; i++){
                drawLiving(map->at(Coordinate(x,y))->getLivings().at(i));
            }
        }
    }
}

void MapScene::updateSize(){
    size.setHeight(map->getHeight());
    size.setWidth(map->getWidth());
}

Map* MapScene::getMap(){
    return map;
}

Coordinate MapScene::pointToCoordinate(QPoint point)
{
    Coordinate ret = Coordinate(0,0);
    ret.setX(point.x()/SCENE_UD);
    ret.setY(point.y()/SCENE_UD);
    return ret;
}

void MapScene::setPath(const std::vector<Coordinate> &pathToset)
{
    path = pathToset;
}

std::vector<Coordinate> MapScene::getPath()
{
    return path;
}

void MapScene::emptyPath()
{
    path.clear();
}

