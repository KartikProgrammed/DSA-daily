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

// 2594. Minimum Time to Repair Cars
// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
// You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
// Return the minimum time taken to repair all the cars.
// Note: All the mechanics can repair the cars simultaneously.

//APPROACH:-
// Binary search 

//CODE:-
class Solution {
public:
    bool check(vector<int>& rank,int cars,long long mid){
        long long tot=0;
        for(int i=0;i<rank.size();i++){
            tot+=sqrt(mid/rank[i]);
        }
        return tot>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1;
        long long res=-1;
        long long high=(long long)cars * cars * (*min_element(ranks.begin(), ranks.end()));
        long long mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(ranks,cars,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};