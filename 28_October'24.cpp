#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;
//DailyProblem 2501:- Longest Square streak in an Array

// You are given an integer array nums. A subsequence of nums is called a square streak if:
// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

//CODE:-
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            int count = 0;
            long long current = num;

            while (st.find(current) != st.end()) {
                count++;
                current *= current;
                if (current > *st.rbegin()) break;
            }

            longest = max(longest, count);
        }

        return longest == 1 ? -1 : longest;
    }
};
