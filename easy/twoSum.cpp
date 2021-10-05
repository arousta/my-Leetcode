#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        // simple brute force solution. start from begin
        // look for all possible combinations
        for(auto i=begin(nums), last=end(nums); i!=last; ++i){
            auto res = find_if(i+1,last, [&](int val){ return val+*i==target; });
            if( res!=last )
                return {int(i-begin(nums)), int(res-begin(nums))};
        }
        return {};
    }
};


// The optimal solution for lookup using hash container
// class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int,int> hm;
//        vector<int> ans(2);
//        for(int i=0;i<nums.size();i++){
//            if(hm.find((target- nums[i])) != hm.end()){
//                ans[0]=hm[target- nums[i]];
//                ans[1]=i;
//                break;
//            }
//            else hm[nums[i]]=i;
//        }
//        return ans;
//    }
//};