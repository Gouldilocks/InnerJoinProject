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
		cout << table.at (i).at (0);
		for (int x = 1; x < table.at (i).size (); x++) {
			cout << "," << table.at (i).at (x);
		}
		cout << endl;
	}
}
vector<vector<string>> innerJoin (vector<vector<string>> leftTable, vector<vector<string>> rightTable) {
	string idToMatch = "";
//for (int i = 0; i < leftTable.size(); i ++){ // for each left table vector, do this.
//	idToMatch = leftTable.at(i).at(0); // get the id to match from the
//	for (int x = 0; x < rightTable.size(); x ++ ){ //for each right table vector, do this.
//		if (rightTable.at(x).at(0).compare(idToMatch) == 0){ // if the ids are the same, then do this.
//			for (int p = 1; p < rightTable.at(x).size(); p++){ // for each value in this id# (except 0), do this.
//				leftTable.at(i).push_back(rightTable.at(x).at(p));
//			}
//		} else continue; // if the strings are not the same, keep going through the ids.
//	}
//}
	vector <vector<string>> returnMe(leftTable.size ());
	vector <string> commons;
	for (int z = 0; z < rightTable.size (); z++) {
		for (int i = 0; i < leftTable.size (); i++) {
			if (leftTable.at (i).at(0) == rightTable.at(z).at(0)){
				commons.push_back(rightTable.at(z).at(0));
			}
		}
	}
	for (int i = 0; i < commons.size (); i++){
		returnMe.at(i).push_back(commons.at(i));
	}
	for (int x = 1; x < leftTable.at(0).size(); x++) {
		for (int i = 0; i < leftTable.size (); i++) { // this loop makes all the ids in the returnMe vector.
			returnMe.at (i).push_back (leftTable.at (i).at (x));
		}
	}
	for (int x = 1; x < rightTable.at(0).size(); x++) {
		for (int i = 0; i < rightTable.size (); i++) { // this loop makes all the ids in the returnMe vector.
			returnMe.at (i).push_back (rightTable.at (i).at (x));
		}
	}

	return returnMe;

}