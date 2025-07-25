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

//3487. Maximum Unique Subarray Sum After Deletion
// You are given an integer array nums.
// You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
// All elements in the subarray are unique.
// The sum of the elements in the subarray is maximized.
// Return the maximum sum of such a subarray.

// Approach:
//brute force

// CODE:
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int curr=INT_MIN;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
    
        for(int i=nums.size()-1;i>=0;i--){
            if(curr==INT_MIN){
                curr=nums[i];
                map[nums[i]]++;
            }
            else if(map[nums[i]]==0 && curr+nums[i]>curr){
                curr+=nums[i];
                map[nums[i]]++;
            }
        }
        return curr;
    }
};

//22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Approach:
//create all possible combinations of parentheses using backtracking

// CODE:
class Solution {
public:
    void recursion(vector<string> &res,string curr,int open,int close,int n){
        if(open==n && close==n){
            res.push_back(curr);
        }
        else{
            if(open>close){
                if(open<n){
                    recursion(res,curr+'(',open+1,close,n);
                }
                recursion(res,curr+')',open,close+1,n);
            }
            else{
                recursion(res,curr+'(',open+1,close,n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursion(res,"",0,0,n);
        return res;
    }
};