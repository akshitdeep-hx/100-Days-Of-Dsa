/*
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (const string& word : words) {
            for (char c : word) {
                if (inDegree.find(c) == inDegree.end()) {
                    inDegree[c] = 0;
                }
            }
        }

        for (size_t i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());

            if (w1.length() > w2.length() && w1.substr(0, len) == w2.substr(0, len)) {
                return "";
            }

            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto const& [curr, count] : inDegree) {
            if (count == 0) {
                q.push(curr);
            }
        }

        string result = "";
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result += u;

            if (adj.count(u)) {
                for (char v : adj[u]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }

        if (result.length() < inDegree.size()) {
            return "";
        }

        return result;
    }
};