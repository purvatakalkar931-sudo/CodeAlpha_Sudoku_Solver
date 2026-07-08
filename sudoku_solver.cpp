#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 9;

void printGrid(const vector<vector<int>>& grid) {
    for (int r = 0; r < SIZE; r++) {
        if (r % 3 == 0 && r != 0) cout << "------+-------+------\n";
        for (int c = 0; c < SIZE; c++) {
            if (c % 3 == 0 && c != 0) cout << "| ";
            cout << grid[r][c] << " ";
        }
        cout << "\n";
    }
}

bool isValid(const vector<vector<int>>& grid, int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) return false;
        if (grid[i][col] == num) return false;
    }

    int boxRowStart = (row / 3) * 3;
    int boxColStart = (col / 3) * 3;
    for (int r = boxRowStart; r < boxRowStart + 3; r++) {
        for (int c = boxColStart; c < boxColStart + 3; c++) {
            if (grid[r][c] == num) return false;
        }
    }

    return true;
}

bool findEmptyCell(const vector<vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) return true;
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    if (!findEmptyCell(grid, row, col)) {
        return true; 
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0; 
        }
    }

    return false; 
}

int main() {
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Puzzle:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists for this puzzle.\n";
    }

    return 0;
}
