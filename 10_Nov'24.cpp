#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 3097:- Shortest Subarray With OR at Least K II
// You are given an array nums of non-negative integers and an integer k.

// An array is called special if the bitwise OR of all of its elements is at least k.

// Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.

//CODE:-
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(32, 0);
        int currentOR = 0;
        int left = 0;
        int minLength = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            currentOR |= nums[right];
            
            for (int bit = 0; bit < 32; bit++) {
                if (nums[right] & (1 << bit)) {
                    bitCount[bit]++;
                }
            }
            
            while (left <= right && currentOR >= k) {
                minLength = min(minLength, right - left + 1);
                
                int updatedOR = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if (nums[left] & (1 << bit)) {
                        bitCount[bit]--;
                    }
                    if (bitCount[bit] > 0) {
                        updatedOR |= (1 << bit);
                    }
                }
                currentOR = updatedOR;
                left++;
            }
        }
        
        return minLength == INT_MAX ? -1 : minLength;
    }
};