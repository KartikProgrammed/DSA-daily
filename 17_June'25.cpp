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

// 3405. Count the Number of Arrays with K Matching Adjacent Elements
// You are given three integers n, m, k. A good array arr of size n is defined as follows:
// Each element in arr is in the inclusive range [1, m].
// Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
// Return the number of good arrays that can be formed.
// Since the answer may be very large, return it modulo 109 + 7.

// Approach: Combinatorial counting with dynamic programming

//CODE:-
class Solution {
public:
    int MOD=1e9+7;
    int findPower(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long half=findPower(a,b/2);
        long long result=(half*half)%MOD;
        if(b%2==1){
            result=(result*a) %MOD;
        }
        return result;
    }

    long long nCr(int n,int r,vector<long long> &factorial,vector<long long> &inverseFactorial){
        return factorial[n]*inverseFactorial[n-r]% MOD *inverseFactorial[r]% MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1,1);
        factorial[0]=1;
        factorial[1]=1;
        for(int i=2;i<=n;i++){
            factorial[i]=(factorial[i-1]*i) % MOD;
        }

        vector<long long> inverseFactorial(n+1,1);
        for(int i=0;i<=n;i++){
            inverseFactorial[i]=findPower(factorial[i],MOD-2);
        }

        long long result=nCr(n-1,k,factorial,inverseFactorial);
        result=(result*m)%MOD;
        result=result*findPower(m-1,n-k-1)%MOD;
        return result;
    }
};

//1. Two Sum
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


// Approach: Hash map to store indices of elements

//CODE:-
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int nex=target-nums[i];
            if(map.find(nex)!=map.end()){
                res.push_back(i);
                res.push_back(map[nex]);
                return res;
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
 

//169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 

// Approach:
//Unordered map to count occurrences of each element
// The algorithm maintains a count and a candidate for the majority element.

//CODE:-
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            if(map[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
        return nums[0];
    }
};

//Approach2:
//Boyer-Moore Voting Algorithm
// The Boyer-Moore Voting Algorithm is an efficient algorithm to find the majority element in linear time and constant space.
// It works by maintaining a count and a candidate for the majority element.
// The count is incremented when the current element matches the candidate and decremented otherwise.
// If the count reaches zero, the current element becomes the new candidate.


//CODE:-
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=0;
        int count=0;
        for(int num:nums){
            if(count==0){
                curr=num;
            }
            count+=(num==curr?1:-1);
        }
        return curr;
    }
};

//53. Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Approach: Kadane's algorithm
// Kadane's algorithm is a dynamic programming approach that finds the maximum sum of a contiguous subarray in linear time.
// It maintains a current sum and a maximum sum, updating them as it iterates through the array.


//CODE:-
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr=max(curr+nums[i],nums[i]);
            res=max(res,curr);
        }
        return res;
    }
};