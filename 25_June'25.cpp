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

//54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.


// Approach: Use a loop to traverse the matrix in spiral order. Keep track of the boundaries of the matrix and adjust them as you traverse.
// Time Complexity: O(m * n), where m is the number of rows and n is
// the number of columns in the matrix.

// CODE:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        vector<int> res;

        while(top<=bottom && left<=right){
            for(int j=left;j<=right;j++){
                res.push_back(matrix[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};


//560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Approach: Use a hash map to store the cumulative sum and its frequency. For each element, check if the cumulative sum minus k exists in the map. If it does, add the frequency of that sum to the result.

//Code:-
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int count=0;
        int tot=0;
        for(int it:nums){
            tot+=it;
            if(map.find(tot-k)!=map.end()){
                count+=map[tot-k];
            }
            map[tot]++;
        }
        return count;
    }
};


//118. Pascal's Triangle
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Approach: Use a loop to generate each row of Pascal's triangle. Each element in the row can be calculated using the elements from the previous row.

//CODE:-
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0){
            return res;
        }
        res.push_back({1});
        int curr=0;
        while(curr<numRows-1){
            vector<int> currvec=res[curr];
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<currvec.size()-1;i++){
                temp.push_back(currvec[i]+currvec[i+1]);
            }
            temp.push_back(1);
            curr++;
            res.push_back(temp);
        }
        return res;
    }
};

//229. Majority Element II
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Approach: Use a hash map to count the frequency of each element. Then, iterate through the map to find elements that appear more than n/3 times.

// CODE:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> res;
        int n=nums.size();
        for(int it:nums){
            map[it]++;
        }
        for(auto &it:map){
            if(it.second>n/3){
                res.push_back(it.first);
            }
        }
        return res;
        
    }
};