//C++ 
#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
int main() 
{ 
    ll n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int max = 0;
    for(int i=0;i<n;i++){
    	int sum = 0;
		for(int j = n-1;j>=i;j--){
			sum+=a[j];
		}
		max = (sum>max)?sum:max;
    }
    
    cout<<max;
    
    return 0;
}

