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

//2966. Divide Array Into Arrays With Max Difference
// You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
// Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

// Approach: sort and check for valid triplets

//CODE:-
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        int prev=nums[0];
        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size()) return {};
            int minVal = nums[i];
            int maxVal = nums[i + 2];
            if (maxVal - minVal > k) return {};
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};