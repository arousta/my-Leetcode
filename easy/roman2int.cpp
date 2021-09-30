#include <map>
#include <string_view>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(const string s) {
        map<char,int> RomanVal{       {'I',1},   {'V',5},
                                      {'X',10},  {'L',50},
                                      {'C',100}, {'D',500},   
                                      {'M',1000} };
        
        int val=0;
        for( auto cur=s.begin(), next=cur+1, end=s.end()-1; cur!=end; ++cur, ++next ){
            const int curval = RomanVal[*cur],
                     nextval = RomanVal[*next];
            val += ( 1-2*(curval<nextval) )*curval;
        }
        val += RomanVal[s.back()];
        return val;
    }
};

int main( int argc, char* argv[] ){
    Solution S;
    S.romanToInt("LVIII");
    return EXIT_SUCCESS;
}