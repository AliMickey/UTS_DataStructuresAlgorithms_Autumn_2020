#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	/* test 1 */
	vertex<double> v1(1, 1.25); //Initialise
	vertex<double> v2(2, 2.41);
	vertex<double> v3(3, 3.36);

	directed_graph<double> g1; 

	g1.add_vertex(v1); //Add to graph
	g1.add_vertex(v2);
	g1.add_vertex(v3);

	g1.remove_vertex(2); // remove a vertex by id 

	vector<vertex<double>> result1 = g1.get_vertices(); // Make a list
	for (vertex<double> v : result1) {
		cout << "ID: " << v.id << ", Weight: " << v.weight << endl;
	}

	cout << g1.contains(1) << endl;
	cout << endl;
}

