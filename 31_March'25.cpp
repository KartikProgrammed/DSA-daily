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

//2551. Put Marbles in Bags
// You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
// Divide the marbles into the k bags according to the following rules:
// No bag is empty.
// If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
// If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
// The score after distributing the marbles is the sum of the costs of all the k bags.
// Return the difference between the maximum and minimum scores among marble distributions.

//APPROACH:-
//find adj pair sum, sort it and then find max and min sum

//CODE:-
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxSum=0;
        long long minSum=0;
        int m=weights.size()-1;
        vector<long long> pairsum(m,0);

        for(int i=0;i<m;i++){
            pairsum[i]=weights[i]+weights[i+1];
        }
        sort(pairsum.begin(),pairsum.end());

        for(int i=0;i<k-1;i++){
            minSum+=pairsum[i];
            maxSum+=pairsum[m-i-1];
        }
        return maxSum-minSum;
    }
};