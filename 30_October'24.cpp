#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 1671:- minimum number of removals to make mountain array
// You may recall that an array arr is a mountain array if and only if:
// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

 
//CODE:-
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return -1;
        }
        vector<int> left(size, 1), right(size, 1);
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        for (int i = size - 2; i >= 0; --i) {
            for (int j = size - 1; j > i; --j) {
                if (nums[j] < nums[i]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }

        int minRemovals = size;
        for (int i = 1; i < size - 1; ++i) {
            if (left[i] > 1 && right[i] > 1) { 
                int mountainLength = left[i] + right[i] - 1;
                minRemovals = min(minRemovals, size - mountainLength);
            }
        }

        return minRemovals;
    }
};
