/*
 * dijkstra_althorighm.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: thuanbachvan
 */

#include "iostream"
#include <vector>
#include "utils.h"

using namespace std;

const unsigned int TOTAL_VERTEXES = 13;
const int MAX_INTEGER = 1000;

void initiate(int graph[TOTAL_VERTEXES][TOTAL_VERTEXES]) {

	for (unsigned int i=0; i< TOTAL_VERTEXES; i++) {
		for (unsigned int j=0; j< TOTAL_VERTEXES; j++) {
			graph[i][j] = MAX_INTEGER;
		}
	}

	graph[0][1] = 3;
	graph[0][3] = 3;
	graph[0][5] = 3;

	graph[1][0] = 3;
	graph[1][2] = 9;
	graph[1][3] = 1;
	graph[1][4] = 3;

	graph[2][1] = 9;
	graph[2][4] = 3;
	graph[2][7] = 9;

	graph[3][0] = 3;
	graph[3][1] = 1;
	graph[3][5] = 5;
	graph[3][6] = 7;

	graph[4][1] = 3;
	graph[4][2] = 3;
	graph[4][6] = 4;
	graph[4][7] = 7;

	graph[5][0] = 3;
	graph[5][3] = 5;
	graph[5][8] = 1;
	graph[5][10] = 7;

	graph[6][3] = 7;
	graph[6][4] = 4;
	graph[6][8] = 2;
	graph[6][9] = 1;

	graph[7][2] = 9;
	graph[7][4] = 7;
	graph[7][9] = 1;
	graph[7][12] = 5;

	graph[8][5] = 1;
	graph[8][6] = 2;
	graph[8][10] = 6;
	graph[8][11] = 3;

	graph[9][6] = 1;
	graph[9][7] = 1;
	graph[9][11] = 4;
	graph[9][12] = 4;


	graph[10][5] = 7;
	graph[10][8] = 6;
	graph[10][11] = 1;

	graph[11][8] = 3;
	graph[11][9] = 4;
	graph[11][10] = 1;
	graph[11][12] = 7;

	graph[12][7] = 5;
	graph[12][9] = 4;
	graph[12][11] = 7;

	return;
}


int find_smallest_distance(int distance[TOTAL_VERTEXES], std::vector<int> unprocessed_vertexes) {

	int smalless = MAX_INTEGER;
	int next_vertex = unprocessed_vertexes.at(0);
	int index = 0;
	for (unsigned int i=0; i<unprocessed_vertexes.size(); i++) {
		if ( distance[unprocessed_vertexes.at(i)] < smalless) {
			smalless = distance[unprocessed_vertexes.at(i)];
			next_vertex = unprocessed_vertexes.at(i);
			index = i;

		}
	}
	unprocessed_vertexes.erase(unprocessed_vertexes.begin(), unprocessed_vertexes.begin()+index); // @suppress("Invalid arguments")
	return next_vertex;
}


void trace_dijstra(std::vector<int> processed_vertexes,
		std::vector<int> unprocessed_vertexes,
		int distance[TOTAL_VERTEXES],
		int preprocessor[TOTAL_VERTEXES] ) {

	cout << "S = " << print_vector(processed_vertexes) << endl;
	cout << "V-S =" << print_vector(unprocessed_vertexes) << endl;

	cout << "Vertex		" << "Distance	" << "Path		" <<endl;
	for (unsigned int i=1; i<TOTAL_VERTEXES; i++) {

		string dis = "";

		if (distance[i] == MAX_INTEGER) {
			dis = "∞";
		} else {
			dis = to_string(distance[i]);
		}

		string paht = "";

		if (preprocessor[i] != -1) {
			paht = to_string(preprocessor[i]) + "->" + to_string(i);
		}


		cout << i <<	"		" << dis << "		" << paht <<endl;

	}
	cout << endl;
}

void find_shortest_paths_by_dijkstra() {

	int graph[TOTAL_VERTEXES][TOTAL_VERTEXES];

	initiate(graph);


	std::vector<int> processed_vertexes;
	processed_vertexes.push_back(0);

	std::vector<int> unprocessed_vertexes;
	unprocessed_vertexes.push_back(1);
	unprocessed_vertexes.push_back(2);
	unprocessed_vertexes.push_back(3);
	unprocessed_vertexes.push_back(4);
	unprocessed_vertexes.push_back(5);
	unprocessed_vertexes.push_back(6);
	unprocessed_vertexes.push_back(7);
	unprocessed_vertexes.push_back(8);
	unprocessed_vertexes.push_back(9);
	unprocessed_vertexes.push_back(10);
	unprocessed_vertexes.push_back(11);
	unprocessed_vertexes.push_back(12);


	int distance[TOTAL_VERTEXES];
	int preprocessor[TOTAL_VERTEXES];

	for (int i=1; i<TOTAL_VERTEXES;i++) {
		if (graph[0][i] != MAX_INTEGER){
			preprocessor[i] = 0;
		} else {
			preprocessor[i] = -1;
		}
		distance[i] = graph[0][i];
	}

	trace_dijstra(processed_vertexes, unprocessed_vertexes, distance, preprocessor);

	while (!unprocessed_vertexes.empty()) {

		int next_vertex = find_smallest_distance(distance, unprocessed_vertexes);
		// cout << "next" << next_vertex << endl;

		std::vector<int> temp;
		for ( int i=0; i<unprocessed_vertexes.size(); i++){
			if (unprocessed_vertexes.at(i) != next_vertex) {
				temp.push_back(unprocessed_vertexes.at(i));
			}

		}

		unprocessed_vertexes = temp;
		processed_vertexes.push_back(next_vertex);


		for (int i=1; i<TOTAL_VERTEXES; i++) {

			if (graph[next_vertex][i] != MAX_INTEGER) {
				if (distance[next_vertex] + graph[next_vertex][i] < distance[i]) {
					distance[i] = distance[next_vertex] + graph[next_vertex][i];
					preprocessor[i] = next_vertex;
				}
			}
		}

		trace_dijstra(processed_vertexes, unprocessed_vertexes, distance, preprocessor);
	}


}
