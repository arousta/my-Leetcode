#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if( n==1 ) return 1;
        if( n==2 ) return 2;
        return climbStairs(n-1)+climbStairs(n-2);

        // To avoid stack overflow of recursion
        // int ways=2, ways_previous=1;
        // for(int nstep=3; nstep<=n; ++nstep){
        //     const int ways_new = ways + ways_previous;
        //     ways_previous = ways;
        //     ways = ways_new;
        // }
        // return ways;
    }
};

int main(){
    Solution S;
    cout<< "= " << S.climbStairs(45) << endl;
}