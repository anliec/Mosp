#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout << argv[0] << std::endl;
    /*MainWindow w;
    w.show();*/
    Living player(LIVING_UNUSABLE,"player",Coordinate(0,0));
    Map map("../../../map/test.map");
    map.addLiving(&player);
    MapWidget w(&map, &player);
    w.show();

    return a.exec();
}
