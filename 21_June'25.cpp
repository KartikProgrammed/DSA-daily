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

// 3085. Minimum Deletions to Make String K-Special
// You are given a string word and an integer k.
// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
// Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
// Return the minimum number of characters you need to delete to make word k-special.

// Approach: Count frequency of each character, then check the maximum frequency and minimum frequency.

// CODE:
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<word.size();i++){
            map[word[i]-'a']++;
        }
        int res=INT_MAX;
        for(auto curr:map){
            int mini=curr.first;
            int count=curr.second;
            int del=0;
            for(auto y:map){
                if(count>y.second){
                    del+=y.second;
                }
                else if(y.second>count+k){
                    del+=y.second-count-k;
                }
            }
            res=min(del,res);
        }
        return res;
    }
};