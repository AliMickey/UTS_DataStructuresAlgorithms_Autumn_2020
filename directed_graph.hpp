#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
// include more libraries here if you need to


using namespace std; // the standard namespace are here just in case.

/*
	the vertex class: similar to "Node" for "Linked_List".
*/
template <typename T>
class vertex {
	public:
		int src_id; // unique identifer for each vertex
		int dest_id;
		T v_weight; // int, double, char, string, ...
		T e_weight;

		//Constructors
		vertex(int src_id, T v_weight) : src_id(src_id), v_weight(v_weight){};

		//edge(int src_id, int dest_id, T e_weight) : src_id(src_id), dest_id(dest_id), e_weight(e_weight){}
};


template <typename T>
class directed_graph {

	private:
		vector<vertex<T>> adjList;

	public:

		bool contains(const int&) const; //Returns true if the graph contains the given vertex_id, false otherwise.
		bool adjacent(const int&, const int&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

		void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
		void add_edge(const int&, const int&, const T&); //Add an edge from source vertex to dest vertex

		void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
		void remove_edge(const int&, const int&); //Removes the edge between the two vertices, if it exists.

		size_t in_degree(const int&) const; //Returns number of edges coming in to a vertex.
		size_t out_degree(const int&) const; //Returns the number of edges leaving a vertex.
		size_t degree(const int&) const; //Returns the degree of the vertex (both in edges and out edges).

		size_t num_vertices() const; //Returns the total number of vertices in the graph.
		size_t num_edges() const; //Returns the total number of edges in the graph.

		vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
		vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
		vector<vertex<T>> get_second_order_neighbors(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex. A vector cannot be considered a second_order_neighbor of itself.
		bool reachable(const int&, const int&) const; //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
		bool contian_cycles() const; // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

		vector<vertex<T>> depth_first(const int&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
		vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

		directed_graph<T> out_tree(const int&); //Returns a spanning tree of the graph starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

		vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of a pre-order traversal of the minimum spanning tree starting at the given vertex.
		vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the minimum spanning tree starting at the given vertex.
		vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the minimum spanning tree starting at the given vertex.

		vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

	};


template <typename T> //Done
bool directed_graph<T>::contains(const int& v_id) const {
	for (int i = 0; i < adjList.size(); i++) { // Loop through each vertex
		if (adjList[i].src_id == v_id) {
			return true;
			break;
		}
	}
	return false;
}

template <typename T>
bool directed_graph<T>::adjacent(const int& source_id, const int& dest_id) const { 
	
	return false; 
}

template <typename T> //Done
void directed_graph<T>::add_vertex(const vertex<T>& v) {
	adjList.push_back(v);
}

template <typename T>
void directed_graph<T>::add_edge(const int& src_id, const int& dest_id, const T& weight) { //Add an edge
	//adj_list.push_back(src_id, dest_id, weight);

}

template <typename T> //TODO REMOVE EDGES AS WELL
void directed_graph<T>::remove_vertex(const int& v_id) {
		for (int i = 0; i < adjList.size(); i++) { // Loop through each vertex
		if (adjList[i].src_id == v_id) {
			adjList.erase(adjList.begin() + i); // Delete the vertex associated with provided id
			break;
		}
	}
}

template <typename T>
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) {}

template <typename T>
size_t directed_graph<T>::in_degree(const int& u_id) const { return 0; }

template <typename T>
size_t directed_graph<T>::out_degree(const int& u_id) const { return 0; }

template <typename T>
size_t directed_graph<T>::degree(const int& u_id) const { return 0; }

template <typename T> //Done
size_t directed_graph<T>::num_vertices() const { 
	int amount = 0;
	for (int i = 0; i < adjList.size(); i++) { // Loop through each vertex
		amount += 1;
		}
	return amount;
	} 

template <typename T>
size_t directed_graph<T>::num_edges() const { return 0; }

template <typename T> //Done
vector<vertex<T>> directed_graph<T>::get_vertices() { // Return all vertexes. 
	return adjList;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::get_second_order_neighbors(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
bool directed_graph<T>::reachable(const int& u_id, const int& v_id) const { return false; }

template <typename T>
bool directed_graph<T>::contian_cycles() const { return false; }

template <typename T>
vector<vertex<T>> directed_graph<T>::depth_first(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::breadth_first(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int& u_id) { return directed_graph<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() { return vector<vertex<T>>(); }









#endif