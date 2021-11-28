/*
 * graph.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include <vector>
#include "utils.h"


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

void trace_dfs(int operation, int adjacent_vertices, std::vector<int> being_visisted, std::vector<int> fnished_orders){
	string adjacent = "";

	string finished_order_str = "";


	string operation_str = "";
	if (operation != -1) {
		operation_str = to_string(operation);
	}

	string adjcent_str = "";
	if (adjacent_vertices != -1) {
		adjcent_str = to_string(adjacent_vertices);
	}

	cout << operation_str << "\t\t" << adjcent_str << "\t" << print_vector(being_visisted) <<"\t\t" << print_vector(fnished_orders) << endl;
	cout << endl;
}



void depth_first_search_recursive(int vertex,
		int graph[DFS_TOTAL_VERTEXES][DFS_TOTAL_VERTEXES],
		std::vector<int> &being_visisted,
		std::vector<int> &fnished_orders) {

	for (int i = 0; i < DFS_TOTAL_VERTEXES; i++) {
		if (graph[vertex][i] != MAX_INTEGER
				&& !check_if_visited(i, being_visisted)) {

			being_visisted.push_back(i);

			trace_dfs(0, i, being_visisted, fnished_orders);

			depth_first_search_recursive(i, graph, being_visisted,fnished_orders);
		}
	}
	fnished_orders.push_back(vertex);
	trace_dfs(0, -1, being_visisted, fnished_orders);
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

	std::vector<int> fnished_orders;

	cout << "Operation " << "Adjacent Vertices " << "Discovery (Visit) Order " << "Finish Order	" << endl;

	trace_dfs(0,-1, being_visisted, fnished_orders);

	depth_first_search_recursive(0, graph, being_visisted, fnished_orders);
}
