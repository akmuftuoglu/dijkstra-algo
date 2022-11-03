//
//  main.cpp
//


#include <string>
#include <vector>
#include <iostream>
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
    //vector<string> names = {"1", "2", "3", "4", "5", "6"};
        
    double cost = 0;
    
    
    // case I: multiple shortest paths //
    
    string origin = names[0];
    string destination = names[5];
        
    auto shortest = dijkstra(map, names, origin, destination, cost);
    cout << "The travel cost from " << origin << " to " << destination << " is " << cost << "." << endl;
    print_paths(shortest, names);
        
    cout << "***************************************" << endl;
    
    // case II: no path
    origin = names[5];
    destination = names[0];
    shortest = dijkstra(map, names, origin, destination, cost);
    cout << "The travel cost from " << origin << " to " << destination << " is " << cost << "." << endl;
    print_paths(shortest, names);
    
    // case II //
    
    //string origin = names[5];
    //string destination = names[0];
    //auto shortest = dijkstra(map, names, origin, destination, cost);
    //cout << "The travel cost from " << origin << " to " << destination << " is " << cost << "." << endl;
    //print_paths(shortest, names);
    
    
    // case III //
    
    //string origin = names[0];
    //string destination = names[3];
    //auto shortest = dijkstra(map, names, origin, destination, cost);
    //cout << "The travel cost from " << origin << " to " << destination << " is " << cost << "." << endl;
    //print_paths(shortest, names);
        
    
    // case IV //
    
    //string origin = names[1];
    //string destination = names[4];
    //auto shortest = dijkstra(map, names, origin, destination, cost);
    //cout << "The travel cost from " << origin << " to " << destination << " is " << cost << "." << endl;
    //print_paths(shortest, names);
    
    return 0;
}
