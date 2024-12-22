
#include <iostream>

//2940. Find Building Where Alice and Bob Can Meet
// You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.
// If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
// You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.
// Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

//APPROACH 1:- idk why it doesnt work but it should according to me..(please help)
//while the complexity is still nice O(n*q) well reduce it further


//CODE:-
class Solution {
public:
	vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
		vector<int> answer(queries.size(),-1);
		for(int i=0; i<queries.size(); i++) {
			int first=queries[i][0];
			int second=queries[i][1];
			int st=max(first,second);
			int h1=heights[first];
			int h2=heights[second];
			for(int k=st; k<heights.size(); k++) {
				if(heights[k]>=h1 && heights[k]>=h2) {
					answer[i]=k;
					break;
				}
			}
		}
		return answer;
	}
};

//APPROACH 2:- monotonic stack
class Solution {
public:
	vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
		vector<pair<int, pair<int, int>>> q;
		vector<int> ans(queries.size(), -1);

		for (int i = 0; i < queries.size(); i++) {
			q.push_back({max(queries[i][1],queries[i][0]), {min(queries[i][1],queries[i][0]), i}});
		}

		sort(q.rbegin(), q.rend());

		map<int, int> m;
		stack<int>s;
		for (int j = 0; j < q.size(); j++) {
			int f = q[j].first;
			int l = heights.size();
			if (j > 0) l = q[j - 1].first;

			for (int i = l-1; i >= f; i--) {
				if(s.empty()) {
					s.push(heights[i]);
					m[heights[i]]=i;
				}
				else {
					while(!s.empty() && s.top()<=heights[i]) {
						m.erase(s.top());
						s.pop();
					}
					s.push(heights[i]);
					m[heights[i]]=i;
				}
			}
			int maxi = max(heights[q[j].first], heights[q[j].second.first]);
			if(heights[q[j].second.first]>=heights[q[j].first] && q[j].first!=q[j].second.first) {
				auto it = m.upper_bound(maxi);
				if (it != m.end()) {
					ans[q[j].second.second] = it->second;
				}
			}
			else {
				auto it = m.lower_bound(maxi);
				if (it != m.end()) {
					ans[q[j].second.second] = it->second;
				}
			}
		}

		return ans;
	}
};
