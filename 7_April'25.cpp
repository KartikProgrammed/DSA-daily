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

//416. Partition Equal Subset Sum
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    bool dp(vector<int>& nums,int sum,int curr,vector<vector<int>> &memo){
        if(sum==0){
            return true;
        }
        if(curr>=nums.size() || sum<0){
            return false;
        }
        if(memo[curr][sum]!=-1){
            return memo[curr][sum];
        }
        bool use=dp(nums,sum-nums[curr],curr+1,memo);
        bool notu=dp(nums,sum,curr+1,memo);
        return memo[curr][sum]=use||notu;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum % 2 != 0) return false;
        vector<vector<int>> memo(nums.size(),vector<int>(sum+1,-1));
        return dp(nums,sum/2,0,memo);
    }
};


//62. Unique Paths
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int dp(int x,int y,int m,int n,vector<vector<int>> &memo){
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(memo[x][y]!=-1){
            return memo[x][y];
        }
        int right=0,down=0;
        if(x<m-1){
            down+=dp(x+1,y,m,n,memo);
        }
        if(y<n-1){
            right+=dp(x,y+1,m,n,memo);
        }
        return memo[x][y]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dp(0,0,m,n,memo);
    }
};


//63. Unique Paths II
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 109.


//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int dp(int x,int y,int m,int n,vector<vector<int>> &memo,vector<vector<int>> &grid){
        if(grid[x][y]==1){
            return 0;
        }
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(memo[x][y]!=-1){
            return memo[x][y];
        }
        int right=0,down=0;
        if(x<m-1){
            down+=dp(x+1,y,m,n,memo,grid);
        }
        if(y<n-1){
            right+=dp(x,y+1,m,n,memo,grid);
        }
        return memo[x][y]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> memo(m,vector<int>(n,-1));

        return dp(0,0,m,n,memo,obstacleGrid);

    }
};


//64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

//APPROACH:-
//DP-2D

//CODE:-
class Solution {
public:
    int dp(vector<vector<int>>& grid,vector<vector<int>>& memo,int x,int y){
        int m=grid.size();
        int n=grid[0].size();
        if(x==m-1 && y==n-1){
            return grid[x][y];
        }
        if(memo[x][y]!=-1){
            return memo[x][y];
        }
        int right=INT_MAX,down=INT_MAX;
        if(x<m-1){
            down=grid[x][y]+dp(grid,memo,x+1,y);
        }
        if(y<n-1){
            right=grid[x][y]+dp(grid,memo,x,y+1);
        }
        return memo[x][y]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dp(grid,memo,0,0);
    }
};


//120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

//APPROACH:-
//DP-2D

//CODE:-
class Solution {
public:
    int dp(vector<vector<int>>& triangle,vector<vector<int>>& memo,int x,int y){
        int m=triangle.size();
        int n=triangle[x].size();
        if(x==m-1){
            return triangle[x][y];
        }
        if(memo[x][y]!=-1){
            return memo[x][y];
        }
        int same,right=INT_MAX;
        same=triangle[x][y]+dp(triangle,memo,x+1,y);
        right=triangle[x][y]+dp(triangle,memo,x+1,y+1);
        return memo[x][y]=min(same,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dp(triangle,memo,0,0);
    }
};