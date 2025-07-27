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

// 2210. Count Hills and Valleys in an Array
// You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest non-equal neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i] == nums[j].
// Note that for an index to be part of a hill or valley, it must have a non-equal neighbor on both the left and right of the index.
// Return the number of hills and valleys in nums.

// Approach:
// Iterate through the array and count hills and valleys based on the conditions provided.

// CODE:
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            int right=i+1;
            while(right<nums.size()-1 && nums[right]==nums[i]){
                right++;
            }
            if(nums[i-1]>nums[i] && nums[right]>nums[i]){
                res++;
            }
            else if(nums[i-1]<nums[i] && nums[right]<nums[i]){
                res++;
            }
        }
        return res;
    }
};

//39. Combination Sum
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Approach:
// Use backtracking to explore all combinations of candidates that sum to the target.

// CODE:
class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &curr, int ind, vector<int> &candidates, int target) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || ind == candidates.size()) return;

        backtrack(res, curr, ind + 1, candidates, target);

        curr.push_back(candidates[ind]);
        backtrack(res, curr, ind, candidates, target - candidates[ind]);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res, curr, 0, candidates, target);
        return res;
    }
};
