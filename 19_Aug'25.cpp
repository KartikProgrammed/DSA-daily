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

//2348. Number of Zero-Filled Subarrays

// Given an integer array nums, return the number of subarrays filled with 0.
// A subarray is a contiguous non-empty sequence of elements within an array.

//Approach:-
// 1. Initialize a count variable to keep track of the number of zero-filled subarrays.
// 2. Use a variable to count the length of consecutive zeros.
// 3. Iterate through the array:
//    - If the current element is zero, increment the count of consecutive zeros.
//    - If the current element is not zero, calculate the number of zero-filled subarrays formed by the consecutive zeros
//      using the formula count * (count + 1) / 2, and reset the count of consecutive zeros to zero.

//CODE:-
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                res+=count;
                count=0;
                continue;
            }
            res+=count;
            count++;
        }

        return res+count;
    }
};


//424. Longest Repeating Character Replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

//Approach:-
// 1. Use a sliding window approach to find the longest substring with at most k replacements.
// 2. Maintain a frequency map to count the occurrences of characters in the current window.
// 3. Use two pointers to represent the window's start and end.
// 4. Expand the window by moving the end pointer and update the frequency map.
// 5. If the number of characters that need to be replaced exceeds k, move the start pointer to shrink the window until the condition is satisfied.
// 6. Keep track of the maximum length of the valid substring found during the process.


//CODE:-
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int res=0;
        int maxCount=0;
        unordered_map<char,int> map;
        while(right<s.length() && left<=right){
            map[s[right]]++;
            maxCount=max(maxCount,map[s[right]]);
            while(right-left+1-maxCount > k){
                map[s[left]]--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};