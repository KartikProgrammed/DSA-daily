#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2257. Count Unguarded Cells in the Grid
// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i]= [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

//CODE:-
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 0 = free, 1 = guard, 2 = wall, 3 = guardable
        
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        auto mark_guarded = [&](int r, int c) {
            for (int row = r + 1; row < m; row++) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            for (int row = r - 1; row >= 0; row--) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            for (int col = c + 1; col < n; col++) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
            for (int col = c - 1; col >= 0; col--) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
        };
        
        for (const auto& guard : guards) {
            mark_guarded(guard[0], guard[1]);
        }
        
        int res = 0;
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 0) res++;
            }
        }
        
        return res;
    }
};