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

#define sort(x)                       sort(all(x))
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
typedef vector<VLL> VVLL;

typedef vector<string> VS;
typedef vector<VS> VVS;

struct Order
{
    bool operator()(PII const& a, PII const& b) const
    {
        return a.second > b.second;
    }
};

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen ("edges.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	VVII g;
	int n, e;
	cin>>n>>e;
	g.resize(n+1);
	int v1,v2,w;
	FOR(i,0,e)
	{
		cin>>v1>>v2>>w;
		g[v1].pb(mp(v2,w));
		g[v2].pb(mp(v1,w));
	}
	priority_queue<PII, VII, Order> Q;
	vector<bool> isVisited(n+1,false);
	LL sum = 0 ;
	FOR(i,0,sz(g[1]))
	{
		Q.push(g[1][i]);
	}
	int T = 1;
	isVisited[1] = true;
	while(T < n)
	{
		int j = Q.top().first;
		if(isVisited[j] == false)
		{
			sum += (LL)Q.top().second;
			T++;
			// DEBUG(j);
			// DEBUG(Q.top().second);
		}
		isVisited[j] = true;
		Q.pop();
		for(int i = 0; i < sz(g[j]); i++)
			if (isVisited[g[j][i].first] == false)
			{
				Q.push(g[j][i]);
			}
	}
	cout<<sum<<endl;
	
	return 0;
}