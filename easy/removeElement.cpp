#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, const int val)
    {
        if( nums.empty() ) return 0;

        size_t count=0;
        for(auto cur=begin(nums),back=end(nums)-1; cur<=back; ++cur, ++count)
        {
            if(*cur != val) continue;
            if(cur == back) return count;

            while(*back==val){
                --back;
                if( back==cur ) return count;
            }
            *cur = *back;
            --back;
        }
        return count; 
    }
};

int main(int argc, char* argv[]){
    Solution S;

    vector<int> nums = {3,2,2,3};
    // S.removeElement(nums,3);

    // nums = {0,1,2,2,3,0,4,2};
    // S.removeElement(nums,2);

    // nums = {};
    // S.removeElement(nums,0);

    // nums = {1};
    // S.removeElement(nums,1);

    nums = {0,1,2,2,2,0,4,2};
    S.removeElement(nums,2);
    for(auto i=begin(nums), endi=end(nums); i!=endi; ++i){
        int x = *i;
    }
}


// The solution I like: use two iterators
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
// int k=0;
// for(int i=0 ; i<nums.size() ; i++)
// {
//     if(nums[i]!=val)
//     {
//         nums[k]=nums[i];
//         k++;
//     }
// }
//         return k;
//     }
// };

// Good one using _STL_ALGOBASE_Hclass Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
//         return nums.size();
//     }
// };