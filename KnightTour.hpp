//
//  Knight'sTour.hpp
//  Knight'sTour
//
//  Created by Enkeleda Bardhi on 19.1.20.
//  Copyright © 2020 Enkeleda Bardhi. All rights reserved.
//

#ifndef KnightTour_hpp
#define KnightTour_hpp

#include <stdio.h>
#define N 8
class KnightTour {
private:
    int currentRow, currentColumn;
public:
    KnightTour(int, int);
    ~KnightTour();
    bool isSafe(int [N][N]); // Checkes if making a new move is safe
    void printSolution(int [N][N]); // Prints the board
    int accessibility(int [N][N], int [N][N]); // Returns the number of the best posible move
    void solveTour();
};
#endif /* KnightTour_hpp */
