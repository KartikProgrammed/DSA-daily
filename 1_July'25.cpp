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

//3330. Find the Original Typed String I
// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
// Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
// You are given a string word, which represents the final output displayed on Alice's screen.
// Return the total number of possible original strings that Alice might have intended to type.

// Approach:
// 1. Initialize a counter to keep track of the number of possible original strings.
// 2. Iterate through the string, checking for consecutive characters.
// 3. For each character, check if it is the same as the next character.
// 4. If it is, increment the counter for each consecutive character found.
// 5. If the character is different from the next character, reset the counter to 1.
// 6. Return the total count of possible original strings.

// CODE:
class Solution {
public:
    int possibleStringCount(string word) {
        int res=1;
        char prev='\0';
        int count=0;
        for(int i=0;i<word.length();i++){
            if(prev=='\0' || word[i]!=prev){
                prev=word[i];
                res+=count;
                count=0;
            }
            else if(word[i]==prev){
                count++;
            }
        }
        return res+count;
    }
};