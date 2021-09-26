#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
// bool visited[2005]; 
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
int factorial( int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res = ((res)%mod * (i)%mod)%mod;
    return res%mod;
}
bool sortbysec(const pair<ll,vector<ll>> &a,
              const pair<ll,vector<ll>> &b)
{
    return (a.first < b.first);
}
bool visited[101][101];
char arr[101][101]; 
void rec(int i , int j, int n){

  
    if(i <= 0 || j <= 0){
        return; 
    }
    if(i > n || j >n){
        return; 
    }
    if(arr[i][j] == '1'){
        return; 
    }
    if(visited[i][j] == true){
        return; 
    }
      visited[i][j] = true; 
    rec(i+1,j,n); 
     rec(i,j+1,n); 
      rec(i-1,j,n); 
       rec(i,j-1,n); 
     
}
 void solve(){
     int n; 
     cin>>n; 
     int a,b,c,d; 
     cin>>a>>b>>c>>d; 
     
     memset(visited,false,sizeof(visited)); 
   
     for(int  i =1;i<=n;i++){
         for(int  j = 1; j <= n; j ++ ){
             cin>>arr[i][j]; 
         }
     }
     rec(a,b,n); 
     vector<pair<int,int>>v; 
     for(int i = 1; i<=n;i ++ ){
         for(int j  = 1; j <=n ; j ++ ){
             if(visited[i][j] == true){
                 v.push_back({i,j}); 
             }
         }
     }
      memset(visited,false,sizeof(visited)); 

          rec(c,d,n); 
     vector<pair<int,int>>v1; 
     for(int i = 1; i<=n;i ++ ){
         for(int j  = 1; j <=n ; j ++ ){
             if(visited[i][j] == true){
                 v1.push_back({i,j}); 
             }
         }
     }
    //  for(auto i : v){
    //      cout<<i.first<<" "<<i.second<<"\n"; 
    //  }
    //  cout<<"\n"; 
    //   for(auto i : v1){
    //      cout<<i.first<<" "<<i.second<<"\n"; 
    //  }
      int mini = 1e9; 
       for(int i = 0 ; i < v.size(); i ++ ){
           for(int j = 0 ; j < v1.size(); j ++ ){
               int ans = (v[i].first - v1[j].first)*(v[i].first - v1[j].first); 
               int ans1 =  (v[i].second - v1[j].second)*(v[i].second - v1[j].second) ;
               int ans2 = ans + ans1; 
               mini = min(ans2,mini);      
           }
       }
       cout<<mini; 

}

 int main()
 {   int t = 1; 
    //   scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}