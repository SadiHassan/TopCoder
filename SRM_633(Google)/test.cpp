#include<iostream>
using namespace std;

int main(){

int arr[100][100];

for(int i=0;i<100;i++) for(int j=0;j<100;j++) arr[i][j]=0;

int n=25;
int tot=0;
int factor=0;
int i, j;

while(1){

    tot = 0;

    i=0+factor*2;

    for(j=0+factor*2; j<=((n-1)-2*factor); j++)
    {
        arr[i][j]=1;
        tot++;
    }

    if(tot==1) break;

    i = (n-1)-2*factor;
    for(j=0+factor*2; j<=((n-1)-2*factor); j++)
    {
        arr[i][j]=1;
        tot++;
    }

    j = 0+2*factor;
    for(int i=0+factor*2; i<=((n-1)-2*factor); i++)
    {
        arr[i][j]=1;
        tot++;
    }

    j = (n-1)-2*factor;
    for(int i=0+factor*2; i<=((n-1)-2*factor); i++)
    {
        arr[i][j]=1;
        tot++;
    }

    factor++;
    //if(tot==0) break;
}

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
        cout<<arr[i][j]<<" ";

    cout<<endl;
}

return 0;
}
