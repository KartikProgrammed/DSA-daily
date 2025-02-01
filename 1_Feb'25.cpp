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

//3151. Special Array I
// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

//APPROACH:-
//nested if-else statement for even and odd indices work best and O(n) complexity

//CODE:-
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
       if(nums.size()<2){
        return true;
       }
       int st=nums[0]%2==0?0:1; //starting index odd or even, odd is 1 and even 0
       for(int i=1;i<nums.size();i++){
        if(st==0 && i%2==0){
            if(nums[i]%2!=0){
                return false;
            }
        }
        if(st==0 && i%2!=0){
            if(nums[i]%2==0){
                return false;
            }
        }
        if(st==1 && i%2==0){
            if(nums[i]%2==0){
                return false;
            }
        }
        if(st==1 && i%2!=0){
            if(nums[i]%2!=0){
                return false;
            }
        }
       } 
       return true;
    }
};