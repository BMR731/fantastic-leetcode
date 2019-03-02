//
// Created by Saijun Hu on 2019/1/31.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
//second write,
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //step 1: find the minimum ,then offset

        int low = 0;
        int high = nums.size()-1;
        int mid=0;

        while(low<high){
            mid = (low+high)>>1;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        int offset = low;
        cout<<offset<<endl;
        //step 2: find the target value;
        low=0;
        high=nums.size()-1;
        mid=0;
        while(low<=high){
            mid = (low+high)>>1;
            int mid_rectified = (mid+offset)%nums.size();
            if(target==nums[mid_rectified]){
                cout<<mid<<"-"<<mid_rectified<<endl;
                return mid_rectified;
            }else if(nums[mid_rectified]>target){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
};
