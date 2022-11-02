//
//  dijkstra.cpp
//  HW4 PIC10C

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <algorithm>

#include "dijkstra.h"

using namespace std;


vector<vector<size_t>> dijkstra(const vector<vector<double>>& map, const vector<string>& names, string origin, string target, double& cost) {
    
    
    //auto iter1 = find(names.begin(), names.end(), origin);
    //int originIndex = iter1-names.begin();
    
    //auto iter2 = find(names.begin(), names.end(), target);
    //int targetIndex = iter2-names.begin();
    
   
    vector<vector<size_t>> returnInfo;
    return returnInfo;
}







void print_paths(const std::vector<std::vector<size_t>>& paths, const std::vector<std::string> & names)
{
    for (int i = 0; i < paths.size(); i ++)
    {
        
    }
    
    
}


void findShortestToAll(const vector<vector<double>>& map, const vector<string>& names, string origin)
{
    
    std::map<string,int> visited;
    std::map<string,int> unvisited;
    
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
   
    
    // start of step 1 //
    string current = origin;
    
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
    auto it = unvisited.find(current);
    unvisited.erase(it);
    
    // end of step 1
    
    // start of step 2 //
    int max = 10001;
    
    // find next min node
    
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
    
    
    iter1 = find(names.begin(), names.end(), current);
    currIndex = iter1-names.begin();
    
    
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
    auto it2 = unvisited.find(current);
    unvisited.erase(it2);

    // end of step 2
    
    
    // start of step 3
    max = 10001;
    
    // find next min node
    
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
    
    
    iter1 = find(names.begin(), names.end(), current);
    currIndex = iter1-names.begin();
    
    
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
    auto it3 = unvisited.find(current);
    unvisited.erase(it3);
    
    // end of step 3

    
    // start of step 4
    max = 10001;
    
    // find next min node
    
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
    
    
    iter1 = find(names.begin(), names.end(), current);
    currIndex = iter1-names.begin();
    
    
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
    auto it4 = unvisited.find(current);
    unvisited.erase(it4);
    
    // end of step 4
    
    
    // start of step 5
    max = 10001;
    
    // find next min node
    
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
    
    
    iter1 = find(names.begin(), names.end(), current);
    currIndex = iter1-names.begin();
    
    
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
    auto it5 = unvisited.find(current);
    unvisited.erase(it5);
    
    // end of step 5
    
    
    // start of step 6
    max = 10001;
    
    // find next min node
    
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
    
    
    iter1 = find(names.begin(), names.end(), current);
    currIndex = iter1-names.begin();
    
    
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
    auto it6 = unvisited.find(current);
    unvisited.erase(it6);
    
    // end of step 6
    
    
    
    
    
    // print function to see
   
    for (auto it = unvisited.begin(); it != unvisited.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
     
    std::cout << std::endl;
    
    for (auto it = visited.begin(); it != visited.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    
    
    std::cout << current;
    
}
