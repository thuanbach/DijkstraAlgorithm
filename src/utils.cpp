/*
 * utils.cpp
 *
 *  Created on: Nov 28, 2021
 *      Author: thuanbachvan
 */


#include <iostream>
#include <vector>

using namespace std;

string print_vector(std::vector<int> vector) {
	string result = "[";

	for (int i = 0; i < vector.size(); i++) {

		result.append(to_string(vector.at(i)));
		if (i != vector.size()-1){
			result.append(",");
		}
	}

	result.append("]");

	return result;
}
