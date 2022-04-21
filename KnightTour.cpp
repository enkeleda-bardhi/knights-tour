//
//  Knight'sTour.cpp
//  Knight'sTour
//
//  Created by Enkeleda Bardhi on 19.1.20.
//  Copyright © 2020 Enkeleda Bardhi. All rights reserved.
//

#include "KnightTour.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#define N 8
using namespace std;

    int horizontal[N] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[N] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int row;
    int column;

KnightTour::KnightTour(int currentRow, int currentColumn) {
    row = currentRow;
    column = currentColumn;
}

KnightTour::~KnightTour() {
    
}

    bool KnightTour::isSafe(int chessBoard[N][N]) {
        if ((row>=0 && row<N) && (column>=0 && column<N) && chessBoard[row][column] == 0) {
            return true; // Returns true if the move is safe
        } else {
            return false; // Returns false if the move isn't safe
        }
    }
    
    void KnightTour::printSolution(int chessBoard[N][N]) {
        cout << "The Knight's Tour" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << setw(3) << chessBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int KnightTour::accessibility(int chessBoard[N][N], int accessibility[N][N]) {
        int bestMove = 8;
        int accessibilityNumber = 9;
        for (int i = 0; i < N; i++) {
            int newRow = row + vertical[i];
            int newColumn = column + horizontal[i];
            if (isSafe(chessBoard) && (accessibility[newRow][newColumn] < accessibilityNumber)) {
                accessibilityNumber = accessibility[newRow][newColumn];
                bestMove = i;
            }
        }
        return bestMove;
    }
    
    void KnightTour::solveTour() {
        int board[N][N] = {0};
        int accessibilityBoard[N][N] = {{2, 3, 4, 4, 4, 4, 3, 2},
                                        {3, 4, 6, 6, 6, 6, 4, 3},
                                        {4, 6, 8, 8, 8, 8, 6, 4},
                                        {4, 6, 8, 8, 8, 8, 6, 4},
                                        {4, 6, 8, 8, 8, 8, 6, 4},
                                        {4, 6, 8, 8, 8, 8, 6, 4},
                                        {3, 4, 6, 6, 6, 6, 4, 3},
                                        {2, 3, 4, 4, 4, 4, 3, 2}};
        int moveNumber, counter = 1; // Declares and inicializes currentRow, currentColumn, counter(counting starts from 1)
        board[row][column] = counter; // Gives the first position of the knight the value of counter
        counter++; // Increments counter
        while (counter <= 64) {
            moveNumber = accessibility(board, accessibilityBoard);
            if (moveNumber == 9) {
                printSolution(board);
                break;
            } else {
                row += vertical[moveNumber];
                column += horizontal[moveNumber];
                board[row][column] = counter;
                for (int i = 0; i < N; i++) {
                    int newRow = row + vertical[i];
                    int newColumn = column + horizontal[i];
                    if (isSafe(board)) {
                        accessibilityBoard[newRow][newColumn]--;
                    }
                }
                counter++;
            }
            cout << endl;
        }
        
        // Prints board if the while loop ended when counter reached value 64
        printSolution(board);
    }
    
