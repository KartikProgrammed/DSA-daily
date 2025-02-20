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

// 1980. Find Unique Binary String
// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

//APPROACH:-
//create a recursive function at each recursion we add either 0 or 1 to the current string
//if a string created of size n is not present in the array we return it and that is the output

//CODE:-
class Solution {
    public:
        string recursion(unordered_map<string,int> map,string curr,int n){
            if(curr.length()==n){
                if(map.find(curr)==map.end()){
                    return curr;
                }
                return "";
            }
            string res=recursion(map,curr+'0',n);
            if(!res.empty()){
                return res;
            }
            res=recursion(map,curr+'1',n);
            return res;
        }
        string findDifferentBinaryString(vector<string>& nums) {
            int n=nums.size();
            unordered_map<string,int> map;
            for(int i=0;i<nums.size();i++){
                map[nums[i]]+=1;
            }
            return recursion(map,"",n);
        }
    };