#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;


//DailyProblem 1829:-Maximum XOR for Each Query
// You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

// Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
// Remove the last element from the current array nums.
// Return an array answer, where answer[i] is the answer to the ith query.

//CODE:-
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> result;
        int xor_sum = 0;
        int max_val = (1 << maximumBit) - 1; 

        for (int num : nums) {
            xor_sum ^= num;
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            result.push_back(xor_sum ^ max_val);  
            xor_sum ^= nums[i];
        }

        return result;
    }
};
