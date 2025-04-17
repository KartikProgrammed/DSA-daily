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
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

//2176. Count Equal and Divisible Pairs in an Array
// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.

//APPROACH:-
//Two pointer approach

//CODE:-
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    int curr=i*j;
                    if(curr%k==0){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};