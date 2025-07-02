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

//153. Find Minimum in Rotated Sorted Array
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

// Approach:
// 1. Initialize two pointers, left and right, to the start and end of the
//    array.
// 2. While left is less than right, calculate the middle index.
// 3. If the middle element is greater than the rightmost element, it means
//    the minimum element is in the right half of the array, so move the left
//    pointer to mid + 1.
// 4. If the middle element is less than or equal to the rightmost element,
//    it means the minimum element is in the left half of the array, so move
//    the right pointer to mid.

// CODE:
class Solution {
public:
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
        return nums[low];
    }
    int findMin(vector<int>& nums) {
        return findpiv(nums);
    }
};

//540. Single Element in a Sorted Array
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Approach:
// 1. Initialize two pointers, left and right, to the start and end of the array.
// 2. While left is less than right, calculate the middle index.
// 3. If the middle index is even, check if the element at mid is equal to the
//    element at mid + 1. If they are equal, it means the single element is
//    in the right half of the array, so move the left pointer to mid +
//    2. If they are not equal, it means the single element is in the left
//    half of the array, so move the right pointer to mid.
// 4. If the middle index is odd, check if the element at mid is equal to the
//    element at mid - 1. If they are equal, it means the single element is
//    in the right half of the array, so move the left pointer to mid +
//    1. If they are not equal, it means the single element is in the left
//    half of the array, so move the right pointer to mid - 1.

// CODE:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(mid%2!=0){
                mid--;
            }
            if(nums[mid]==nums[mid+1]){
                low=mid+2;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};

//162. Find Peak Element
// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.

// Approach:
// 1. Initialize two pointers, left and right, to the start and end of the
//    array.
// 2. While left is less than right, calculate the middle index.
// 3. If the middle element is greater than its right neighbor, it means
//    the peak element is in the left half of the array, so move the right
//    pointer to mid.
// 4. If the middle element is less than its right neighbor, it means
//    the peak element is in the right half of the array, so move the left
//    pointer to mid + 1.
// 5. If the middle element is equal to its right neighbor, it means
//    the peak element is in the right half of the array, so move the left
//    pointer to mid + 1.

// CODE:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
