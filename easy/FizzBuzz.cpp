#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    struct generator {
        int k=0;
        string operator()()
        {return to_string(++k);}
    };

    void fill_fizzBuzz( vector<string>& v, const int devnum, const string& word ){
        int k = v.size()/devnum;
        for(int i=1; i<=k; ++i)
            v[devnum*i-1] = word;
    }

public:

    void fizzBuzz(int n) {
        vector<string> v(n);
        generate( begin(v),end(v), generator() );

        fill_fizzBuzz(v,3,"Fizz");
        fill_fizzBuzz(v,5,"Buzz");
        fill_fizzBuzz(v,15,"FizzBuzz");

	int i=0;
	for(auto const& x:v)
		cout << ++i << ": " << x << "\n";

    }
};

int main( int argc, char* argv[] ){
	Solution S;
	while(true){
		int n;
		cin >> n;
		S.fizzBuzz(n);
	}
}


