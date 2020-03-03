#ifndef PROGRAM3_FUNCTIONS_H
#define PROGRAM3_FUNCTIONS_H

#include <vector>
#include <fstream>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

vector<vector<string>> readTable(ifstream &file);
void writeTable(ofstream &file, vector<vector<string>> &table);
vector<vector<string>> innerJoin(vector<vector<string>> leftTable, vector<vector<string>> rightTable);

#endif //PROGRAM3_FUNCTIONS_H
