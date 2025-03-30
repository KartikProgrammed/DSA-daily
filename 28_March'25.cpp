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

// 763. Partition Labels
// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.

//APPROACH:-
//use 2 maps 1 local and 1 global
//if the local count reaches max for every local map partition

//CODE:-
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> global;
        for(int i=0;i<s.length();i++){
            global[s[i]]++;
        }
        int prev=-1;
        unordered_map<char,int> local;
        vector<int> res;
        for(int i=0;i<s.length();i++){
            local[s[i]]++;
            bool ok=true;
            for (auto &entry : local) {
                if (entry.second < global[entry.first]) {
                    ok = false;
                    break;
                }
            }
            if(ok){
                local.clear();
                res.push_back(i-(prev));
                prev=i;
            }
        }
        return res;
    }
};