#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

// 3363. Find the Maximum Number of Fruits Collected

// There is a game dungeon comprised of n x n rooms arranged in a grid.
// You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
// The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
// The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
// The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
// The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
// When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
// Return the maximum number of fruits the children can collect from the dungeon.

// Approach:
// Use dynamic programming to calculate the maximum number of fruits collected by each child at each step.
// The state can be represented by the positions of the three children and the number of fruits collected so far.
// The transitions will depend on the possible moves of each child, and we will keep track of the maximum fruits collected.

// CODE:
class Solution {
private:
    int n;
    
    // row = i, col = j
    int dfs3(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;

        if(memo[row][col] != -1){return memo[row][col];}
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs3(row + 1, col + 1, mat));
        }
        else if (row - 1 == col) {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat)});
        }
        else {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat),
                       dfs3(row - 1, col + 1, mat)});
        }
        
        return memo[row][col] = val + res;
    }

    int dfs2(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;

        if(memo[row][col] != -1){return memo[row][col];}
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs2(row + 1, col + 1, mat));
        }
        else if (row == col - 1) {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat)});
        }
        else {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat),
                       dfs2(row + 1, col - 1, mat)});
        }
        
        return memo[row][col] = val + res;
    }

public:
    vector<vector<int>> memo;
    int maxCollectedFruits(vector<vector<int>>& mat) {
        n = mat.size();
        int total = 0;

        memo = vector<vector<int>> (n, vector<int> (n, -1));

        // child - 1
        // he will eat all diagonal fruits, so set them to 0 
        for (int i = 0; i < n; i++) {
            total += mat[i][i];
            mat[i][i] = 0;
        }
        
        // child - 2
        total += dfs3(n - 1, 0, mat);
        // child - 3
        total += dfs2(0, n - 1, mat);

        return total;
    }
};