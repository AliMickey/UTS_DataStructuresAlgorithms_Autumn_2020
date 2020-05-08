#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	directed_graph<double> g1;

	vertex<double> v0(0, 0.25); 
	vertex<double> v1(1, 1.41);
	vertex<double> v2(2, 2.32);
	vertex<double> v3(3, 3.66);
	vertex<double> v4(4, 4.12);

	g1.add_vertex(v0);
	g1.add_vertex(v1);
	g1.add_vertex(v2);
	g1.add_vertex(v3);
	g1.add_vertex(v4);

	g1.remove_vertex(1);

	vector<vertex<double>> vertex_list = g1.get_vertices();
	cout << "all vertices: ";
	for (vertex<double> vt : vertex_list) {
	 	cout << "(" << vt.id << ", " << vt.weight << ") ";
	}
	cout << endl;

	g1.add_edge(0, 2, 10);
	g1.add_edge(0, 3, 20);
	g1.add_edge(2, 0, 30);
	g1.add_edge(2, 4, 40);
	g1.add_edge(4, 0, 50);
	g1.add_edge(3, 4, 60);

	cout << "all neighbours of 0: ";
	vector<vertex<double>> neighbour_list = g1.get_neighbours(0);
	for (vertex<double> nb : neighbour_list) {
	 	cout << "(" << nb.id << ", " << nb.weight << ") ";
	}
	cout << endl;

}