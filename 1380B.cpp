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
    int n; 

    string s; 
	cin>>s; 
	map<char,int>mapp; 

	for(auto i : s)
	{
		mapp[i]++;
	}
	int maxed = -1; 
	char c =  'P'; 
	for(auto i : mapp){
		if(maxed < i.second)
		{
		maxed = max(maxed,i.second); 
		c = i.first; 
		}
	}
	char c1; 
	if(c == 'R')
	c1 = 'P'; 
	if(c == 'P')
	c1 = 'S'; 
	if(c == 'S')
	c1 = 'R';
	for(int i = 0; i  <s.length() ; i ++ )
	cout<<c1; 
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