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

//1957. Delete Characters to Make Fancy String
// A fancy string is a string where no three consecutive characters are equal.
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
// Return the final string after the deletion. It can be shown that the answer will always be unique.

// Approach:
// 1. Initialize a result string.
// 2. Traverse the input string and check the last two characters of the result string.
// 3. If the last two characters are the same as the current character, skip the current character.
// 4. Otherwise, append the current character to the result string.
// 5. Return the result string.

// CODE:
class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){
            return s;
        }
        string res="";
        char prev=s[0];
        res+=s[0];
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==prev){
                count++;
                if(count<3){
                    res+=s[i];
                }
                else{
                    continue;
                }
            }
            else{
                res+=s[i];
                prev=s[i];
                count=1;
            }
        }
        return res;
    }
};