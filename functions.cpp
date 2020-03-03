#include <iostream>
#include "functions.h"
#include <vector>
#include <sstream>
using namespace std;

//given a file, read the file and put it into a 2 dimensional vector.
vector<vector<string>> readTable (ifstream &file) {
	//all the variables that will be used.
	string line; // the string that will be used to fill all the vectors.
	vector<vector<string>> returnMe; // vector to be sent back to main.
	vector<string> vectorOfLine; // the vector of each of the lines.

	//this while loop will end when it has finished getting all the lines in the file.
	while (getline (file, line)) {   // get a whole line
		stringstream ss (line);//make it a string stream so that we can use getline()
		//this while loop will end when it has finished organizing the whole line
		while (getline (ss, line, ',')) {
			vectorOfLine.push_back (line);
		}
		returnMe.push_back (vectorOfLine);//put the newly found vector of a line into the returning vector.
		vectorOfLine.resize (0);//resize the vector so that the next line values are not stored here.
	}
	return returnMe;
}

void writeTable (ofstream &file, vector<vector<string>> &table) {
	for (int i = 0; i < table.size (); i++) {
		file << table.at (i).at (0);
		for (int x = 1; x < table.at (i).size (); x++) {
			file << "," << table.at (i).at (x);
		}
		file << endl;
	}
}
vector<vector<string>> innerJoin (vector<vector<string>> leftTable, vector<vector<string>> rightTable) {
	vector <string> toAdd;
	vector <vector<string>> returnMe;
	for (int z = 0; z < rightTable.size (); z++) {
		for (int i = 0; i < leftTable.size (); i++) {
			if (leftTable.at (i).at(0) == rightTable.at(z).at(0)){ // if the id's are the same, do this.

				toAdd = leftTable.at(i);
				for (int x = 0; x < rightTable.at(z).size(); x++){
						toAdd.push_back(rightTable.at(z).at(x));
					}
				toAdd.erase(toAdd.begin()+leftTable.at(1).size());
				returnMe.push_back(toAdd);

			}
		}
	}
	return returnMe;
}