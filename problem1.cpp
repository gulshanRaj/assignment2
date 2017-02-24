#include <bits/stdc++.h>
#define MAX_SEQ_LENGTH 51
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int ar[MAX_SEQ_LENGTH];
    cout<<"Enter no of numbers in seq"<<endl;
    int n; cin>>n;
    cout<<"Give sequence"<<endl;
    for(int i=0; i<n; i++)
        cin>> ar[i];

    int dp[MAX_SEQ_LENGTH]={0};
    bool dp_state[MAX_SEQ_LENGTH]={0};

    dp[0]=1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(j==0) {
                dp[i]=dp[0]+1;
                dp_state[i]=(ar[i]>ar[j]);
                if(ar[i]==ar[j] && dp[j]+1 >= dp[i]) {
                    dp[i]=dp[j];
                    dp_state[i]=dp_state[j];
                }
            }
            else {
                if((ar[i]<ar[j])^dp_state[j] == 0) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        dp_state[i]= !dp_state[j];
                    }
                }
                if(ar[i]==ar[j] && dp[j]+1 >= dp[i]) {
                    dp[i]=dp[j];
                    dp_state[i]=dp_state[j];
                }

            } 

        }
    }

    //find max
    int ans=0;
    for(int i=0; i<n; i++) {
        if(dp[i]>ans) 
            ans=dp[i];
    }
    cout<<ans<<endl;
    
}