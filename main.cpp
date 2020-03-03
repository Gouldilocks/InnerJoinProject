#include <iostream>
#include "functions.h"

int main() {
    std::ofstream file("../Results.csv");

    file << "Hello World" << std::endl;

    return 0;
}