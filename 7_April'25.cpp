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

