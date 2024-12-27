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
