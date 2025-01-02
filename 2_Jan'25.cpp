#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//2559. Count Vowel Strings in Ranges
// You are given a 0-indexed array of strings words and a 2D array of integers queries.
// Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
// Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
// Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

//APPROACH:-
//BRUTE FORCE- TLE at last TC :(

//CODE:-
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<bool> vow(n,false);
        for(int i=0;i<n;i++){
            string curr=words[i];
            int currlen=words[i].length()-1;
            if((curr[0]=='a' || curr[0]=='e' || curr[0]=='i' || curr[0]=='o' || curr[0]=='u') && (curr[currlen]=='a' || curr[currlen]=='e' || curr[currlen]=='i' || curr[currlen]=='o' || curr[currlen]=='u')){
                vow[i]=true;
            }
        }
        int ans=0;
        vector<int> result;
        for(int i=0;i<queries.size();i++){
            ans=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                if(vow[j]==true){
                    ans++;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};

//APPROACH 2:- prefix sum

//CODE:-
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++){
            string curr=words[i];
            pref[i+1]=pref[i];
            int currlen=words[i].length()-1;
            if((curr[0]=='a' || curr[0]=='e' || curr[0]=='i' || curr[0]=='o' || curr[0]=='u') && (curr[currlen]=='a' || curr[currlen]=='e' || curr[currlen]=='i' || curr[currlen]=='o' || curr[currlen]=='u')){
                pref[i+1]+=1;
            }
        }
        vector<int> result;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            result.push_back(pref[end + 1] - pref[start]);
        }
        return result;
    }
};