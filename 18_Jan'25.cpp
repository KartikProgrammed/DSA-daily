#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

//1368. Minimum Cost to Make at Least One Valid Path in a Grid
// Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
// 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
// 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
// 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
// 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
// Notice that there could be some signs on the cells of the grid that point outside the grid.
// You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
// Return the minimum cost to make the grid have at least one valid path.

//APPROACH 1:- DP with memoisation (fails badly wont even run)
//CODE:-
class Solution {
public:
    int recursion(vector<vector<int>>& grid,vector<vector<int>>& memo,int currcost,int i,int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return INT_MAX;
        }
        if(i==grid.size()-1 && j==grid[i].size()-1){
            return currcost;
        }
        if (memo[i][j] != -1) return memo[i][j];
        int r1=INT_MAX;
        int r2=INT_MAX;
        int r3=INT_MAX;

        if(grid[i][j]==1 && j<m-1){
            r1=recursion(grid,memo,currcost,i,j+1);
        }
        else if(grid[i][j]==2 && j>0){
            r1=recursion(grid,memo,currcost,i,j-1);
        }
        else if(grid[i][j]==3 && i<n-1){
            r1=recursion(grid,memo,currcost,i+1,j);
        }
        else if(grid[i][j]==4 && i>0){
            r1=recursion(grid,memo,currcost,i-1,j);
        }
        if(i<n-1){
            r3=recursion(grid,memo,currcost+1,i+1,j);
        }
        if(j<m-1){
            r2=recursion(grid,memo,currcost+1,i,j+1);
        }
        return memo[i][j]=min({r1,r2,r3});
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return recursion(grid,memo,0,0,0);
    }
};

//APPROACH 2:-
//Dijkstra's algorithm

//CODE:-
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; //min-heap of int
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        result[0][0] = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop(); //log(size of pq)

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(result[i][j] < currCost) {
                continue;
            }

            for(int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir-1 != dir_i) ? 1 : 0);

                    int newCost = currCost + dirCost;

                    if(newCost < result[i_][j_]) {
                        result[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};

