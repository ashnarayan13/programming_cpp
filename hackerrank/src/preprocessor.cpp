/* Enter your macros here */
#define FUNCTION(f,q) void f(int &a, int &b){ if(b q a) a = b;}
#define toStr(s) #s //#s converts input to string
#define INF 10000000
#define foreach(v,i) for(int i=0; i<v.size(); i++)
#define io(v) cin>>v

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}