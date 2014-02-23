using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define FOR(i,a,b)                	 for(int i=a;i<b;i++)
#define FOREACH(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define REP(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))
#define PI                     		  acos(-1)
#define sqr(x)                 		  ((x) * (x))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define msort(x)                      sort(all(x))
#define gsort(x)                      sort(all(x), greater<typeof(*((x).begin()))>())
#define mp 							  make_pair

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef int64_t LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VVI> VVVI;
typedef vector<VLL> VVLL;
typedef vector<VVI> VVVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
bool isNegativeCycle(VVVI & v, int N)
{
	FOR(i,1,N+1)
	{
		if (v[i][i][N%2] < 0)
			return true;
	}
	return false;
}
int ssp(VVVI& v, int N)
{
	int m = INT_MAX;
	FOR(i,1,N+1)
		FOR(j,1,N+1)
			m = min(m, v[i][j][N%2]);
	return m;
}
void display(VVVI & v, int N)
{
	FOR(i,1,N+1)
	{
		FOR(j,1,N+1)
		{
			cout<<v[i][j][N%2]<<"    ";
		}
		cout<<"\n";
	}
}
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen ("g3.txt", "r", stdin);
		// freopen ("g1.out.txt", "w", stdout);
	#endif
	int N,M; cin>>N>>M;
	VVVI v(N+1, VVI(N+1,VI(2,INT_MAX)));
	FOR(k,0,M)
	{
		int i,j,w;
		cin>>i>>j>>w;
		v[i][j][0] = (i==j ? 0 : w);
	}
	FOR(k,1,N+1)
		v[k][k][0] = 0;
	// cout<<v[1][13][0]<<"\n";
	for (int k = 1; k <= N; k++)
	{
		int p = k%2;
		int q = (k-1)%2;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (v[i][k][q] == INT_MAX || v[k][j][q] == INT_MAX)
				{
					v[i][j][p] = v[i][j][q];
				}
				else
					v[i][j][p] = min(v[i][j][q], v[i][k][q] + v[k][j][q]);
			}
		}
	}
	// display(v,N);
	cout<<"\n";
	if(isNegativeCycle(v,N))
		cout<<"negative cycle found";
	else
		cout<<ssp(v, N);

	// vector<vector<vector<int> > >v;

	return 0;
}