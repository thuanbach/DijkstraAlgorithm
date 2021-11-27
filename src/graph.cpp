/*
 * graph.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include <vector>

using namespace std;

const unsigned int DFS_TOTAL_VERTEXES = 5;
const int MAX_INTEGER = 1000;

void initiate_graph(int graph[DFS_TOTAL_VERTEXES][DFS_TOTAL_VERTEXES]) {

	for (unsigned int i = 0; i < DFS_TOTAL_VERTEXES; i++) {
		for (unsigned int j = 0; j < DFS_TOTAL_VERTEXES; j++) {
			graph[i][j] = MAX_INTEGER;
		}
	}

	graph[0][1] = 1;
	graph[0][4] = 1;

	graph[1][0] = 1;
	graph[1][2] = 1;

	graph[2][1] = 1;
	graph[2][3] = 1;

	graph[3][1] = 1;
	graph[3][2] = 1;
	graph[3][4] = 1;

	graph[4][0] = 1;
	graph[4][1] = 1;
	graph[4][3] = 1;

	return;
}

bool check_if_visited(int vertex, std::vector<int> being_visisted) {

	for (int i = 0; i < being_visisted.size(); i++) {
		if (being_visisted.at(i) == vertex) {
			return true;
		}
	}

	return false;
}

string print_vector(std::vector<int> being_visisted) {
	string result = "[";

	for (int i = 0; i < being_visisted.size(); i++) {

		result.append(to_string(being_visisted.at(i)));
		if (i != being_visisted.size()-1){
			result.append(",");
		}
	}

	result.append("]");

	return result;
}

void depth_first_search_recursive(int vertex,
		int graph[DFS_TOTAL_VERTEXES][DFS_TOTAL_VERTEXES],
		std::vector<int> &being_visisted) {

	for (int i = 0; i < DFS_TOTAL_VERTEXES; i++) {
		if (graph[vertex][i] != MAX_INTEGER
				&& !check_if_visited(i, being_visisted)) {

			being_visisted.push_back(i);
			cout << "Adjacent vertices: " << i << " ";
			cout << "Discovery Visit Order" << print_vector(being_visisted) << " " << endl;
			cout << endl;

			depth_first_search_recursive(i, graph, being_visisted);
		}
	}

	cout << "Finish order " << vertex << endl;

}

void depth_first_search() {

	int graph[DFS_TOTAL_VERTEXES][DFS_TOTAL_VERTEXES];
	initiate_graph(graph);

	bool visited[DFS_TOTAL_VERTEXES];
	for (int i = 0; i < DFS_TOTAL_VERTEXES; i++) {
		visited[0] = false;
	}

	std::vector<int> being_visisted;
	being_visisted.push_back(0);
	//cout << print_vector(being_visisted);

	cout << "Adjacent vertices: "  << " ";
	cout << "Discovery Visit Order" << print_vector(being_visisted) << " " << endl;
	cout << endl;
	depth_first_search_recursive(0, graph, being_visisted);
}
