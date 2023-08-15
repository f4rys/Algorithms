#include <iostream>

#include "showcase.h"

using namespace std;

int main() {

    cout << "** Various algorithms showcase with example data **" << endl << endl;

    cout << "* Searching algorithms with their runtimes for comparison: *" << endl << endl;
    ShowcaseSearchingAlgorithms();

    cout << "* Sorting algorithms with their runtimes for comparison: *" << endl << endl;
    ShowcaseSortingAlgorithms();

    cout << "* String related algorithms with their input and results: *" << endl << endl;
    ShowcaseStringAlgorithms();

    cout << "* Problems solved using dynamic programming: *" << endl << endl;
    ShowcaseDynamicProgrammingAlgorithms();

    cout << "* Miscellanous algorithms: *" << endl << endl;
    ShowcaseMiscellanousAlgorithms();

    cout << "* Backtracking algorithms: *" << endl << endl;
    ShowcaseBacktrackingAlgorithms();

    return 0;
}
