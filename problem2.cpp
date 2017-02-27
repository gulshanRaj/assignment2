#include <bits/stdc++.h>
#define MAX_AR_SIZE 100
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int width, height;
    cin>>width>>height;
    cout<<"No of bad roads"<<endl;
    int err; cin>>err;
    int blocked[MAX_AR_SIZE+1][MAX_AR_SIZE+1];
    /**
     * blocked[i][j] == [00] - left and down are bad
     *               == [01] - left is bad
     *               == [10] - down is bad
     *               == [11] - both are good
     */  
    
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            blocked[i][j]=3;
        }
    }

    cout<<"enter bad roads"<<endl;
    for(int i=0; i<err; i++) {
        int a,b,c,d; cin>> a>>b>>c>>d;
        if(a+b<c+d) {
            if(a==c)
                blocked[c][d]^=2;
            else blocked[c][d]^=1;
        }
        else {
            if(a==c)
                blocked[a][b]^=2;
            else blocked[a][b]^=1;
        }
    }


    int dp[MAX_AR_SIZE+1][MAX_AR_SIZE+1];
    dp[0][0]=1;
    for(int i=0; i<width; i++) {
        if(blocked[0][i]==3) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int i=0; i<height; i++) {
        if(blocked[i][0]==3) dp[i][0] = 1;
        else dp[i][0] = 0;
    }
    for(int i=1; i<width; i++) {
        for(int j=1; j<height; j++) {
            if(blocked[i][j]^1 == 1)
                dp[i][j] += dp[i-1][j];
            if(blocked[i][j]^2 >= 1)
                dp[i][j] += dp[i][j-1];
        }
    }

    cout<<"Ans = "<<dp[width-1][height-1]<<endl;
    return 0;
}