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