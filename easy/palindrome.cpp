#include <cmath>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(  x<0 ) return false;
        if( x==0 ) return true;

        constexpr int base = 10; // numbers in 10 base
        // const int ndigits = ceil( log10(x)+.0001 );
        int digits[10]; // maximum possible number of digits for 2^31
        
        int mantisa=base, ndigits=0;
        while( x!=0 ) {
            const int r = x % base;
            digits[ndigits] = r;
            ++ndigits;
            
            x -= r;
            x /= base;
        }
        
        int *beg=digits, *end=digits+ndigits-1;
        for( int i=1; i<=ndigits/2; ++i, ++beg,--end ){
          if(*beg != *end) 
              return false;
        }
        return true;
    }
};


// another simpler and faster (%25)
    // bool isPalindrome(int x) {
    //     string temp=to_string(x);
    //     string t=temp;
    //     reverse(t.begin(),t.end());
    //     return t==temp;
    // }

int main( int argc, char* argv[] ){
    Solution S;
    std::cout << "> " << S.isPalindrome(120030221);
}