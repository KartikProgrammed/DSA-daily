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

// //LFU CACHE
// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.


//CODE:-
class LFUCache {
private:
    int currSize, maxSize, minFreq;
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    unordered_map<int, list<Node>::iterator> nodeMap; // Key to node iterator
    unordered_map<int, list<Node>> freqMap;           // Frequency to list of nodes

public:
    LFUCache(int capacity) {
        currSize = 0;
        maxSize = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            return -1; 
        }

        // Update frequency
        auto it = nodeMap[key];
        int val = it->value, freq = it->freq;

        freqMap[freq].erase(it); // Remove node from current frequency list
        if (freqMap[freq].empty() && minFreq == freq) {
            freqMap.erase(freq);
            minFreq++;
        }

        freq++; // Increase frequency
        freqMap[freq].push_front({key, val, freq}); // Add to new frequency list
        nodeMap[key] = freqMap[freq].begin();       // Update nodeMap

        return val;
    }

    void put(int key, int value) {
        if (maxSize == 0) return; // No capacity to store

        if (nodeMap.find(key) != nodeMap.end()) {
            // Key exists, update value and frequency
            auto it = nodeMap[key];
            it->value = value;
            get(key); // Update frequency using get
            return;
        }

        if (currSize >= maxSize) {
            // Evict least frequently used node
            auto &list = freqMap[minFreq];
            Node node = list.back();
            nodeMap.erase(node.key);
            list.pop_back();
            if (list.empty()) {
                freqMap.erase(minFreq);
            }
            currSize--;
        }

        // Insert new node
        minFreq = 1;
        freqMap[1].push_front({key, value, 1});
        nodeMap[key] = freqMap[1].begin();
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
