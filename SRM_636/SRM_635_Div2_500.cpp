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
#include <string.h>
using namespace std;

class SortishDiv2 {
public:
	int tot;
	int arr[102];
	int baki[102];
	int p[102];
	int sq[102];
	int ways(int, vector <int>);
	void rec(int , int, int);
	bool vst[102];
	int NN;
	int ans;

};

void SortishDiv2::rec(int now, int N, int sortedness){

    if(now==N){

        int tot=0;
        int ind=0;


        int sqq[102];
        for(int i=0; i<NN; i++) sqq[i]=sq[i];

        for(int i=0; i<NN; i++)
        if(sq[i]==0){
            sqq[i] = p[ind++];
        }

        for(int i=0; i<NN; i++)
            for(int j=i+1; j<NN; j++)
                if(sqq[i]<sqq[j]) tot++;

        if(tot==sortedness) ans++;

        return;
    }

    for(int i=0; i<N; i++){

        if(!vst[baki[i]]){

            vst[ baki[i] ]=true;
            p[now] = baki[i];
            rec(now+1,N,sortedness);
            vst[baki[i]]=false;

        }
    }
}

int SortishDiv2::ways(int sortedness, vector <int> seq) {
    tot=0;
    int N=seq.size();
    NN = N;
    for(int i=0; i<N; i++) sq[i]=seq[i];

    for(int i=1; i<=N; i++) arr[i]=0;

    int tot_one=0;

    for(int i=0; i<seq.size();i++) {arr[seq[i]]=1; tot_one++;}
    int ind=0;

    for(int i=1; i<=N; i++){
        if(arr[i]==0) baki[ind++]=i;
    }


    ans=0;
    memset(vst,false,sizeof(vst));
    rec(0,ind,sortedness);
    return ans;
}
