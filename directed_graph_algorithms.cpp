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

#include "directed_graph.hpp"

using namespace std;

/*
 * Computes the shortest distance from u to v in graph g.
 * The shortest path corresponds to a sequence of vertices starting from u and ends at v,
 * which has the smallest total weight of edges among all possible paths from u to v.
 */
template <typename T>
vector<vertex<T>> shortest_path(directed_graph<T>& g, const int& u_id, const int& v_id) {
  vector<vertex<T>> vertices;
  if (g.reachable(u_id, v_id)) {
    vector<int> toDoList;
    vector<int> doneList;
    vector<vertex<T>> neighbours;
    vector<vertex<T>> tempGet = g.get_vertices();
    int totalEdgeCost = 99999;
    toDoList.push_back(u_id); //Add source id to toDo
    vertices.push_back(g.findVertex(tempGet, u_id)); //Add source vertex 
    while (toDoList.size() != 0) { //While toDo is not empty
      doneList.push_back(toDoList.back()); //Add ID to done list
      neighbours = g.get_neighbours(toDoList.back()); //Get neighbours of last added ID
      int temptoDoBack = toDoList.back();
      toDoList.pop_back(); //Remove ID from toDo
      for (int i = 0; i < neighbours.size(); i++) { //For each neighbour of ID
        if (neighbours.at(i).id == v_id) { //If neighbour ID is destination ID
          vertices.push_back(g.findVertex(tempGet, v_id)); //Add dest vertex
          return vertices; //Return and break loop
        }
      }
      if (neighbours.size() > 0) { //If there are neighbours
        vertex<T> leastCostVertex = g.smallest_edge(g, temptoDoBack, neighbours, totalEdgeCost); //Make the neighbour vertex with least edge cost
        if (!g.vector_contains(doneList, leastCostVertex.id)) { //If smallest edge vertex ID is not in done list 
          toDoList.push_back(leastCostVertex.id); //Add it to do list
          vertices.push_back(g.findVertex(tempGet, leastCostVertex.id));
        } 
      }
    }
  }
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
