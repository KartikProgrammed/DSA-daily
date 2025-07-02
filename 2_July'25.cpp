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