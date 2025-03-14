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

//2226. Maximum Candies Allocated to K Children
// You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.
// You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
// Return the maximum number of candies each child can get.

//APPROACH 
//max each child can get is the max element of candies arr, min is 1
//calculate the no. of students getting candies usin bin search bw 1->max adjust according to k

//CODE:-
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int mid;
        int res=0;
        int high=*max_element(candies.begin(),candies.end());
        while(low<=high){
            mid=low+(high-low)/2;
            long long count=0;
            for(int i=0;i<candies.size();i++){
                count+=candies[i]/mid;
            }
            if(count>=k){
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }
};