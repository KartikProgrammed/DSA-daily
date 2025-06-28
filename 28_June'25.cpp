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

//2099. Find Subsequence of Length K With the Largest Sum
// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
// Return any such subsequence as an integer array of length k.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Approach:
// Sort the array in descending order and take the first k elements.
// Then find the indices of these elements in the original array and return them sorted.

// CODE:
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        vector<pair<int,int>> temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });
        vector<pair<int,int>> t2(temp.begin(),temp.begin()+k);
        sort(t2.begin(),t2.begin()+k,[](auto &a,auto &b){
            return a.second<b.second;
        });
        
        for(int i=0;i<k;i++){
            res.push_back(t2[i].first);
        }
        return res;
    }
};


//56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Approach:
// Sort the intervals based on the start time.
// Then iterate through the sorted intervals and merge them if they overlap.
// If they don't overlap, add the current interval to the result.

// CODE:
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[0]<b[0];
        });
        vector<vector<int>> res;
        int end;
        int curr=-1;
        
        for(int i=0;i<intervals.size();i++){
            if(i==0 || intervals[i][0]>end ){
                res.push_back(intervals[i]);
                end=intervals[i][1];
                curr++;
            }
            else{
                res[curr][1]=max(res[curr][1],intervals[i][1]);
                end=res[curr][1];
            }
        }
        return res;
    }
};

//88. Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Approach:
//use an extra array to store the merged result
//copy the elements of nums1 and nums2 into the extra array
//sort the extra array
//copy the elements of the extra array back to nums1

// CODE:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       vector<int> nums;
       int l=0;
       int r=0;
        while(l<m && r<n){
            if(nums1[l]<nums2[r]){
                nums.push_back(nums1[l]);
                l++;
            }
            else{
                nums.push_back(nums2[r]);
                r++;
            }
        }
        while(l<m){
            nums.push_back(nums1[l++]);
        }
        while(r<n){
            nums.push_back(nums2[r++]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=nums[i];
        }
    }
};