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

//2016. Maximum Difference Between Increasing Elements
// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
// Return the maximum difference. If no such i and j exists, return -1.

// Approach:
//calculate the maximum difference between increasing elements in the array.

// CODE:
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res=-1;
        for(int i=0;i<nums.size()-1;i++){
            int maxi=*max_element(nums.begin()+i+1,nums.end());
            if(maxi>nums[i]){
                int curr=maxi-nums[i];
                res=max(res,curr);
            }
        }
        return res;
    }
};

//Approach2:-
// Use a single pass to find the maximum difference by keeping track of the minimum value seen so far.

// CODE:
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res=-1;
        int minVal=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>minVal){
                res=max(res,nums[i]-minVal);
            }
            else{
                minVal=nums[i];
            }
        }
        return res;
    }
};

//485. Max Consecutive Ones
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Approach:
// Iterate through the array and count the maximum consecutive 1's.

// CODE:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
            }
            else{
                res=max(res,curr);
                curr=0;
            }
        }
        res=max(res,curr);
        return res;    
    }
};

//136. Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Approach:
// Use XOR operation to find the single number since XOR of a number with itself is 0 and XOR with 0 is the number itself.

// CODE:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};