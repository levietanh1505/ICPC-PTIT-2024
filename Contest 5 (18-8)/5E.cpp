// Cho một dãy số gồm N phần tử A[1], A[2], ..., A[N] và số nguyên K. 
// Nhiệm vụ của bạn là hãy đếm số lượng dãy con liên tiếp thỏa mãn số cặp nghịch thế trong dãy con đó >= K.
// Số cặp nghịch thế của dãy con A[i], A[i+1], ..., A[j] là số cặp (u, v) thỏa mãn i ≤ u < v ≤ j và A[u] > A[v].
// Input:
// Dòng đầu tiên là số nguyên dương N và K (1 ≤ N ≤ 100000, K ≤ N*(N-1)/2).
// Dòng tiếp theo gồm N số nguyên dương A[i] (0 ≤ A[i] ≤ 109).
// Output:
// In ra một số nguyên duy nhất là đáp số của bài toán.



#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define el "\n"
#define pb push_back
#define all(x) x.begin(),x.end()
ll mod=1e9+7;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
 
 
 
 
void fast(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
 
 
 
 
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("INPUT.inp","r",stdin);
	freopen("OUTPUT.out","w",stdout);
	#endif 
	fast();
	ordered_multiset ms;
	ll n,k; cin>>n>>k;
	ll a[n+1];
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n==1){
		if(0>=k) cout<<1;
		else cout<<0;
		return 0;
	}
	if(k==0){
		cout<<n*(n+1)/2; return 0;
	}
	ms.insert(a[1]);
	ll l=1,r=2;
	ll dem=0, ans=0;
	map<ll,ll> mp;
	mp[a[1]]++;
	ll pos=1;
	while(l<=n&&r<=n){
		if(pos!=r){
			ll x=ms.order_of_key(a[r]);
			x=ms.size()-x-mp[a[r]];
			dem+=x;
			ms.insert(a[r]); mp[a[r]]++;
			pos=r;
		}
		if(dem>=k){
			ans+=n-r+1;
			ll y=ms.order_of_key(a[l]);
			dem-=y;
			mp[a[l]]--;
			ms.erase(ms.find_by_order(ms.order_of_key(a[l])));
			l++;
		}
		else{
			r++;
		}
	}
	cout<<ans<<el;
}
