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

//3330. Find the Original Typed String I
// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
// Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
// You are given a string word, which represents the final output displayed on Alice's screen.
// Return the total number of possible original strings that Alice might have intended to type.

// Approach:
// 1. Initialize a counter to keep track of the number of possible original strings.
// 2. Iterate through the string, checking for consecutive characters.
// 3. For each character, check if it is the same as the next character.
// 4. If it is, increment the counter for each consecutive character found.
// 5. If the character is different from the next character, reset the counter to 1.
// 6. Return the total count of possible original strings.

// CODE:
class Solution {
public:
    int possibleStringCount(string word) {
        int res=1;
        char prev='\0';
        int count=0;
        for(int i=0;i<word.length();i++){
            if(prev=='\0' || word[i]!=prev){
                prev=word[i];
                res+=count;
                count=0;
            }
            else if(word[i]==prev){
                count++;
            }
        }
        return res+count;
    }
};

//33. Search in Rotated Sorted Array
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Approach:
// 1. Use binary search to find the pivot index where the array is rotated.
// 2. Determine which part of the array to search based on the target value.
// 3. Perform a standard binary search in the identified part of the array.
// 4. Return the index of the target if found, otherwise return -1.

// CODE:
class Solution {
public:
    int binsearch(vector<int>& nums,int target,int low,int high){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    int findpiv(vector<int>& nums){
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
    int search(vector<int>& nums, int target) {
        int piv=findpiv(nums);
        if(piv==0){
            return binsearch(nums,target,0,nums.size()-1);
        }
        if(target>=nums[0]){
            return binsearch(nums,target,0,piv-1);
        }
        return binsearch(nums,target,piv,nums.size()-1);      
    }
};

//81. Search in Rotated Sorted Array II
// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
// You must decrease the overall operation steps as much as possible

// Approach:
// use a variant of binary search to find the target in the rotated sorted array.
// 1. Initialize two pointers, left and right, to the start and end of the array.
// 2. While left is less than or equal to right, calculate the middle index.
// 3. If the middle element is equal to the target, return true.
// 4. If the middle element is less than the target, move the left pointer to mid + 1.
// 5. If the middle element is greater than the target, move the right pointer to mid - 1.
// 6. If the middle element is equal to the left or right pointer, increment the left pointer and decrement the right pointer to avoid duplicates.
// 7. If the target is not found, return false.

// CODE:
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // If left half is sorted
            if (nums[low] < nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // If right half is sorted
            else if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            // Duplicates: nums[low] == nums[mid] or nums[mid] == nums[high]
            else {
                if (nums[low] == nums[mid]) low++;
                if (nums[high] == nums[mid]) high--;
            }
        }

        return false;
    }
};
