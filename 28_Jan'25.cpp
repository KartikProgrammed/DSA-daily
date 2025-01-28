#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
using namespace std;

//2658. Maximum Number of Fish in a Grid
//You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:
// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

//APPROACH:-
//Apply dfs and search in all directions
//add up fishes in each direction and return the max of ponds

//CODE:-
class Solution {
public:
    int dfs(vector<vector<bool>> &visited,int row,int col,vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        if(grid[row][col]==0){
            return 0;
        }
        if(visited[row][col]){
            return 0;
        }
        visited[row][col]=true;
        int fish=grid[row][col];
        
        if(row>0){
            fish+=dfs(visited,row-1,col,grid);
        }
        if(row<m-1){
            fish+=dfs(visited,row+1,col,grid);
        }
        if(col>0){
            fish+=dfs(visited,row,col-1,grid);
        }
        if(col<n-1){
            fish+=dfs(visited,row,col+1,grid);
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    vector<vector<bool>> visited(m,vector<bool>(n,false));
                    int curr=dfs(visited,i,j,grid);
                    res=curr>res?curr:res;
                }
            }
        }
        return res;
    }
};