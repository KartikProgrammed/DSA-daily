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

//1323. Maximum 69 Number

// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Approach:
// 1. Convert the integer to a string to manipulate its digits.
// 2. Iterate through the string and change the first '6' to '9'.
// 3. Convert the string back to an integer and return it.

// Code:
class Solution {
public:
    int maximum69Number (int num) {
        if(num<10){
            return 9;
        }
        string nums=to_string(num);
        for(int i=0;i<nums.length();i++){
            if(nums[i]=='6'){
                nums[i]='9';
                break;
            }
        }
        return stoi(nums);
    }
};


//239. Sliding Window Maximum

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Approach:
//use a priority queue to keep track of the maximum elements in the current window.

// Code:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<= i-k){
                pq.pop();
            }
            if (i >= k - 1) {
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};


//901. Online Stock Span

// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
// For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:
// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.


// Approach:
// 1. Use a stack to keep track of the prices and their spans.
// 2. For each price, pop elements from the stack until the top of the stack has a price greater than the current price.
// 3. The span for the current price is the difference between the current index and the
// index of the last price that was greater than the current price.
// 4. Push the current price and its span onto the stack.
// 5. Return the span for the current price.

// Code:
class StockSpanner {
private:
    stack<pair<int,int>> stk;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if(stk.empty() || stk.top().first > price){
            stk.push({price,1});
            return 1;
        }
        int temp=1;
        while(!stk.empty() && stk.top().first<=price){
            temp+=stk.top().second;
            stk.pop();
        }
        stk.push({price,temp});
        return temp;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


//146. LRU Cache

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.


// Approach:
// 1. Use an unordered_map to store the key-value pairs and a doubly linked list to maintain the order of usage.
// 2. When a key is accessed, move it to the front of the list.
// 3. When a new key is added, if the cache is full, remove the least recently used key from both the map and the list.

// Code:
class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // helper: remove node
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // helper: insert at front (after head)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);  // dummy head
        tail = new Node(0, 0);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            insert(node); // move to front
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            insert(node);
            mp[key] = node;
        }
    }
};


//460. LFU Cache

// Design and implement a data structure for a Least Frequently Used (LFU) cache.
// Implement the LFUCache class:
// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.
// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.
// The functions get and put must each run in O(1) average time complexity.

// Approach:
// 1. Use an unordered_map to store the key-value pairs and their frequencies.
// 2. Use another unordered_map to store the keys for each frequency.
// 3. Use a priority queue to keep track of the least frequently used keys.
// 4. When a key is accessed, update its frequency and move it to the appropriate frequency list.
// 5. When a new key is added, if the cache is full, remove the least frequently used key.
// 6. Ensure that both get and put operations run in O(1) average time


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