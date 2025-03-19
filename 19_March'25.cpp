#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//3191. Minimum Operations to Make Binary Array Elements Equal to One I
//You are given a binary array nums.You can do the following operation on the array any number of times (possibly zero):
// Choose any 3 consecutive elements from the array and flip all of them.
// Flipping an element means changing its value from 0 to 1, and from 1 to 0.
// Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.


//APPROACH:-
//GREEDY APPROACH
//conv every 0 to 1 and linearly move fwd

//CODE:-
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        
        for(int j=0;j<=n-3;j++){
            if(nums[j]==0 && j<n-2){
                res++;
                for(int k=j;k<j+3;k++){
                    nums[k]^=1;
                }
            }
        }
        
        if(*min_element(nums.begin(),nums.end())==0){return -1;}
        return res;
    }
};