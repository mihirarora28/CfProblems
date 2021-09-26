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
    cin>>n; 
    int arr[n]; 
    map<int,bool>mapp; 
    for(int i = 0 ; i < n ; i ++ )
    {    
    cin>>arr[i]; 
    // mapp[arr[i]]++; 
    }
    vector<int>v1; 
    set<int>s; 
    for(int i = 0 ; i  < n ; i ++ )
    {
        if(mapp[arr[i]] == true){
            break; 
        }
        mapp[arr[i]] = true; 
        s.insert(arr[i]); 
        if(s.size() == i + 1){
            v1.push_back(i+1); 
        }
    }
    ///////////////
    s.clear(); 
    // v1.clear();
    vector<int>v2; 
    mapp.clear(); 
    //   vector<int>v1; 
    // set<int>s; 
    for(int i = n-1 ; i  >=0 ; i -- )
    {
        if(mapp[arr[i]] == true){
            break; 
        }
        mapp[arr[i]] = true; 
        s.insert(arr[i]); 
        if(s.size() == n - i && *(s.begin()) == 1 && *(s.end()) == n-i) ){
            v2.push_back(i+1); 
        }
    }
    for(auto i : v1){
        cout<<i<<" "; 
    }
    cout<<"\n"; 
   for(auto i : v2){
        cout<<i<<" "; 
    }
   
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