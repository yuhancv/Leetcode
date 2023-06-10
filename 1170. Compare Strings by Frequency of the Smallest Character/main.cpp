#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    unordered_map<int, int> hashQuery, hashWord;

    int f(string s){
        map<char, int> treeMap;

        for (int i = 0; i < s.length(); ++i) {
            treeMap[s[i]]++;
        }

        return treeMap.begin()->second;
    }

    void visit(vector<string>& queries, vector<string>& words){
        for (int i = 0; i < queries.size(); ++i) {
            hashQuery[i] = f(queries[i]);
        }

        for (int i = 0; i < words.size(); ++i) {
            hashWord[i] = f(words[i]);
        }
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        visit(queries, words);

        for (int i = 0; i < queries.size(); ++i) {
            int counts = 0;

            for (auto it = hashWord.begin(); it != hashWord.end() ; ++it) {
                if (it->second > hashQuery[i]){
                    counts++;
                }
            }

            ans.push_back(counts);
        }
        return ans;
    }
};





int main() {


    return 0;
}
