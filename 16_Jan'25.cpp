#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

//2425. Bitwise XOR of All Pairings
//You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

// Return the bitwise XOR of all integers in nums3.

//APPROACH 1:-
//1 for loop for the nums1 2nd for the nums2
//complexity too high thus MLE/TLE

//CODE:-
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                res.push_back(nums1[i]^nums2[j]);
            }
        }
        int result=res[0];
        for(int i=1;i<res.size();i++){
            result=result^res[i];
        }
        return result;
    }
};

//APPROACH 2:-
//if size of nums1 is odd, it will contribute to the result
//else it will not

//CODE:-
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1=0;
        int xor2=0;
        for(int i=0;i<nums1.size();i++){
            xor1^=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            xor2^=nums2[i];
        }
        int result=0;
        if(nums1.size()%2!=0){
            result^=xor2;
        }
        if(nums2.size()%2!=0){
            result^=xor1;
        }
        return result;
    }
};