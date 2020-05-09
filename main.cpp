#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	directed_graph<double> g1;

	vertex<double> v0(0, 0.25); 
	vertex<double> v1(1, 1.41);
	vertex<double> v2(2, 2.32);
	vertex<double> v3(3, 3.66);
	vertex<double> v4(4, 4.22);

	g1.add_vertex(v0);
	g1.add_vertex(v1);
	g1.add_vertex(v2);
	g1.add_vertex(v3);
	g1.add_vertex(v4);

	//g1.remove_vertex(1);

	vector<vertex<double>> vertex_list = g1.get_vertices();
	cout << "Vertices: (id, weight):" << endl;
	for (vertex<double> vt : vertex_list) {
	 	cout << "(" << vt.id << ", " << vt.weight << ") ";
	}
	cout << endl << " " << endl;

	g1.add_edge(0, 2, 10);
	g1.add_edge(0, 3, 20);
	g1.add_edge(1, 4, 30);
	g1.add_edge(2, 4, 40);
	g1.add_edge(4, 0, 50);
	g1.add_edge(0, 1, 60);
	g1.add_edge(2, 1, 20);
	g1.add_edge(1, 3, 20);

	g1.remove_edge(0, 1);

	cout << "Outgoing neigbours of 2 (id, weight):" << endl;
	vector<vertex<double>> neighbour_list = g1.get_neighbours(2);
	for (vertex<double> nb : neighbour_list) {
	 	cout << "(" << nb.id << ", " << nb.weight << ") ";
	}
	cout << endl << " " << endl;

	cout << "Amount of vertices: " << g1.num_vertices() << ", Number of edges: " << g1.num_edges() << endl;

	cout << "Adjacent - 2 & 3: " << g1.adjacent(1,2) << endl;

	cout << "Incoming edges to 1: " << g1.in_degree(1) << " and outgoing edges: " << g1.out_degree(1) << " and total edges: " << g1.degree(1) << endl;

}