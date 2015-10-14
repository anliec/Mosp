<<<<<<< HEAD
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
    Map map("map/test.map");
    map.addLiving(&player);
    MapWidget w(&map, &player);
    w.show();

    return a.exec();
}
=======
#include <iostream>
#include "Map.h"
#include "Pathfinder.h"


using namespace std;

int main() {

    Map test("map/test.map");

    Coordinate depart(1,2), arriver(3,2);

    Pathfinder pathfinder(depart,arriver,test);

    vector<Coordinate> path = pathfinder.compute();

    test.printMap();

    for (int i = 0; i < path.size(); ++i) {
        cout << path.at(i) << endl;
    }

    return 0;
}
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
