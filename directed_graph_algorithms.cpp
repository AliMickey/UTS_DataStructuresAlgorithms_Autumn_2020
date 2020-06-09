#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <cstddef>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>
#include <optional>
#include <exception>
#include <stdexcept>
#include<bits/stdc++.h> 

#include "directed_graph.hpp"

using namespace std;
//Was developed in IDE, use link to track progress: https://github.com/AliMickey/UTS_DataStructuresAlgorithms_2020_Assignment2/commits/master

/*
 * Computes the shortest distance from u to v in graph g.
 * The shortest path corresponds to a sequence of vertices starting from u and ends at v,
 * which has the smallest total weight of edges among all possible paths from u to v.
 */
template <typename T> //Done
vector<vertex<T>> shortest_path(directed_graph<T>& g, const int& u_id, const int& v_id) {
  vector<vertex<T>> neighbours;
  vector<vertex<T>> vertices;
  set<pair<int,int>> setds; 
  vector<int> dist(g.num_vertices()+1, 9999999); //Create dist array to store shortest distance for each vertex
  vector<int> prev(g.num_vertices()+1, 0); //Creat prev array to store previous shortest vertex for each vertex
  setds.insert(make_pair(0, u_id)); //Insert source and set dest to 0
  dist[u_id] = 0; 
  while (!setds.empty()) { 
    pair<int, int> temp = *(setds.begin()); //Set temp to top vertex in set
    setds.erase(setds.begin()); //Remove it from set
    int u = temp.second; //Set temp vertex to vertex id
    neighbours = g.get_neighbours(u); //Neighbours of current vertex
    for (auto vert: neighbours) { 
      int v = vert.id; //Neighbour id
      int weight = g.edgeCost(u, v); //current-neighbour edge cost
      if (dist[v] > dist[u] + weight) { //If current distance is smaller than total 
        if (dist[v] != 9999999) {
          setds.erase(setds.find(make_pair(dist[v], v))); //Update dist[neighbour] with updated distance
        }
        dist[v] = dist[u] + weight; //Set new distance
        prev[v] = u; //Set previous of shortest neighbour to curr
        setds.insert(make_pair(dist[v], v)); //Add to set
      }
    }
  }
  //Trace our way back from target to source by using prev[]
  int currentTempVertex = v_id; //Set initial temp to target
  while (prev[currentTempVertex] != 0) { //While previous is not 0
    vertices.push_back(g.getVertex(currentTempVertex)); //Add the vertex to 
    currentTempVertex = prev[currentTempVertex]; //Set current to prev
  } 
  vertices.push_back(g.getVertex(u_id)); //Add source vertex
  reverse(vertices.begin(), vertices.end()); //Reverse for final return
  return vertices;  
}


/*
 * Computes the strongly connected components of the graph.
 * A strongly connected component is a subset of the vertices
 * such that for every pair u, v of vertices in the subset,
 * v is reachable from u and u is reachable from v.
 */
template <typename T> //Done
vector<vector<vertex<T>>> strongly_connected_components(directed_graph<T>& g) {
  //Tarjan's Algorithm
  vector<vector<vertex<T>>> result;
  int n = g.num_vertices()+1;
  int dfn[n] = {0};
  int low[n];
  int dfn_cnt = 0;
  stack<vertex<T>> s;
  set<int> in_s;
  for (auto u: g.get_vertices()) {
    if (!dfn[u.id]) {
      sccRecursive(u, dfn, low, dfn_cnt, s, in_s, result, g);
    }
  }
  return result;
}

template <typename T> //Done
void sccRecursive(vertex<T>& u, int dfn[], int low[], int& dfn_cnt, stack<vertex<T>>& s, set<int>& in_s, vector<vector<vertex<T>>>& result, directed_graph<T>& g) {
  low[u.id] = dfn[u.id] = ++dfn_cnt;
  s.push(u); 
  in_s.insert(u.id);
  for (auto v: g.get_neighbours(u.id)) {
    if (!dfn[v.id]) {
      sccRecursive(v, dfn, low, dfn_cnt, s, in_s, result, g);
      low[u.id] = min(low[u.id], low[v.id]);
    }
    else if (in_s.find(v.id) != in_s.end()) {
      low[u.id] = min(low[u.id], dfn[v.id]);
    }
  }
  if (dfn[u.id] == low[u.id]) {
    vector<vertex<T>> vertices;
    while (s.top().id != u.id) { 
      vertices.push_back(s.top());
      in_s.erase(s.top().id);
      s.pop();
    }
    vertices.push_back(s.top());
    in_s.erase(s.top().id); 
    s.pop();   
    result.push_back(vertices);
  }
}


/*
 * Computes a topological ordering of the vertices.
 * For every vertex u in the order, and any of its
 * neighbours v, v appears later in the order than u.
 * You will be given a DAG as the argument.
 */
template <typename T> //Done
vector<vertex<T>> topological_sort(directed_graph<T>& g) {
  vector<vertex<T>> vertices; 
  int num_vertices = g.num_vertices();
  bool *visited = new bool [num_vertices]; //Initialise done array
  for (int i = 0; i < num_vertices; i++) { //Set all indexes in array as unvisited
    visited[i] = false;
  }
  for (int i = 0; i < num_vertices; i++) { //For each vertex in array
    if (visited[i] == false) { //If unvisited
      topological_sort_util(g, i, visited, vertices); //Perform topo
    }
  }
  reverse(vertices.begin(), vertices.end()); //Once all vertices are added to result, reverse the order for final return
  return vertices;
}

template <typename T> //Done
void topological_sort_util(directed_graph<T>& g, int node, bool visited[], vector<vertex<T>>& vertices) {
  visited[node] = true; //Set current node as visited
  vector<vertex<T>> neighbours = g.get_neighbours(node); //Get neighbours for current node
  for (vertex<T> i: neighbours) { //For every neighbour
    if (!visited[i.id]) { //If it is not visited already
      topological_sort_util(g, i.id, visited, vertices); //Perform topo sort
    }
  }
  if (g.getVertex(node).id != -2) { //If return is not empty vertex
    vertices.push_back(g.getVertex(node)); //Add it to result
  }
}


/*
 * Computes the lowest cost-per-person for delivery over the graph.
 * u is the source vertex, which send deliveries to all other vertices.
 * vertices denote cities; vertex weights denote cities' population;
 * edge weights denote the fixed delivery cost between cities, which is irrelevant to 
 * the amount of goods being delivered. 
 */
template <typename T>
T low_cost_delivery(directed_graph<T>& g, int u_id) {

  return 0;

}
