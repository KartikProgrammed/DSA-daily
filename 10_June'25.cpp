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

//3442. Maximum Difference Between Even and Odd Frequency I
// You are given a string s consisting of lowercase English letters.
// Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
// a1 has an odd frequency in the string.
// a2 has an even frequency in the string.
// Return this maximum difference.

//Approach:
// Count the frequency of each character and then find the maximum difference between odd and even frequencies.

// CODE:
class Solution {
public:
    int maxDifference(string s) {
        vector<int> map(26,0);
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
        }
        int maxOdd=INT_MIN;
        int minEven=INT_MAX;
        for(int i=0;i<26;i++){
            if(map[i]%2==0 && map[i]!=0){
                minEven=min(minEven,map[i]);
            }
            else{
                maxOdd=max(maxOdd,map[i]);
            }
        }
        return maxOdd-minEven;
    }
};