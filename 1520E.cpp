#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 ll mod = 10000000000007;
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
     string s; 
     cin>>s; 
     int start = -1; 
     int end = -1;
     int maxed =0; 
     int count = 0; 
     int i; 
     for( i= 0 ; i < n; i ++ ){
            //  cout<<i<<" "; 
         if(s[i] == '*'){
         
              count = 1;
             for(int j = i + 1; j < n; j ++ ){
                 if(s[j] == '*'){
                     count++; 
                     if(j == n-1)
                     goto cc;
                 }
                 else{
                     if(count > maxed){
                         start = i ; 
                         end = j-1; 
                         maxed = count; 
                          i = i + j - 1; 
                     }
                       break; 
                 }
             }
         }
     }
     cc:
     ////////////////////////
    //  cout<<count; 
       if(count > maxed){
             start = i ; 
            end = n-1; 
            maxed = count;          
    }
    if(start == -1 && end == -1){
        cout<<0; 
        return; 
    }
    int ans = 0 ;
    int c = start - 1; 
    for(int i = start-1; i >=0; i-- ){
        if(s[i]  == '*'){
            ans+=abs(i-c);
            c--;  
        }
    }
    int c1 = end + 1; 
      for(int i = end + 1; i < n; i++ ){
        if(s[i]  == '*'){
            ans+=abs(i-c1); 
            c1++; 
        }
    }
    cout<<ans; 
    //  cout<<maxed<<"\n"<<start<<" "<<end<<"\n"; 
     
}
 int main()
 {
     cin.tie(NULL);
     int t = 1; 
      scanf("%d",&t); 

        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }