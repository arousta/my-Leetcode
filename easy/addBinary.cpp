#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
    {
        if( a=="0" && b=="0" ) return "0";
        if( a=="0" && b=="1" ) return "1";
        if( a=="1" && b=="0" ) return "1";
        if( a=="1" && b=="1" ) return "10";

        constexpr char c0='0', c1='1';
        const size_t na=a.size(), nb=b.size();
        const size_t n = max(na,nb); 
        if( na<n ) a = string(n-na,c0)+a;
        if( nb<n ) b = string(n-nb,c0)+b;
        
        string sum(n+1,c0);
        bool carry_forward = false;
        for( auto ia=a.rbegin(), ib=b.rbegin(), is=sum.rbegin();
                                                    ia!=a.rend();
                                                   ++ia,++ib,++is)
        {
            const char achar = *ia,
                       bchar = *ib;
            if( achar==c1 && bchar==c1 ){
                *is = carry_forward ? c1:c0;
                carry_forward = true;
            }
            else if( achar==c0 && bchar==c0 ){
                *is = carry_forward ? c1:c0;
                carry_forward = false;
            }
            else // 01 or 10
                *is = carry_forward ? c0:c1;
        }
        if( carry_forward )
            sum.front() = c1;
        else
            sum.erase( sum.cbegin() );
        
        return sum;
    }
};

int main(){
    Solution S;
    cout<< "sum: " << S.addBinary("100","110010") << endl;
}