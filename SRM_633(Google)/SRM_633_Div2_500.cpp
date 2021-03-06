#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class Jumping {
public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {

        double xx = (double) x;
        double yy = (double) y;

        double dist = sqrt( x*x + y*y ) ;

        double tot = 0;
        double c = 0;
        double b = jumpLengths[jumpLengths.size()-1];
        double a = dist;

        for(int i=0; i<jumpLengths.size();i++){

            tot = tot+(double) jumpLengths[i];

            if(i<jumpLengths.size()-1)
                c = c + (double) jumpLengths[i];
        }

        //cout<<dist<<" "<<tot<<endl;

        if(tot==dist) return "Able";

        if(tot<dist) return "Not able";

        if(tot>dist&&jumpLengths.size()==1) return "Not able";

        b = 0;
        for(int i=0; i<jumpLengths.size();i++){
            b = b + (double) jumpLengths[i];
            c = tot - b;
            if( a + b > c && b + c > a && c + a > b) return "Able";
        }


        return "Not able";

	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	Jumping *obj;
	string answer;
	obj = new Jumping();
	clock_t startTime = clock();
	answer = obj->ableToGet(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	vector <int> p2;
	string p3;

	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 4;
	int t2[] = {2,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 4;
	int t2[] = {4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Not able";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 4;
	int t2[] = {6};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Not able";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 0;
	p1 = 1;
	int t2[] = {100,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 300;
	p1 = 400;
	int t2[] = {500};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 11;
	p1 = 12;
	int t2[] = {1,2,3,4,5,6,7,8,9,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = 11;
	p1 = 12;
	int t2[] = {1,2,3,4,5,6,7,8,9,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Not able";
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
