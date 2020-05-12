#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	directed_graph<double> g1;

	vertex<double> v1(1, 800); //A
	vertex<double> v2(2, 3000); //B
	vertex<double> v3(3, 400); //C
	vertex<double> v4(4, 710); //D
	vertex<double> v5(5, 221); //E

	g1.add_vertex(v1);
	g1.add_vertex(v2);
	g1.add_vertex(v3);
	g1.add_vertex(v4);
	g1.add_vertex(v5);
	//g1.remove_vertex(1);

	g1.add_edge(1, 2, 6); //A-B
	g1.add_edge(1, 3, 9); //A-C 
	g1.add_edge(3, 4, 4); //C-D
	g1.add_edge(4, 3, 7); //D-C
	g1.add_edge(4, 1, 1); //D-A
	g1.add_edge(4, 5, 5); //D-E
	g1.add_edge(2, 5, 3); //B-E
	//g1.remove_edge(0, 1);


	//Tests
	vector<vertex<double>> vertex_list = g1.get_vertices();
	cout << "Vertices: (id, weight):" << endl;
	for (vertex<double> vt : vertex_list) {
	 	cout << "(" << vt.id << ", " << vt.weight << ") ";
	}
	cout << endl << " " << endl;

	cout << "Outgoing neighbours of 4 (id, weight):" << endl;
	vector<vertex<double>> neighbour_list = g1.get_neighbours(4);
	for (vertex<double> nb : neighbour_list) {
	 	cout << "(" << nb.id << ", " << nb.weight << ") ";
	}

	cout << endl << " " << endl;

	cout << "Second order neighbours of 4 (id, weight):" << endl;
	vector<vertex<double>> secondOrderNeighbour_list = g1.get_second_order_neighbours(4);
	for (vertex<double> snb : secondOrderNeighbour_list) {
	 	cout << "(" << snb.id << ", " << snb.weight << ") ";
	}

	cout << endl << " " << endl;

	cout << "Is 5 reachable from 1: " << g1.reachable(1, 5) << endl;
	

	cout << "DFS from 1: " << endl;
	//vector<vertex<double>> dfs_list = g1.depth_first(1);
	//for (vertex<double> snb : dfs_list) {
	 	//cout << "(" << snb.id << ", " << snb.weight << ") ";
	//}


	cout << "Amount of vertices: " << g1.num_vertices() << ", Number of edges: " << g1.num_edges() << endl;

	cout << "Adjacent - 2 & 5: " << g1.adjacent(2,5) << endl;

	cout << "Incoming edges to 3: " << g1.in_degree(4) << " and outgoing edges: " << g1.out_degree(4) << " and total edges: " << g1.degree(4) << endl;

}