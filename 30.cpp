//
// Created by Saijun Hu on 2019/1/28.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//TODO i haven't any bit of thought...oh,the word length is fixed,use hashmap is cool
// 120 ms, faster than 54.32% of C++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> hash_map;
        for(string word : words){
            hash_map[word]++;
        }
        int len_s = s.length();
        int num_word = words.size();
        if(len_s==0 || num_word==0) return res;
        int len_word = words[0].length();
        for(int i=0;i<len_s - num_word*len_word + 1;i++){
            unordered_map<string,int> seen;
            int j=0;
            for(;j<num_word;j++){
                string word = s.substr(i+j*len_word,len_word);
                if(hash_map.find(word) != hash_map.end()){
                    seen[word]++;
                    if(seen[word]>hash_map[word]) break;
                }else{ break;}
            }
            if(j==num_word) res.push_back(i);
        }
        return res;
    }
};

