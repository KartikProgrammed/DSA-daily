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

// 1865. Finding Pairs With a Certain Sum
// You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:
// Add a positive integer to an element of a given index in the array nums2.
// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
// Implement the FindSumPairs class:
// FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
// void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
// int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

// Approach:
// 1. Use a hash map to store the frequency of each element in nums2.
// 2. For the add operation, update the frequency of the element at the given index
//    in the hash map.
// 3. For the count operation, iterate through nums1 and for each element, check
//    if the complement (tot - nums1[i]) exists in the hash map. If it does, add
//    the frequency of that complement to the count.

// CODE:
class FindSumPairs {
private:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int,int> map;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int it:arr2){
            map[it]++;
        }
    }
    
    void add(int index, int val) {
        map[arr2[index]]--;
        arr2[index]=arr2[index]+val;
        map[arr2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(int it:arr1){
            int search=tot-it;
            if(map.find(search)!=map.end()){
                res=res+map[search];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */


//1482. Minimum Number of Days to Make m Bouquets
// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

// Approach:
// 1. Initialize two pointers, left and right, to the minimum and maximum bloom days
//    in the bloomDay array.
// 2. While left is less than right, calculate the middle day.
// 3. Count the number of bouquets that can be made by iterating through the
//    bloomDay array and checking if the bloom day is less than or equal to the
//    middle day. If it is, increment the count of adjacent flowers. If the count
//    reaches k, increment the bouquet count and reset the adjacent flower count.
// 4. If the bouquet count is greater than or equal to m, it means we can make
//    enough bouquets, so move the right pointer to mid. Otherwise, move the left
//    pointer to mid + 1.

// CODE:
class Solution {
public:
    int calc(vector<int>& arr,int mid,int k){
        int left=0;
        int steps=0;
        int res=0;
        while(left<arr.size()){
            if(arr[left]<=mid){
                steps++;
                if(steps==k){
                    res++;
                    steps=0;
                }
                left++;
            }
            else{
                steps=0;
                left++;
            }
        }
        return res;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int bouq=calc(bloomDay,mid,k);
            if(bouq>=m){
                res = (res == -1) ? mid : min(res, mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};

//1283. Find the Smallest Divisor Given a Threshold
// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
// The test cases are generated so that there will be an answer.

// Approach:
// 1. Initialize two pointers, left and right, to 1 and the maximum element
//    in the nums array.
// 2. While left is less than right, calculate the middle divisor.
// 3. Calculate the total sum of the division results for all elements in nums
//    using the current divisor.
// 4. If the total sum is less than or equal to the threshold, it means
//    the divisor is valid, so move the right pointer to mid.
// 5. If the total sum is greater than the threshold, it means the divisor is too small,
//    so move the left pointer to mid + 1.
// 6. Return the left pointer as the smallest divisor.

// CODE:
class Solution {
public:
    int calc(vector<int>& nums,int mid){
        int res=0;
        for(int it:nums){
            res+=(it+mid-1)/mid;
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int res=high;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=calc(nums,mid);
            if(sum<=threshold){
                high=mid-1;
                res=min(res,mid);
            }
            else{
                low=mid+1;
            }
        }        
        return res;
    }
};

// 1011. Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// Approach:
// 1. Initialize two pointers, left and right, to the maximum weight in the weights array
//    and the sum of all weights, respectively.
// 2. While left is less than right, calculate the middle capacity.
// 3. Count the number of days required to ship all packages with the current capacity.
// 4. If the number of days is less than or equal to days, it means the capacity is valid,
//    so move the right pointer to mid. Otherwise, move the left pointer to mid + 1.
// 5. Return the left pointer as the minimum capacity required to ship all packages.

// CODE:
class Solution {
public:
    int calc(vector<int>& weights,int mid){
        int i=0;
        int curr=0;
        int day=0;
        while(i<weights.size()){
            if(curr+weights[i]>mid){
                curr=weights[i];
                day++;
            }
            else{
                curr+=weights[i];
            }
            i++;
        }
        return day+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int it:weights){
            high+=it;
        }
        int res=high;
        while(low<=high){
            int mid=(low+high)/2;
            int expect=calc(weights,mid);
            if(expect<=days){
                high=mid-1;
                res=min(mid,res);
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};