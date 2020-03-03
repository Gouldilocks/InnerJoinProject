#include <iostream>
#include "functions.h"

using namespace std;

int main () {

	ofstream Results;
	ifstream Users;
	ifstream Cars;


	Cars.open ("CarsTable.csv");
	//Make all of the vectors
	vector<vector<string>> cars = readTable (Cars);
	Cars.close();
	Users.open ("UsersTable.csv");
	vector<vector<string>> users = readTable (Users);
	Users.close();
	vector<vector<string>> join = innerJoin (users, cars);


	Results.open ("Results.csv");
	//Print out the results
	writeTable (Results, join);
	Results.close();
	return 0;
}