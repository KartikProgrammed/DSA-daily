#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//407. Trapping Rain Water II
// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

//CODE:-
class Solution {
public:
    int trapRainWater(vector<vector<int>>& map) {
        int r=map.size(), c=map[0].size();
        // to store {height, row, col}, min heap
        // as need to process lower height first (starting from the boundary)
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        // add boundary cells of the grid, water can't fill in these cells
        for(int i=0; i<r; i++){
            pq.push({map[i][0], i, 0});
            pq.push({map[i][c-1], i, c-1});
            visited[i][0] = visited[i][c-1] = true;
        }
        for(int j=1; j<c-1; j++){
            pq.push({map[0][j], 0, j});
            pq.push({map[r-1][j], r-1, j});
            visited[0][j] = visited[r-1][j] = true;
        }

        vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        int volume = 0;
        while(!pq.empty()){
            vector<int> n = pq.top();
            pq.pop();
            int height=n[0], row=n[1], col=n[2];
            // move to adjacent cells, check if water can fill those cell if its height is smaller
            for(auto &move:direction){
                int next_row = row+move[0], next_col = col+move[1];
                // if next move is inside grid and cell is not visited
                if(next_row>=0 && next_row<r && next_col>=0 && next_col<c && !visited[next_row][next_col]){
                    visited[next_row][next_col] = true;
                    // if curr height is greater than next cell's height
                    if(height > map[next_row][next_col]){
                        // fill water in next cell upto curr height and push it with updated height
                        volume += height - map[next_row][next_col];
                        pq.push({height, next_row, next_col});
                    }
                    // water can't be filled in next cell (as water will flow out to adjacent lower height)
                    else pq.push({map[next_row][next_col], next_row, next_col});
                }
            }
        }
        return volume;
    }
};