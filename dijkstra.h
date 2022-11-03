
/*
PIC 10C Homework 4, dijkstra.h
Purpose: Implement Dijkstra's Algorithm
Author: Aral Muftuoglu
Date: 11/03/2021
*/

#ifndef dijkstra_h
#define dijkstra_h

#include <vector>
#include <map>

std::vector<std::vector<size_t>> dijkstra(const std::vector<std::vector<double>>& map, const std::vector<std::string>& names, std::string origin, std::string target, double& cost);

void print_paths(const std::vector<std::vector<size_t>>& paths, const std::vector<std::string> & names);

std::map<std::string, std::map<int, std::vector<std::vector<size_t>>>> shortestToAllWithPathes(const std::vector<std::vector<double>>& map, const std::vector<std::string>& names, std::string origin);

#endif /* dijkstra_h */
