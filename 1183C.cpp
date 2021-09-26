#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1000000007;
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (prime[p])
        primes.push_back(p); 
}
ll power(ll x,  ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2)%mod) * (power(x, y / 2)%mod))%mod;
    else
        return ((((x  %mod) * ((power(x, y / 2)%mod)))%mod * (power(x, y / 2)%mod))%mod)%mod;
}
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
 
 void solve(){
	 ll k,n,b,a; 
	 cin>>k>>n>>a>>b; 
	 //check negative 
	 if(k<=n*b){
		 cout<<-1; 
		 return; 
	 }
	 ll lower = 0; 
	 ll upper = n; 
	 ll maxed = -1; 
	 while(lower<=upper){
		 ll mid = (lower+upper)/2; 
		//  int c1 = mid*a; 
		 ll c2 = (k-mid*a);
	     ll c3 = (n-mid)*b; 
		//  cout<<c2<<" "<<c3<<"\n"; 
		 if(c2 > c3){
			 lower = mid + 1; 
			 maxed = max(maxed,mid); 
		 }
		 else{
			 upper = mid - 1; 
		 }
	 }
	 cout<<maxed; 
}
 int main()
 {

     int t = 1; 
      scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }