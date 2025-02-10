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

//3174. Clear Digits
// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

//APPROACH:-
//basic string operation erase

//CODE:-
class Solution {
    public:
        string clearDigits(string s) {
            bool flag;
            do{
                flag=false;
                for(int i=0;i<s.length();i++){
                    if(isdigit(s[i])){
                        for(int j=i-1;j>=0;j--){
                            if(isalpha(s[j])){
                                s.erase(i,1);
                                s.erase(j,1);
                                flag=true;
                                break;
                            }
                        }
                        break;
                    }
                }
            }while(flag);
            return s;
        }
    };