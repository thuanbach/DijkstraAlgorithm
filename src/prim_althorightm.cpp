/*
 * dijkstra_althorighm.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: thuanbachvan
 */

#include "iostream"
#include <vector>


using namespace std;

const unsigned int TOTAL_VERTEXES = 13;
const int MAX_INTEGER = 1000;

void initiate_prim(int graph[TOTAL_VERTEXES][TOTAL_VERTEXES]) {

	for (unsigned int i=0; i< TOTAL_VERTEXES; i++) {
		for (unsigned int j=0; j< TOTAL_VERTEXES; j++) {
			graph[i][j] = MAX_INTEGER;
		}
	}

	graph[0][1] = 50;
	graph[0][2] = 40;
	graph[0][3] = 260;

	graph[1][0] = 50;
	graph[1][2] = 60;


	graph[2][0] = 40;
	graph[2][1] = 60;
	graph[2][6] = 155;
	graph[2][7] = 120;


	graph[3][0] = 260;
	graph[3][4] = 148;
	graph[3][5] = 180;


	graph[4][3] = 148;
	graph[4][5] = 120;


	graph[5][3] = 180;
	graph[5][4] = 120;
	graph[5][6] = 180;


	graph[6][2] = 155;
	graph[6][5] = 180;
	graph[6][7] = 150;
	graph[6][8] = 180;

	graph[7][2] = 120;
	graph[7][6] = 150;
	graph[7][8] = 130;


	graph[8][6] = 180;
	graph[8][7] = 130;
	graph[8][9] = 320;


	graph[9][8] = 320;


	return;
}


int find_smallest_dis(int distance[TOTAL_VERTEXES], std::vector<int> unprocessed_vertexes) {

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
	//unprocessed_vertexes.erase(unprocessed_vertexes.begin(), unprocessed_vertexes.begin()+index); // @suppress("Invalid arguments")
	return next_vertex;
}

void find_spanning_tree() {

	int graph[TOTAL_VERTEXES][TOTAL_VERTEXES];

	initiate_prim(graph);


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


	int distance[TOTAL_VERTEXES];
	int preprocessor[TOTAL_VERTEXES];

	for (int i=1; i<TOTAL_VERTEXES;i++) {
		if (graph[0][i] != MAX_INTEGER){
			preprocessor[i] = 0;
		}
		distance[i] = graph[0][i];
	}

	while (!unprocessed_vertexes.empty()) {

		int next_vertex = find_smallest_dis(distance, unprocessed_vertexes);

		cout << "Next vertex: " << next_vertex;

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


	}

//	cout << "Vertex		" << "Distance		" << "Path		" <<endl;
//
//	for (unsigned int i=0; i<TOTAL_VERTEXES; i++) {
//
//		cout << i << "		" << distance[i] << "		" << preprocessor[i] <<endl;
//	}
}
