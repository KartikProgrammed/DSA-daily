#include <bits/stdc++.h>
using namespace std;

//1014. Best Sightseeing Pair
// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

// The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

// Return the maximum score of a pair of sightseeing spots.


//APPROACH 1:- Brute force (TLE) 
//CODE:-
class Solution {
public:
    int score(vector<int> &values,int i,int j){
        int result=values[i]+values[j]+(i-j);
        return result;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int currmax=INT_MIN;
        for(int i=0;i<values.size();i++){
            for(int j=i+1;j<values.size();j++){
                int curr=score(values,i,j);
                if(curr>currmax){
                    currmax=curr;
                }
            }
        }
        return currmax;
    }
};

//APPROACH 2:- 
//Greedy APPROACH
//think of the score as values[i]+i + values[j]-j 

//CODE:-
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left=values[0];
        int maxtillhere=INT_MIN;
        for(int j=1;j<values.size();j++){
            maxtillhere=max(maxtillhere,left+values[j]-j);
            left=max(left,values[j]+j);
        }
        return maxtillhere;
    }
};

//2104. Sum of Subarray Ranges
// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.


//APPROACH:-
//finding subarray miniums and subarray maximums and then subtracting easy
//sub-min and sub-max are found using monotonic stack
//NSL- next smaller left, NSR- next smaller right similarly NGL and NGR

//CODE:-
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> helper;
        vector<int> NSL(nums.size(),-1);
        vector<int> NSR(nums.size(),nums.size());
        for(int i=0;i<nums.size();i++){
            while(!helper.empty() && nums[helper.top()]>=nums[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NSL[i]=helper.top();
            }
            helper.push(i);
        }
        while(!helper.empty()){
            helper.pop();
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!helper.empty() && nums[helper.top()]>nums[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NSR[i]=helper.top();
            }
            helper.push(i);
        }
        //calc contribution
        long long rangemin=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-NSL[i];
            long long right=NSR[i]-i;
            rangemin=rangemin+((long long)nums[i]*left*right);
        }
        while(!helper.empty()){
            helper.pop();
        }
        vector<int> NGR(nums.size(),nums.size());
        vector<int> NGL(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(!helper.empty() && nums[helper.top()]<=nums[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NGL[i]=helper.top();
            }
            helper.push(i);
        }
        while(!helper.empty()){
            helper.pop();
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!helper.empty() && nums[helper.top()]<nums[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NGR[i]=helper.top();
            }
            helper.push(i);
        }
        //calc contribution
        long long rangemax=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-NGL[i];
            long long right=NGR[i]-i;
            rangemax=rangemax+((long long)nums[i]*left*right);
        }
        return rangemax-rangemin;
    }
};

//402. Remove K Digits
//Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

//APPROACH:- 
//Use a monotonic stack and pop whenever top>num[i]

//CODE:-
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k){
            return "0";
        }
        if(k==0){
            return num;
        }
        stack<char> helper;
        for(int i=0;i<num.length();i++){
            while(!helper.empty() && k>0 && helper.top()>num[i]){
                helper.pop();
                k--;
            }
            helper.push(num[i]);
        }
        while(!helper.empty() && k>0){
            helper.pop();
            k--;
        }
        string result="";
        while(!helper.empty()){
            result.push_back(helper.top());
            helper.pop();
        }
        reverse(result.begin(), result.end());
        int start=0;
        while (start < result.length() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};

//84. Largest Rectangle in Histogram
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

//APPROACH:-
//finding the next smaller left and right for each elements using monotonic stack and computing area as
//smaller left - smaller right -1 * heights[i]

//CODE:-
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> helper;
        int result=INT_MIN;
        vector<int> NSL(heights.size(),-1);
        vector<int> NSR(heights.size(),heights.size());
        for(int i=0;i<heights.size();i++){
            while(!helper.empty() && heights[helper.top()]>=heights[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NSL[i]=helper.top();
            }
            helper.push(i);
        }
        while(!helper.empty()){
            helper.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!helper.empty() && heights[helper.top()]>heights[i]){
                helper.pop();
            }
            if(!helper.empty()){
                NSR[i]=helper.top();
            }
            helper.push(i);
        }
        for(int i=0;i<heights.size();i++){
            int curr=(NSR[i]-NSL[i]-1)*heights[i];
            result=result>curr?result:curr;
        }
        return result;

    }
};
