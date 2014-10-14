/*
Couldn't solve perfectly during contest.. poor me :(
Finally solved in practice :)
*/
#include <vector>
#include <list>
#include <map>
#include <set>
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

class GameOfStones {
public:
	int count(vector <int>);
};

int GameOfStones::count(vector <int> stones) {
    double sum=0;
    int N=stones.size();
    for(int i=0; i<N;i++) sum = sum + (double)stones[i];
    sum = sum/N;

    if(sum-floor(sum)>0) return -1;

    int tot=0;
    int average = (int) sum;

    for(int i=0; i<N; i++){

            if( abs(average-stones[i])%2 != 0  ) return -1;
            if(stones[i]<average)
            tot = tot + ((average-stones[i]))/2;

    }
    return tot;
}
