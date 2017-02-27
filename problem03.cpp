    #include<bits/stdc++.h>
    using namespace std;
     
    int search(int list[],int r,int num);
     
    int LIS(long long a[],int s,int n){
    	int list[n];
    	for(int i=0; i<n; i++)
            list[i]=0;

    	list[0]=a[s];
    	int len=1;
    	for(int i=s+1;i<n+s;i++){
    		if(a[i]<list[0])
    		list[0]=a[i];
    		
    		else if (a[i]>list[len-1])
    		list[len++]=a[i];
    		
    		else
    		list[search(list,len-1,a[i])]=a[i];
    	}
    	return len;
    }
     
     
    int main(){
        int t;
        cin>>t;
        while(t--){
    	
    	int n;
    	cin>>n;
    	long long int a[2*n];
    	for(int i=0;i<n;i++)
    	{
    	   cin>>a[i];
    	   a[n+i]=a[i];       
        }
        int MAX=0;
        int answer;
    	for(int i=0;i<n;i++){	
            answer=LIS(a,i,n);
        if(answer>MAX)
            MAX=answer;	
       }
    	cout<<MAX<<endl;
     
    }
    	return 0;
    } 

int search(int list[],int r,int num){
        int l=0;
        while(r-l>1){
            int m=(l+r)/2;
            if(list[m]>num)
            r=m;
            else
            l=m;
        }
        return r;
    }