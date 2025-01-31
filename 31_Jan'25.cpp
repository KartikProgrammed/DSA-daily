#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 827. Making A Large Island
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

//APPROACH:-
//since the constraints are too tight brute force wont work
//we use an approach wherein we think of mapping the size of islands already present without flipping any water to land
//map the size and a unique id of the island in a unordered map
//calculate the total size by adding 1 to the neighbouring islands of a water

//CODE:-
class Solution {
public:
    int DFS(vector<vector<bool>>&visited ,vector<vector<int>> &grid,int id,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || visited[i][j]==true){
            return 0;
        }
        grid[i][j]=id;
        visited[i][j]=true;
        
        return 1+DFS(visited,grid,id,i-1,j)+DFS(visited,grid,id,i+1,j) +DFS(visited,grid,id,i,j-1) +DFS(visited,grid,id,i,j+1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> map;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int currid=2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int size=DFS(visited,grid,currid,i,j);
                    map[currid]=size;
                    currid++;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    int curr=1;
                    unordered_set<int> neighbors; 
                    if (i > 0) neighbors.insert(grid[i - 1][j]);
                    if (i < m - 1) neighbors.insert(grid[i + 1][j]);
                    if (j > 0) neighbors.insert(grid[i][j - 1]);
                    if (j < n - 1) neighbors.insert(grid[i][j + 1]);
                    for(int iter:neighbors){
                        curr+=map[iter];
                    }
                    res=max(curr,res);
                }
            }
        }
        if (res == 0) {
            res = m * n;
        }
        return res;
    }
};