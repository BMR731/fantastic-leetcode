//
// Created by Saijun Hu on 2019/1/23.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>
//TODO with the help of 3sum and 2sum,4 ms, faster than 100.00% of C++
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        //3sum idea
        for (int i = 0; i < len; ++i) {
            if(i>0 && nums[i]==nums[i-1])
                continue;// skip the duplicate character
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
                break; //then there isn't a solution
            if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target)
                continue;//current i doesn't have  a solution
            //2sum idea
            for(int j=i+1;j<len-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[j]+nums[j+1]+nums[j+2]>target-nums[i]) break;
                if(nums[j]+nums[len-2]+nums[len-1]<target-nums[i]) continue;
                int left=j+1,right=len-1;
                while(left<right){
                    int sum = nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target){ left++;}
                    else if(sum>target){ right--;}
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        //skip duplicate
                        do{ left++;} while(nums[left]==nums[left-1] && left<right);
                        do{ right--;} while(nums[right]==nums[right+1] && left<right);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> input {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = s.fourSum(input,0);
    return 0;
}