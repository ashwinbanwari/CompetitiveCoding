// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long 
#define gc getchar_unlocked
 
void scan(ll &x)
{
    register ll c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
 
int main()
{
	ll n,q,i,j,k;
	scan(n);
	scan(q);
 
	ll arr[n];
	for(i=0;i<n;i++) { scan(arr[i]); }
	
	queue<ll> q1,q2;
	sort(arr,arr+n);
    
    ll queries[q];
    for (ll i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
	for(int i=n-1;i>=0;i--) q1.push(arr[i]);
	ll count =1,temp, queryNum = 0;
	
	while(queryNum != q){
        temp = queries[queryNum];
		ll ans;
		for(;count<=temp;count++)
		{
			if(q1.front()>=q2.front()) ans = q1.front(),q1.pop();
			else ans = q2.front(),q2.pop();
			q2.push(ans>>1);
		}
        queryNum++;
		printf("%lld\n",ans);
	}
 
}  