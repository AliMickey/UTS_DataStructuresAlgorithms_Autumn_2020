/*
* A main function for you to build and run your
* own tests with.
* This file is not part of the marking, so you
* can do anything you want here.
*/
#include <iostream>

#include "directed_graph_algorithms.cpp"

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

	g1.add_edge(1, 2, 6); //A-B
	g1.add_edge(1, 3, 9); //A-C 
	g1.add_edge(3, 4, 4); //C-D
	g1.add_edge(4, 3, 7); //D-C
	g1.add_edge(4, 1, 1); //D-A
	g1.add_edge(4, 5, 5); //D-E
	g1.add_edge(2, 5, 3); //B-E

	cout << "Shortest Path: " << endl;
	vector<vertex<double>> sp = shortest_path<double>(g1, 1, 2);
    for (vertex<double> spv : sp) {
		cout << "(" << spv.id << ", " << spv.weight << ") ";   
    }

	cout << endl;

    cout << "Strongly connected: " << endl;
	vector<vector<vertex<double>>> sc = strongly_connected_components(g1);
	int count = 0;
	for (vector<vertex<double>> scv : sc) {
		cout << "Pair: " << scv.at(0).id << " ";
            for (vertex<double> scva : scv) {
	 	        cout << "(" << scva.id << ", " << scva.weight << ") ";   
				count ++;
            }     
    }
	cout << "Total: " << count << " " << endl;

 
}