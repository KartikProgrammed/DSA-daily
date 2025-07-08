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

// 1751. Maximum Number of Events That Can Be Attended II
// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
// You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
// Return the maximum sum of values that you can receive by attending events.


// Approach:
//Use dynamic programming to solve the problem.

// CODE:
class Solution {
public:
    unordered_map<string, int> memo;
    int dp(vector<vector<int>>& events,int curr,int time,int k){
        if(curr>=events.size()){
            return 0;
        }
        string key = to_string(curr) + "," + to_string(time) + "," + to_string(k);
        if (memo.count(key)) return memo[key];
        int op1=INT_MIN;

        if(time<events[curr][0] && k>0){
            op1=events[curr][2]+dp(events,curr+1,events[curr][1],k-1);
        }    
        int op2=dp(events,curr+1,time,k);
        return memo[key]=max(op1,op2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        return dp(events,0,-1,k);
    }
};
 

//Approach 2:-
// Use dynamic programming with binary search to optimize the solution.

// CODE:
class Solution {
public:
    vector<vector<int>> dp;

    int findNextEvent(const vector<vector<int>>& events, int currEnd, int startIdx) {
        int low = startIdx, high = events.size() - 1;
        int ans = events.size(); // default to "not found"

        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > currEnd) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int dfs(const vector<vector<int>>& events, int curr, int k) {
        if (curr >= events.size() || k == 0) return 0;
        if (dp[curr][k] != -1) return dp[curr][k];

        // Option 1: Skip current event
        int skip = dfs(events, curr + 1, k);

        // Option 2: Take current event
        int nextIdx = findNextEvent(events, events[curr][1], curr + 1);
        int take = events[curr][2] + dfs(events, nextIdx, k - 1);

        return dp[curr][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        int n = events.size();
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return dfs(events, 0, k);
    }
};


//74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

// Approach:
// Use binary search to find the target in the 2D matrix.

// CODE:
class Solution {
public:
    int BSCol(vector<vector<int>>& matrix,int target){
        int n=matrix.size();
        int low=0;
        int high=n-1;
        int res=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(target<matrix[mid][0]){
                high=mid-1;
            }
            else{
                low=mid+1;
                res=mid;
            }
        }
        return res;
    }
    bool BSRow(vector<vector<int>>& matrix,int target,int col){
        int low=0;
        int high=matrix[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[col][mid]==target){
                return true;
            }
            else if(matrix[col][mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=BSCol(matrix,target);
        return BSRow(matrix,target,col);
    }
};

//240. Search a 2D Matrix II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Approach:
// Use binary search to find the target in the 2D matrix.

// CODE:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int col=matrix[0].size()-1;
        while(row>=0 && row<matrix.size() && col>=0 && col<matrix[0].size()){
            if(matrix[row][col]==target){
                return true;
            }
            if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};

//1901. Find a Peak Element II
// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Approach:
// Use binary search to find a peak element in the 2D grid.

// CODE:
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxRow=0;
            for(int i=0;i<mat.size();i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow=i;
                }
            }

            bool leftOk = (mid == 0) || (mat[maxRow][mid] > mat[maxRow][mid - 1]);
            bool rightOk = (mid == mat[0].size() - 1) || (mat[maxRow][mid] > mat[maxRow][mid + 1]);

            if (leftOk && rightOk) {
                return {maxRow, mid};
            }
            else if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {};
    }
};