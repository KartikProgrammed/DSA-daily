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

// 2438. Range Product Queries of Powers
// Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.
// You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.
// Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

// Approach:
// 1. Generate the powers of 2 that sum to n and store them in a
//    vector called powers.
// 2. For each query, calculate the product of the specified range in powers.

// Code:
#define MOD 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int power=0;
        vector<long long> powers;
        while(n>0){
            int num=n&1;
            n>>=1;
            if(num==1){
                powers.push_back(1LL << power);
            }
            power++;
        }
        vector<int> answers;
        for(int i=0;i<queries.size();i++){
            int ans=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                ans=(1LL * ans*powers[j]) % MOD;
            }
            answers.push_back(ans);
        }
        return answers;
    }
};