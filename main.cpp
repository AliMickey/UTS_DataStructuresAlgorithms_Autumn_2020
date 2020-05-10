#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	directed_graph<double> g1;

	vertex<double> v0(0, 800); //A
	vertex<double> v1(1, 3000); //B
	vertex<double> v2(2, 400); //C
	vertex<double> v3(3, 710); //D
	vertex<double> v4(4, 221); //E

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

	g1.add_edge(0, 1, 6); //A-B
	g1.add_edge(0, 2, 9); //A-C 
	g1.add_edge(2, 3, 4); //C-D
	g1.add_edge(3, 2, 7); //D-C
	g1.add_edge(3, 0, 1); //D-A
	g1.add_edge(3, 4, 5); //D-E
	g1.add_edge(1, 4, 3); //B-E

	//g1.remove_edge(0, 1);

	cout << "Outgoing neigbours of 2 (id, weight):" << endl;
	vector<vertex<double>> neighbour_list = g1.get_neighbours(2);
	for (vertex<double> nb : neighbour_list) {
	 	cout << "(" << nb.id << ", " << nb.weight << ") ";
	}
	cout << endl << " " << endl;

	cout << "Amount of vertices: " << g1.num_vertices() << ", Number of edges: " << g1.num_edges() << endl;

	cout << "Adjacent - 2 & 3: " << g1.adjacent(2,3) << endl;

	cout << "Incoming edges to 3: " << g1.in_degree(3) << " and outgoing edges: " << g1.out_degree(3) << " and total edges: " << g1.degree(3) << endl;

}