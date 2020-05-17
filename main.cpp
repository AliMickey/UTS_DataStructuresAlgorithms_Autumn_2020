#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	directed_graph<double> g1;

	vertex<double> v1(1, 800); //A
	vertex<double> v2(2, 3000); //B
	vertex<double> v3(3, 400); //C
	vertex<double> v4(4, 710); //D
	vertex<double> v5(5, 221); //E
	vertex<double> v6(6, 100);

	g1.add_vertex(v1);
	g1.add_vertex(v2);
	g1.add_vertex(v3);
	g1.add_vertex(v4);
	g1.add_vertex(v5);
	g1.add_vertex(v6);
	//g1.remove_vertex(1);


	//Edges for BFS and Tree
	// g1.add_edge(1,2,1);
	// g1.add_edge(1,3,2);
	// g1.add_edge(2,4,3);
	// g1.add_edge(2,5,4);
	// g1.add_edge(3,6,5);

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
	vector<vertex<double>> neighbour_list = g1.get_neighbours(2);
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

	cout << "DFS from 2: " << endl;
	vector<vertex<double>> dfs_list = g1.depth_first(1);
	for (vertex<double> x : dfs_list) {
	 	cout << "(" << x.id << ", " << x.weight << ") ";
	}
	cout << endl << " " << endl;

	cout << "BFS from 2: " << endl;
	vector<vertex<double>> bfs_list = g1.breadth_first(1);
	for (vertex<double> x : bfs_list) {
	 	cout << "(" << x.id << ", " << x.weight << ") ";
	}
	cout << endl << " " << endl;

	cout << "Tree from 1: " << endl;

	vector<vertex<double>> tree = g1.out_tree(1).get_vertices();	
	for (vertex<double> vt : tree) {
	 	cout << "(" << vt.id << ", " << vt.weight << ") ";
	}

	cout << endl << " " << endl;

	cout << "Amount of vertices: " << g1.num_vertices() << ", Number of edges: " << g1.num_edges() << endl;

	cout << "Reachable: 1 & 5: " << g1.reachable(4, 5) << endl;

	cout << "Adjacent: 2 & 5: " << g1.adjacent(2,5) << endl;

	cout << "Contain Cycles: " << g1.contain_cycles() << endl;

	cout << "Significance: " << endl;
	vector<vertex<double>> significance = g1.significance_sorting();
	for (vertex<double> x : significance) {
	 	cout << "(" << x.id << ", " << x.weight << ") ";
	}
	cout << endl << " " << endl;

	cout << "Incoming/outgoing/total edges to 3: " << g1.in_degree(3) << "/" << g1.out_degree(3) << "/" << g1.degree(3) << endl;

}