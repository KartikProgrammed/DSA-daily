#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2563:- Count the Number of Fair Pairs
// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

// A pair (i, j) is fair if:
//     0 <= i < j < n, and
//     lower <= nums[i] + nums[j] <= upper

#define ll long long
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll res = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            res += r - l;
        }

        return res;
    }
};