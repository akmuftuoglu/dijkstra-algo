//
//  main.cpp
//  HW4 PIC10C
//
//  Created by Aral Muftuoglu on 10/30/22.
//

#include <iostream>
#include <vector>
#include <map>

#include "dijkstra.h"

using namespace std;


int main() {
    
    vector<vector<double>> map =
             { { 0, 5, 6, 0, 10, 0},
               { 3, 0, 0, 1, 3, 0},
               { 0, 0, 0, 0, 2, 4},
               { 0, 0, 1, 0, 2, 0},
               { 0, 0, 0, 0, 0, 2},
               { 0, 0, 3, 9, 0, 0}};
    
    vector<string> names = {"San Francisco", "San Diego", "Sacramento", "Los Angeles", "San Jose", "Irvine"};
        
    double cost = 0;
    
    // case I: multiple shortest paths
    string origin = names[1];
    string destination = names[5];
    
    findShortestToAll(map, names, origin);
    
   
    
    return 0;
}
