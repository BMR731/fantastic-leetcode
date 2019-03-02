//
// Created by Saijun Hu on 2019/1/22.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//TODO try to use to 2sum to address it .
//sort first, then use two pointer method to solve 2sum sub-problem
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return vector<vector<int>>();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++){
            int target_sum = 0 - nums[i];
            if(i==0 || nums[i]!=nums[i-1] ){//skip the duplicate
                for(int left=i+1,right=nums.size()-1;left<right;){
                    if(nums[left]+nums[right]==target_sum){
                        res.push_back({nums[i],nums[left],nums[right]});
                        //remove the duplicate
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        left++;right--;
                    }else if(nums[left]+nums[right]<target_sum){left++;}
                    else{ right--;}
                }
            }
        }
        return res;
    }
};