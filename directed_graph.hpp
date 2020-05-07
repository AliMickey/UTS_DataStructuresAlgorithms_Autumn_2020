#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
// include more libraries here if you need to


using namespace std; // the standard namespace are here just in case.

/*
	the vertex class: similar to "Node" for "Linked_List"
*/
template <typename T>
class vertex {

public:
	int id; // unique identifer for each vertex
	T weight; // int, double, char, string, ...

	vertex(int v_id, T v_weight) : id(v_id), weight(v_weight) { // constructor
	}

	// add more functions here if you need to
};



/*
	the graph class: similar to "Linked_List"
*/
template <typename T>
class directed_graph {

private:

	vector<vertex<T>> vertice_list; // this is not design for this assignment
	// if you are using adj_list instead of adj_matrix, you may need something like vector < vector<vertex<T>> adj_list;

public:

	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.  // A vector cannot be considered a second_order_neighbor of itself.

};

template <typename T>
void directed_graph<T>::add_vertex(const vertex<T>& v) { //Add a vertex
	vertice_list.push_back(v);
}

template <typename T>
void directed_graph<T>::remove_vertex(const int& v_id) { // Remove Vertex
	for (int i = 0; i < vertice_list.size(); i++) { // Loop through each vertex
		if (vertice_list[i].id == v_id) {
			vertice_list.erase(vertice_list.begin() + i); // Delete the vertex associated with provided id
			break;
		}
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_vertices() { // Return all vertexes. 
	return vertice_list;
}






#endif