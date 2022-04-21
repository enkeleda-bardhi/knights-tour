//
//  main.cpp
//  Knight'sTour
//
//  Created by Enkeleda Bardhi on 19.1.20.
//  Copyright © 2020 Enkeleda Bardhi. All rights reserved.
//

#include "KnightTour.hpp"
#include <iostream>

using namespace std;

int main() {
    int currentRow, currentColumn;
    cout << "Please give the inititial position of the knight!" << endl;
    cout << "Row number(from 1 to 8): ";
    cin >> currentRow;
    cout << "Column number(from 1 to 8): ";
    cin >> currentColumn;
    cout << endl;
    KnightTour myKnightTour(currentRow, currentColumn);
    myKnightTour.solveTour();
}
