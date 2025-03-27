#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2780. Minimum Index of a Valid Split
// An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
// You are given a 0-indexed integer array nums of length n with one dominant element.
// You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
// 0 <= i < n - 1
// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
// Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
// Return the minimum index of a valid split. If no valid split exists, return -1.

//APPROACH:-
//try split at each ind from 0

//CODE:-
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for(int num:nums){
            map2[num]++;
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            map1[num]++;
            map2[num]--;

            int n1=i+1;
            int n2=n-i-1;

            if(map1[num]>n1/2 && map2[num]>n2/2){
                return i;
            }
        }
        return -1;
    }
};


// 733. Flood Fill
// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:
// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.


//APPROACH:-
//BFS

//CODE:-
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]==color){
            return image;
        }
        q.push({sr,sc});
        int curr=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x>0 && image[x-1][y]==curr){
                image[x-1][y]=color;
                q.push({x-1,y});
            }
            if(x<m-1 && image[x+1][y]==curr){
                image[x+1][y]=color;
                q.push({x+1,y});
            }
            if(y>0 && image[x][y-1]==curr){
                image[x][y-1]=color;
                q.push({x,y-1});
            }
            if(y<n-1 && image[x][y+1]==curr){
                image[x][y+1]=color;
                q.push({x,y+1});
            }
        }
        return image;
    }
};


//542. 01 Matrix
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two cells sharing a common edge is 1.

//APPROACH:-
//BFS

//CODE:-
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && res[newX][newY] == -1) {
                    res[newX][newY] = res[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return res;
    }
};


//130. Surrounded Regions
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

//APPROACH:-
//DFS - poorly worded - eliminate all Os who are not connected to a O on the edge

//CODE:-
//1st try
class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& keep,int x,int y){
        if(!keep[x][y]){
            int m=board.size();
            int n=board[0].size();
            keep[x][y]=true;
            if(x>0 && board[x-1][y]=='O'){
                dfs(board,keep,x-1,y);
            }
            if(x<m-1 && board[x+1][y]=='O'){
                dfs(board,keep,x+1,y);
            }
            if(y>0 && board[x][y-1]=='O'){
                dfs(board,keep,x,y-1);
            }
            if(y<n-1 && board[x][y+1]=='O'){
                dfs(board,keep,x,y+1);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> keep(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,keep,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(board,keep,i,n-1);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(board,keep,0,i);
            }
            if(board[m-1][i]=='O'){
                dfs(board,keep,m-1,i);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!keep[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};