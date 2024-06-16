#include <iostream>

#include "showcase.h"

using namespace std;

int main() 
{
    cout << "** Various algorithms showcase with example data **" << endl << endl;

    cout << "* Sorting algorithms with their runtimes for comparison: *" << endl << endl;
    ShowcaseSortingAlgorithms();

    cout << "* Searching algorithms with their runtimes for comparison: *" << endl << endl;
    ShowcaseSearchingAlgorithms();

    cout << "* String related algorithms with their input and results: *" << endl << endl;
    ShowcaseStringAlgorithms();

    cout << "* Problems solved using dynamic programming: *" << endl << endl;
    ShowcaseDynamicProgrammingAlgorithms();

    cout << "* Backtracking algorithms: *" << endl << endl;
    ShowcaseBacktrackingAlgorithms();

    cout << "* Graph algorithms: *" << endl << endl;
    ShowcaseGraphAlgorithms();

    cout << "* Miscellaneous algorithms: *" << endl << endl;
    ShowcaseMiscellaneousAlgorithms();

    return 0;
}
