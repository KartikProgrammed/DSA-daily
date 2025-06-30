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
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;


//594. Longest Harmonious Subsequence
// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

// Approach:
// Use a hash map to count the frequency of each number.
// Iterate through the keys in the map and check if the current key and the next key (
// current key + 1) exist in the map.
// If they do, calculate the length of the harmonious subsequence formed by these two keys and
// update the maximum length found so far.

// CODE:
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int it:nums){
            map[it]++;
        }
        int res=0;
        for(auto &it:map){
            int num=it.first;
            int count=it.second;
            int count2=INT_MIN;
            if(map.find(num+1)!=map.end()){
                count2=max(count2,map[num+1]);
            }
            if(map.find(num-1)!=map.end()){
                count2=max(count2,map[num-1]);
            }
            res=max(res,count+count2);
        }
        return res;
    }
};