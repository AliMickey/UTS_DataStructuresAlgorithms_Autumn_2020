#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>

using namespace std; 


template <typename T>
class vertex { //Vertex Class
	public:
		int id;
		T weight;
		vertex(int v_id, T v_weight) : id(v_id), weight(v_weight) {}	
};


template <typename T>
class directed_graph { //Graph Class

	private:
		unordered_map<int, T> all_vertices;
		unordered_map<int, unordered_map<int, T>> adj_list; // keep track of which index corresponds to which vertex_id

	public:
		directed_graph(); //A constructor for directed_graph. The graph should start empty.
		~directed_graph(); //A destructor. Depending on how you do things, this may not be necessary.

		bool contains(const int&); //Returns true if the graph contains the given vertex_id, false otherwise.
		bool adjacent(const int&, const int&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

		void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
		void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

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

template <typename T>
directed_graph<T>::directed_graph() {}

template <typename T>
directed_graph<T>::~directed_graph() {}

template <typename T> //Done
bool directed_graph<T>::contains(const int& v_id) {
	if(all_vertices.find(v_id)!=all_vertices.end()){
		return true;	
	}
	return false;
}

template <typename T>
bool directed_graph<T>::adjacent(const int& source_id, const int& dest_id) const { 
	
	return false; 
}

template <typename T> //Done
void directed_graph<T>::add_vertex(const vertex<T>& v) {
	if(!contains(v.id)){
		all_vertices.insert({v.id, v.weight}); // step 1: add to all_vertices
		adj_list[v.id]=unordered_map<int, T>(); // step 2: add to adj_list
	}
}

template <typename T>
void directed_graph<T>::add_edge(const int& u_id, const int& v_id, const T& uv_weight) {
	if(contains(u_id) && contains(v_id)){ // add the edge only if both vertices are in the graph and the edge is not in the graph
		if(adj_list[u_id].find(v_id)==adj_list[u_id].end()){
			adj_list[u_id].insert({v_id, uv_weight});
		}
	}
}

template <typename T>
void directed_graph<T>::remove_vertex(const int& u_id) { // remove the vertex, as well as all the incident edges
	all_vertices.erase(u_id); // step 1: remove from all_vertices
	adj_list.erase(u_id); // step 2: remove from adj_list
	for (auto& x: adj_list){ // x == pair<int, unordered_map<int,T>>
		x.second.erase(u_id); // x.second == unordered_map<int, T>
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
	for (int i = 0; i < all_vertices.size(); i++) { // Loop through
		amount += 1;
		} 
	return amount;
}
	

template <typename T> //TODO
size_t directed_graph<T>::num_edges() const { 
	int amount = 0;
	for (int i = 0; i < adj_list.size(); i++) { // Loop through
		amount += 1;
		} 
	return amount;
} 

template <typename T>
vector<vertex<T>> directed_graph<T>::get_vertices() {
	vector<vertex<T>> v;
	for(auto x: all_vertices){
		v.push_back(vertex<T>(x.first, x.second));
	}
	return v;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) {
	vector<vertex<T>> v;
	if(contains(u_id)){ // first make sure the vertex is in the graph
		for (auto x: adj_list[u_id]){ // adj_list[u_id] is an unordered_map<int, T>
			v.push_back(vertex<T>(x.first, all_vertices[x.first]));
		}
	}
	return v;
}

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