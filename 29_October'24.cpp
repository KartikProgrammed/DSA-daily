#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 2684:- Maximum Number of Moves in a Grid
// You are given a 0-indexed m x n matrix grid consisting of positive integers.
// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.

class Solution {
public:
    int recursion(int i,int j,vector<vector<int>> &grid,int m,int n,vector<vector<int>>& memo){
        if (memo[i][j] != -1)
            return memo[i][j];
        
        int curr=grid[i][j];
        int maxMoves = 0;  
        if (i > 0 && j < m - 1 && curr < grid[i - 1][j + 1])
            maxMoves = max(maxMoves, 1 + recursion(i - 1, j + 1, grid, m, n, memo));
        
        if (j < m - 1 && curr < grid[i][j + 1]) 
            maxMoves = max(maxMoves, 1 + recursion(i, j + 1, grid, m, n, memo));
        
        if (i < n - 1 && j < m - 1 && curr < grid[i + 1][j + 1])
            maxMoves = max(maxMoves, 1 + recursion(i + 1, j + 1, grid, m, n, memo));
        
        return memo[i][j] = maxMoves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxMovesCount = 0;
        vector<vector<int>> memo(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            maxMovesCount = max(maxMovesCount, recursion(i, 0, grid, m, n,memo));
        }

        return maxMovesCount;
    }
};