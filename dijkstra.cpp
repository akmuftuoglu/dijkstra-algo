
/*
PIC 10C Homework 4, dijkstra.cpp
Purpose: Implement Dijkstra's Algorithm
Author: Aral Muftuoglu
Date: 11/03/2021
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <algorithm>
#include <stack>

#include "dijkstra.h"

using namespace std;

map<string, map<int, vector<vector<size_t>>>> shortestToAllWithPathes(const vector<vector<double>>& map, const vector<string>& names, string origin)
{
    std::map<string, std::map<int, vector<vector<size_t>>>> allPaths;
    
    std::map<string, int> visited;
    std::map<string, int> unvisited;
    std::map<string, vector<vector<size_t>>> paths;
    
    vector<string> nodeHistory;
    
    int maxSteps = 0;
    
    auto iter1 = find(names.begin(), names.end(), origin);
    int currIndex = iter1-names.begin();
    
    // initializes unvisited list in a random order
    for (int i = 0; i < names.size(); i++)
    {
        if (names[i] == origin)
        {
            unvisited.insert(pair<string, int>(origin, 0));
        }
        else
        {
            unvisited.insert(pair<string, int>(names[i], 10001));
        }
    }
    
    // start of step 1 (adding origin to visited list) //
    string current = origin;
    vector<size_t> originPath;
    originPath.push_back(currIndex);
    
    for (int i = 0; i < names.size(); i++)
    {
        if (unvisited.find(names[i]) != unvisited.end())
        {
            int oldVal = unvisited[names[i]];
            int newVal = unvisited[current] + map[currIndex][i];
            
            if (map[currIndex][i] != 0)
            {
                unvisited[names[i]] = min(oldVal, newVal);
            }
        }
            
    }
    
    visited.insert(pair<string, int>(current, unvisited[current]));
    paths.insert(pair<string,vector<vector<size_t>>>(current, vector<vector<size_t>>()));
    paths[current].push_back(originPath);
    
    auto it = unvisited.find(current);
    unvisited.erase(it);
    nodeHistory.push_back(current);
    
    // end of step 1 //
    
    
    // start of step 2 //
    
    while (maxSteps != names.size()-1) {
        
    int max = 10001;
    
    // find next min node //
    for (int i = 0; i < names.size(); i++)
    {
        if (visited.find(names[i]) == visited.end())
        {
            if (unvisited[names[i]] < max && unvisited[names[i]] != 0)
            {
                current = names[i];
                max = unvisited[names[i]];
            }
        }
    }
    
    
    // find current index //
    iter1 = find(names.begin(), names.end(), current);
    currIndex = iter1-names.begin();
    
    // update unvisited node values //
    for (int i = 0; i < names.size(); i++)
    {
            if (unvisited.find(names[i]) != unvisited.end())
            {
                int oldVal = unvisited[names[i]];
                int newVal = unvisited[current] + map[currIndex][i];
                
                if (map[currIndex][i] != 0)
                {
                    unvisited[names[i]] = min(oldVal, newVal);
                }
            }
            
    }
    
    
    // check paths //
    
        
    for (int i = nodeHistory.size()-1; i != -1; i--)
    {
        int j = 0;
            
        auto namePtr = find(names.begin(), names.end(), nodeHistory[i]);
        int nameIndex = namePtr-names.begin();
            
        if (map[nameIndex][currIndex] != 0 && visited[nodeHistory[i]] + map[nameIndex][currIndex] == unvisited[current])
        {
            paths.insert(pair<string,vector<vector<size_t>>>(current, vector<vector<size_t>>()));
                
            while (j != paths[nodeHistory[i]].size())
            {
                paths[current].push_back(paths[nodeHistory[i]][j]);
                j++;
            }
        }
        
    }
        
    for (int k = 0; k < paths[current].size(); k++)
    {
        paths[current][k].push_back(currIndex);
    }
        
        
    // update visited and unvisited lists //
    visited.insert(pair<string, int>(current, unvisited[current]));
    auto it2 = unvisited.find(current);
    unvisited.erase(it2);
    nodeHistory.push_back(current);
    maxSteps++;
}
    
    // end of steps 2 to number of names //
    
    for (int i = 0; i < names.size(); i++)
    {
        allPaths.insert(make_pair(names[i], std::map<int, vector<vector<size_t>>>()));
        allPaths[names[i]].insert(make_pair(visited[names[i]], paths[names[i]]));
    }
    
    
    return allPaths;
    
}


vector<vector<size_t>> dijkstra(const vector<vector<double>>& map, const vector<string>& names, string origin, string target, double& cost) {
  
    
    std::map<string, std::map<int, vector<vector<size_t>>>> allPaths = shortestToAllWithPathes(map, names, origin);
    
    std::map<int, vector<vector<size_t>>> info = allPaths[target];
    
    if ((info.begin()->second).empty() == true)
    {
        cost = -1;
    }
    else
    {
        cost = info.begin()->first;
    }
    
    vector<vector<size_t>> destinationInfo;
    
    destinationInfo = info.begin()->second;

    return destinationInfo;
}


void print_paths(const std::vector<std::vector<size_t>>& paths, const std::vector<std::string> & names)
{
    
    if (paths.size() == 0)
    {
        cout << "No path found!" << endl;
    }
    
    int line = 0;
    
    while (line != paths.size())
    {
        for (int i = 0 ; i < paths[line].size(); i++)
        {
            
            cout << names[paths[line][i]];
            
            if (i != paths[line].size()-1) {
                
                cout << "--";
            }
        }
        cout << endl;
        line++;
    }
    
}
