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
int atMostSum(int arr[], int n, int k)
{
    int sum = 0;
    int cnt = 0, maxcnt = 0;
 
    for (int i = 0; i < n; i++) {
         
        // If adding current element doesn't
        // cross limit add it to current window
        if ((sum + arr[i]) <= k) {
            sum += arr[i];
            cnt++;
        }
 
        // Else, remove first element of current
        // window and add the current element
        else if(sum!=0)
        {
            sum = sum - arr[i - cnt] + arr[i];
        }
 
        // keep track of max length.
        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
}
 int main()
 {
    //   int indexs[2000000]; 
     int t = 1; 
      scanf("%d",&t); 
        
         while(t--){
             int n; 
             scanf("%d",&n); 
             int k,s; 
             scanf("%d",&k); 
              scanf("%d",&s); 
             int arr[n]; 
             for(int  i = 0 ; i <n ; i ++ )
          scanf("%d",&arr[i]); 
             int lowerrr = 0 ;
             int maxeddd = -1;
             int loop = 0 ; 
        cccc:     while(true){
            loop++; 
                 if(lowerrr == n)
                 {
                     break; 
                 }
                 vector<int>v; 
                 
                 for(int  i = lowerrr ; i < n ; i ++ )
                 {
                     if(arr[i]<=s)
                     v.push_back(arr[i]); 
                     else
                     {
                     lowerrr = i ; 
                     break; 
                     }
                 }
                 if(v.size() == 0)
                 {
                     lowerrr = lowerrr + 1; 
                     continue; 
                 }

            //  cout<<lowerrr; 
            //   exit(0); 
                 int len = v.size(); 
              queue<pair<int,int>>q; 
             int low = 0; 
             ll sum = 0 ; 
             int sumlength = 0; 
             int low1 = 0; 
             int ctrrr = 0 ;
             for(int i = 0 ; i < len ; i ++ ){
                //  cout<<ctrrr<<"\n"; 
                //  ctrrr++; 
                 sum+=v[i]; 
                 if(sum>s)
                 {
                     q.push({low,i-1}); 
                     sumlength+=(i-low); 
                     low = i; 
                     sum=v[i];
                      continue; 
                 }
                 if(q.size() == k){
                     low1 = i ; 
                     break; 
                 }
                 if(i == len - 1)
                 {
                     sumlength+=(len-low); 
                   q.push({low,len-1}); 
                 }
             }
             while(!q.empty())
             {
                 cout<<q.front().first<<" "<<q.front().second<<"\n";
                 q.pop(); 
             }
        }
            //  if(loop == 3){
            //    for(auto i : v)
            //    cout<<i;  
            //      exit(0); 
            //  }
           
            //  cout<<"sss"; 
            //  cout<<low1; 
            //  while(!q.empty()){
            //      cout<<q.front().first<<" "<<q.front().second<<"\n"; 
            //      q.pop();
            //  }
            
          
             //   cout<<sumlength; 
        //     int maxed = sumlength; 
        //       if(q.size()<k){
        //           maxeddd = max(maxeddd,len); 
        //           lowerrr+=1; 
        //          goto cccc; 
        //         //   exit(0); 
        //       }
              
        //       bool ans = true; 
        //       int ctr = 0 ;
             
        //       while(true){
            
        //         //   ctr++; 
        //         //   if(ctr == 5)
        //         //   break; 
        //           pair<int,int>p = q.front(); 
        //           q.pop(); 
        //           sumlength-=(p.second-p.first+1);
        //           ll sum = 0 ;
        //           int high1 = -1 ;
        //           for(int j = low1; j < len; j ++ )
        //           {
        //                 sum+=v[j]; 
        //               if(sum>s)
        //               {
        //               high1 = j-1; 
        //               break; 
        //               }
                
        //           }
                
        //         //   cout<<low1<<" "<<high1; 
        //           if(high1 == -1)
        //           {
        //               high1 = len - 1; 
        //               ans = false;
        //           }
        //           sumlength+=high1-low1+1;
             
        //           maxed = max(maxed,sumlength); 
        //           q.push({low1,high1}); 
        //           if(ans == false){
        //               break; 
        //           }
        //             //   cout<<"eee"<<low1<<"eee\n"; 
        //           low1 = high1+1;
        //         //   cout<<low1<<"\n"; 
        //       }
                
        //     //   cout<<maxed<<"\n"; 
        //     maxeddd = max(maxed,maxeddd); 

        //     // cout<<maxeddd; 
        //     //    exit(0); 

        //     //  q.push({low,n-1}); 
        //     //  while(!q.empty())
        //     //  {
        //     //      cout<<q.front().first<<" "<<q.front().second<<"\n"; 
        //     //      q.pop(); 
                  
        //     //  }
        //     lowerrr++; 
        //  }
        //  cout<<maxeddd<<"\n"; 
        //  }
        }
 
 }