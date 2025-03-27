#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2780. Minimum Index of a Valid Split
// An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
// You are given a 0-indexed integer array nums of length n with one dominant element.
// You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
// 0 <= i < n - 1
// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
// Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
// Return the minimum index of a valid split. If no valid split exists, return -1.

//APPROACH:-
//try split at each ind from 0

//CODE:-
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for(int num:nums){
            map2[num]++;
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            map1[num]++;
            map2[num]--;

            int n1=i+1;
            int n2=n-i-1;

            if(map1[num]>n1/2 && map2[num]>n2/2){
                return i;
            }
        }
        return -1;
    }
};