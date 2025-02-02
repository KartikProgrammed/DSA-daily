#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//1752. Check if Array Is Sorted and Rotated
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.


//APPROACH:- (Beats 100%)
//find the number of rotations in the array if it exceeds 1 return false
//if the rotations is 1 and the 0th element is smaller than the last element return false
//else return true
//this is because if we rotate it accordingly we'll get another rotation
//eg 
// 34125 now rotations=1 at 2nd index
//but last element is greater than 1st element
//after rotating it back it becomes 12534 and we have one more rotaton hence this is false

//CODE:-
class Solution {
public:
    bool check(vector<int>& nums) {
        int rot=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                rot++;
            }
        }
        if(rot>1){
            return false;
        }
        if(rot==1 && nums[0]<nums[nums.size()-1]){
            return false;
        }
        return true;
    }
};