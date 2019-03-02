#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//TODO
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //思路一:排序后双指针扫描，O(nlogn)
        //method2: using hashtable
        vector<int> res;
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            int complement = target-nums[i];
            if(hash.find(complement) != hash.end()){//if we find the complement
                res.push_back(i);
                res.push_back(hash[complement]);
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
