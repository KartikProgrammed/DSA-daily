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