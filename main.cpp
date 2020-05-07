#include "directed_graph.hpp" // contains two classes: vertex, directed_graph

int main() {

	/* test 1 */
	vertex<double> v1(1, 1.25); // use the constructor to create a vertex
								// double is the data type for vertex weight
								// the vertex object v1 has an id (i.e., 1) and a double-typed weight (i.e. 1.25)
	vertex<double> v2(2, 2.41);
	vertex<double> v3(3, 3.36);

	directed_graph<double> g1; 	// the double data type means the same at the vertex class
								//the weight of each vertex is a double
	g1.add_vertex(v1);
	g1.add_vertex(v2);
	g1.add_vertex(v3);
	g1.remove_vertex(2); // remove a vertex by id 

	vector<vertex<double>> result1 = g1.get_vertices(); // give us the vector of all vertices g1
	for (vertex<double> v : result1) {
		cout << v.id << ' ' << v.weight << endl;
	}
	cout << endl;


	/* test 2 */
	vertex<char> va(1, 'a'); // the weight of each vertex now is a char value
							 // each char correponds to a int value: 'a'<'b'
							 // chars are also comparable to each other
	vertex<char> vb(2, 'b');
	vertex<char> vc(3, 'c');

	directed_graph<char> g2;
	g2.add_vertex(va);
	g2.add_vertex(vb);
	g2.add_vertex(vc);
	g2.remove_vertex(2); // remove the second vertex by its id, which is 2

	vector<vertex<char>> result2 = g2.get_vertices();
	for (vertex<char> v : result2) {
		cout << v.id << ' ' << v.weight << endl;
	}
	cout << endl;
}

