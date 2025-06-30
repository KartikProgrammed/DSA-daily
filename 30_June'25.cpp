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


//594. Longest Harmonious Subsequence
// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

// Approach:
// Use a hash map to count the frequency of each number.
// Iterate through the keys in the map and check if the current key and the next key (
// current key + 1) exist in the map.
// If they do, calculate the length of the harmonious subsequence formed by these two keys and
// update the maximum length found so far.

// CODE:
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int it:nums){
            map[it]++;
        }
        int res=0;
        for(auto &it:map){
            int num=it.first;
            int count=it.second;
            int count2=INT_MIN;
            if(map.find(num+1)!=map.end()){
                count2=max(count2,map[num+1]);
            }
            if(map.find(num-1)!=map.end()){
                count2=max(count2,map[num-1]);
            }
            res=max(res,count+count2);
        }
        return res;
    }
};

//Approach2:-
//sliding window

// CODE:
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=0;
        int res=0;
        while(left<=right && right<nums.size()){
            if(nums[right]-nums[left]>1){
                left++;
            }
            else if(nums[right]-nums[left]<1){
                right++;
            }
            else{
                res=max(res,right-left+1);
                right++;
            }
        }
        return res;
    }
};

//704. Binary Search
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Approach:
// Use binary search to find the target in the sorted array.
// Initialize two pointers, left and right, to the start and end of the array.
// While left is less than or equal to right, calculate the middle index.
// If the middle element is equal to the target, return the middle index.
// If the middle element is less than the target, move the left pointer to mid + 1.
// If the middle element is greater than the target, move the right pointer to mid - 1.

// CODE:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
}; 

//35. Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.


// Approach:
// Use binary search to find the target in the sorted array.
// Initialize two pointers, left and right, to the start and end of the array.
// While left is less than or equal to right, calculate the middle index.
// If the middle element is equal to the target, return the middle index.
// If the middle element is less than the target, move the left pointer to mid + 1.
// If the middle element is greater than the target, move the right pointer to mid - 1.
// If the target is not found, return the left pointer as the insertion position.

// CODE:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};