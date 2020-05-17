#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std; 

//Started off using the demo code (adj_list) from Ed.
//Was developed in IDE, use link to track progress: https://github.com/AliMickey/UTS_DataStructuresAlgorithms_2020_Assignment1/commits/master

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
		bool adjacent(const int&, const int&); //Returns true if the first vertex is adjacent to the second, false otherwise.

		void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
		void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

		void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
		void remove_edge(const int&, const int&); //Removes the edge between the two vertices, if it exists.

		size_t in_degree(const int&); //Returns number of edges coming in to a vertex.
		size_t out_degree(const int&); //Returns the number of edges leaving a vertex.
		size_t degree(const int&); //Returns the degree of the vertex (both in edges and out edges).

		size_t num_vertices() const; //Returns the total number of vertices in the graph.
		size_t num_edges(); //Returns the total number of edges in the graph.

		vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
		vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
		vector<vertex<T>> get_second_order_neighbours(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex. A vector cannot be considered a second_order_neighbor of itself.
		bool reachable(const int&, const int&); //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
		bool contain_cycles(); // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

		vector<vertex<T>> depth_first(const int&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
		void depth_first_search(vector<vertex<T>>& vertices, const int u_id, vector<bool>* doneList);
		vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

		directed_graph<T> out_tree(const int&); //Returns a spanning tree of the graph starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

		vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of a pre-order traversal of the minimum spanning tree starting at the given vertex.
		vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the minimum spanning tree starting at the given vertex.
		vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the minimum spanning tree starting at the given vertex.

		vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

	};

template <typename T> //Done
directed_graph<T>::directed_graph() { 
	//Constructor
} 

template <typename T> //Done
directed_graph<T>::~directed_graph() { 
	//Destructor
} 

template <typename T> //Done
bool directed_graph<T>::contains(const int& u_id) {
	if (all_vertices.find(u_id) != all_vertices.end()) { //Check if vertex exists in all list
		return true;	
	}
	return false;
}

template <typename T> //Done
bool directed_graph<T>::adjacent(const int& source_id, const int& dest_id) { 
	if (contains(source_id) && contains(dest_id)) { //Check if verticies exist
		if (adj_list[source_id].find(dest_id) != adj_list[source_id].end()) { //If dest_id is a vertex that exists in adj_list as source_id's edge pair 
			return true; //They are adjacent
		}
	}
	return false; 
}

template <typename T> //Done
void directed_graph<T>::add_vertex(const vertex<T>& v) {
	if (!contains(v.id)) {
		all_vertices.insert({v.id, v.weight}); //Add to all_verticies
		adj_list[v.id] = unordered_map<int, T>(); //Create a adj_list entry 
	}
}

template <typename T> //Done
void directed_graph<T>::add_edge(const int& u_id, const int& v_id, const T& uv_weight) {
	if (contains(u_id) && contains(v_id)) { //Check if vertices exist
		if (adj_list[u_id].find(v_id) == adj_list[u_id].end()) { //Check if edge is not in list 
			adj_list[u_id].insert({v_id, uv_weight}); //Add the edge for corresponding index
		}
	}
}

template <typename T> //Done
void directed_graph<T>::remove_vertex(const int& u_id) {
	all_vertices.erase(u_id); //Remove from vertex list
	adj_list.erase(u_id); //Remove from adjacent list
	for (auto& x: adj_list) { //Remove all edges for u_id
		x.second.erase(u_id); 
	}
}

template <typename T> //Done
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) {
	if (adj_list[u_id].find(v_id) != adj_list[u_id].end()) { //Find if the edge is in the list
		adj_list[u_id].erase(v_id); //Remove the edge
	}
}

template <typename T> //Done
size_t directed_graph<T>::in_degree(const int& u_id) { 
	int amount = 0; //Set initial to 0
	if (contains(u_id)) { //Check if vertex exists
		for (int i = 0; i < adj_list.size(); i++) { //Loop over each item in adj_list
			if (adj_list[i].find(u_id) != adj_list[i].end()) { //If it exists, increment amount by 1.
				amount += 1;
			}	
		}
	}
	return amount; 
}

template <typename T> //Done
size_t directed_graph<T>::out_degree(const int& u_id) {
	int amount = 0; //Set initial to 0
	if (contains(u_id)) { //Check if vertex exists
		for (int i = 0; i < adj_list.size(); i++) { //Loop over each item in adj_list
			if (adj_list[u_id].find(i) != adj_list[i].end()) { //If it exists, increment amount by 1.
				amount += 1;
			}	
		}
	}
	return amount;  
}

template <typename T> //Done
size_t directed_graph<T>::degree(const int& u_id) { 
	return in_degree(u_id) + out_degree(u_id); //Add in and out edges and return it.
}

template <typename T> //Done
size_t directed_graph<T>::num_vertices() const {
	return all_vertices.size(); //Return size of vertices list
}

template <typename T> //Done
size_t directed_graph<T>::num_edges() {
	int amount = 0; //Set initial to 0
	for (int i = 0; i < adj_list.size(); i++) { //Loop over number of adj_list items
		for (auto x : adj_list[i]) { //For each vertex in adj_list
			amount += 1; //Increment by 1
		}
	}
	return amount;
}

template <typename T> //Done
vector<vertex<T>> directed_graph<T>::get_vertices() {
	vector<vertex<T>> v; 
	for (auto x: all_vertices) { //For all vertices
		v.push_back(vertex<T>(x.first, x.second)); //Add to returnable <vector>, original was unordered_map
	}
	return v;
}

template <typename T> //Done
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) {
	vector<vertex<T>> v;
	if (contains(u_id)) { //Check if vertex exists
		for (auto x: adj_list[u_id]) { //For all edges of u_id
			v.push_back(vertex<T>(x.first, all_vertices[x.first])); //Add to returnable <vector>, original was unordered_map
		}
	}
	return v;
}

template <typename T> //Done
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int& u_id) {
	//Used this as pseudo code - https://stackoverflow.com/a/354366
	vector<int> firstNeighboursID;
	vector<int> doneList;
	vector<vertex<T>> tempSecondNeighbours;
	vector<vertex<T>> secondNeighbours;
	if (contains(u_id)) { //Check if vertex exists
		for (auto x: adj_list[u_id]) { //Get first neighbour IDs
			firstNeighboursID.push_back(x.first);
		}
		for (int i = 0; i < firstNeighboursID.size(); i++) { //For each first neighbour
			tempSecondNeighbours = get_neighbours(firstNeighboursID.at(i)); //Get its neighbours and add to temp
			for (int j = 0; j < tempSecondNeighbours.size(); j++) { //For each second neighbour
				if (!(find(doneList.begin(), doneList.end(), tempSecondNeighbours[j].id) != doneList.end()) && tempSecondNeighbours.at(j).id != u_id ) { //If ID is NOT in done list AND ID is not source vertex
					secondNeighbours.push_back(tempSecondNeighbours[j]); //Add neighbour to returnable <vector>
				}
				doneList.push_back(tempSecondNeighbours[j].id); //Add ID to done list
			}
		}
	}
	return secondNeighbours;
}

template <typename T> //Done
bool directed_graph<T>::reachable(const int& u_id, const int& v_id) { 
	vector<int> toDoList;
	vector<int> doneList;
	vector<vertex<T>> neighbours;
	toDoList.push_back(u_id); //Add source id to toDo
	while (toDoList.size() != 0) { //While toDo is not empty
		doneList.push_back(toDoList.back()); //Add ID to done list
		neighbours = get_neighbours(toDoList.back()); //Get neighbours of last added ID
		toDoList.pop_back(); //Remove ID from toDo
		for (int i = 0; i < neighbours.size(); i++) { //For each neighbour of ID
			if (neighbours.at(i).id == v_id) { //If neighbour ID is destination ID
				return true; //They are reachable
			}
			if (!(find(doneList.begin(), doneList.end(), neighbours[i].id) != doneList.end())) { //If ID is not in done list
				toDoList.push_back(neighbours[i].id); //Add it to do list
			} 
		}
		neighbours.clear(); //Delete all neighbours for next iteration
	}
	return false; 
}

template <typename T> //Done
bool directed_graph<T>::contain_cycles() {
	//Call reachable with source_id and source_id until return true
	for (int i = 0; i < adj_list.size(); i++) {
		if (reachable(i, i)) {
			return true;
		}
	}
	return false;
}

template <typename T> //Done
vector<vertex<T>> directed_graph<T>::depth_first(const int& u_id) { 
	//Used this as inspiration - https://edstem.org/courses/3890/discussion/233222
	auto* doneList = new vector<bool>(num_vertices()+1); //Set initial boolean to size + 1
	vector<vertex<T>> vertices;
	depth_first_search(vertices, u_id, doneList); //Run the initial dfs on source vertex
	for (int i = 0; i < doneList->size(); i++) { //Then run it for each vertex NOT visited already for amount of vertices
		if (!doneList->at(i)) {
			depth_first_search(vertices, i, doneList);
		}
	}
	return vertices; 
}

template <typename T> //Done
void directed_graph<T>::depth_first_search(vector<vertex<T>>& vertices, const int u_id, vector<bool>* doneList) {
	if (contains(u_id)) { //If vertex exists
		if (!doneList->at(u_id)) { //If it is not visited
			auto tempVertex = all_vertices.find(u_id); //Set temp to vertex returned by search list
			vertices.push_back({tempVertex->first, tempVertex->second}); //Add it to returnable vertices <vector> 
			doneList->at(u_id) = true; //Set it to visited
		}
		for (auto n : get_neighbours(u_id)) { //For each neighbour of just visited vertex
			if (contains(n.id)) { //If it exists
				if (!doneList->at(n.id)) { //If not visited
					depth_first_search(vertices, n.id, doneList); //Run dfs on it
				}
			}
		}
	}
}

template <typename T> //TODO
vector<vertex<T>> directed_graph<T>::breadth_first(const int& u_id) { //FIFO
	deque<int> toDoList;
 	vector<int> doneList;
 	vector<vertex<T>> vertices;

	doneList.push_back(u_id); //Add first ID to 
	auto tempVertex = all_vertices.find(u_id);
	vertices.push_back({tempVertex->first, tempVertex->second});

	for (int i = 0; i < num_vertices()+1; i++) {
		auto currentTemp = all_vertices.find(i);
		doneList.push_back(i);
		

		for (auto n : get_neighbours(i)) {
			if (!(find(doneList.begin(), doneList.end(), n.id) != doneList.end())) {
				vertices.push_back({currentTemp->first, currentTemp->second});
				doneList.push_back(n.id);
				vertices.push_back(n);
				
			}
	//WORKS, MAKE IT SO IT ADDS INCOMING NEIGHBOURS (VERTICES ABOVE INITIAL)
		}
	}
	
	
	return vertices;
}

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int& u_id) { 
	directed_graph<T> tree;
	vector<vertex<T>> vertices;
	//
	//out_tree.add_vertex(v1);
	//out_tree.add_edge();
	//vertex<double> v1(6, 100);
	auto initalVertex = all_vertices.find(u_id); //Set temp to vertex returned by list
	tree.add_vertex({initalVertex->first, initalVertex->second});

	if (contains(u_id)) {
		int vertices_size = num_vertices();
		
	 	for (int i = 0; i < vertices_size; i++){




	 	}




	 }




	return tree; 
	
}

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T> //Done
vector<vertex<T>> directed_graph<T>::significance_sorting() { 
	vector<vertex<T>> vertices = get_vertices(); //Get all vertices
	for (int i = 1; i < vertices.size(); i++) { //Using Insertion Sort
		vertex<T> x = vertices[i];
		int pos = i-1;
		while (pos >= 0 && vertices[pos].weight < x.weight) {
			vertices[pos+1] = vertices[pos];
			pos--;
		}
		vertices[pos + 1] = x;
	}
	return vertices;
}

#endif