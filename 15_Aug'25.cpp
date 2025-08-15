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

//342. Power of Four
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

// Approach:
// 1. Check if n is greater than 0.
// 2. Check if n is divisible by 4 in a loop until n becomes 1.
// 3. If n becomes 1, return true; otherwise, return false.

// Code:
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4!=0){
                return false;
            }
            n/=4;
        }
        if(n!=1){
            return false;
        }
        return true;
    }
};

//84. Largest Rectangle in Histogram

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Approach:
// 1. Use a stack to keep track of the indices of the bars.
// 2. find next smaller element for each bar.
// 3. Calculate the area for each bar using the next smaller elements and update the maximum area found.

// Code:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        vector<int> nextSmaller(heights.size(),heights.size());
        vector<int> prevSmaller(heights.size(),-1);

        for(int i=0;i<heights.size();i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                prevSmaller[i]=stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            stk.pop();
        }

        for(int i=heights.size()-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                nextSmaller[i]=stk.top();
            }
            stk.push(i);
        }
        int res=0;
        for(int i=0;i<heights.size();i++){
            int curr=(nextSmaller[i]-prevSmaller[i]-1) * heights[i];
            res=max(curr,res);
        }
        return res;
    }
};


//85. Maximal Rectangle

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Approach:
//NSL,NSR - calc
//treat every row as a new pass to the prev solution

//CODE:-
class Solution {
public:
    vector<int> buildVec(vector<char> &num,vector<int> &prev){
        vector<int> res(num.size());
        for(int i=0;i<num.size();i++){
            if(num[i]=='1'){
                res[i]=1+prev[i];
            }
            else{
                res[i]=0;
            }
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        vector<int> nextSmaller(heights.size(),heights.size());
        vector<int> prevSmaller(heights.size(),-1);

        for(int i=0;i<heights.size();i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                prevSmaller[i]=stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            stk.pop();
        }

        for(int i=heights.size()-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                nextSmaller[i]=stk.top();
            }
            stk.push(i);
        }
        int res=0;
        for(int i=0;i<heights.size();i++){
            int curr=(nextSmaller[i]-prevSmaller[i]-1) * heights[i];
            res=max(curr,res);
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0){
            return 0;
        }
        vector<int> prev(matrix[0].size(),0);
        int res=0;
        for(int i=0;i<matrix.size();i++){
            prev=buildVec(matrix[i],prev);
            int curr=largestRectangleArea(prev);
            res=max(res,curr);
        }
        return res;
    }
};