#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2560. House Robber IV
// There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
// The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
// You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
// You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

//APPROACH:-
//DP (TLE)

//CODE:-
class Solution {
public:
    int recursion(vector<int>& nums, int k,int i){
        if(k==0)
            return 0;
        if(i>=nums.size()){return INT_MAX;}
        int take=max(nums[i],recursion(nums,k-1,i+2));
        int not_take=recursion(nums,k,i+1);
        return min(take,not_take);
    }
    int minCapability(vector<int>& nums, int k) {
        return recursion(nums,k,0);
    }
};

//APPROACH 2:-
//Binary Search

//CODE:-
class Solution {
public:
    bool check(vector<int>& nums, int k,int cap){
        int house=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=cap){
                house++;
                i++;
            }
        }
        return house>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int mid;
        int res=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(nums,k,mid)){
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};