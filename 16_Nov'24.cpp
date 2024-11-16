#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 3254:- Find the Power of K-Size Subarrays I
// You are given an array of integers nums of length n and a positive integer k.

// The power of an array is defined as:

// Its maximum element if all of its elements are consecutive and sorted in ascending order.-1 otherwise.
// You need to find the power of all subarrays of nums of size k.

// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

//CODE:-
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0; i <= nums.size() - k; i++) {
            bool sorted = true;
            bool consecutive = true;
            int maxElem = nums[i];
            for(int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    sorted = false;
                }
                if (nums[j] + 1 != nums[j + 1]) {
                    consecutive = false;
                }
                maxElem = max(maxElem, nums[j + 1]);
            }
            if (sorted && consecutive) {
                res.push_back(maxElem);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
