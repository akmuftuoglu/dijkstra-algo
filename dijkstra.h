//
//  dijkstra.h
//  HW4 PIC10C


#ifndef dijkstra_h
#define dijkstra_h

#include <vector>


std::vector<std::vector<size_t>> dijkstra(const std::vector<std::vector<double>>& map, const std::vector<std::string>& names, std::string origin, std::string target, double& cost);

void print_paths(const std::vector<std::vector<size_t>>& paths, const std::vector<std::string> & names);


void findShortestToAll(const std::vector<std::vector<double>>& map, const std::vector<std::string>& names, std::string origin);
#endif /* dijkstra_h */
