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

	//You will need to add some data members here
	//to actually represent the graph internally,
	//and keep track of whatever you need to.
	
	vector<vertex<T>> vertice_list; // this is not design for this assignment
	// if you are using adj_list instead of adj_matrix, you may need something like vector < vector<vertex<T>> adj_list;

public:

	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.														  // A vector cannot be considered a second_order_neighbor of itself.

};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

template <typename T>
void directed_graph<T>::add_vertex(const vertex<T>& u) {
	vertice_list.push_back(u);
}

template <typename T>
void directed_graph<T>::remove_vertex(const int& u_id) { // the argument is the vertex_id
	for (int i = 0; i < vertice_list.size(); i++) { // check on each vertex within vertice_list, which is a vector
		if (vertice_list[i].id == u_id) {
			vertice_list.erase(vertice_list.begin() + i); // delete the i-th vertex from the vector
			break;
		}
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_vertices() { // return the vector, whicn contains all vertices of the vector
	return vertice_list;
}






#endif