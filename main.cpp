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