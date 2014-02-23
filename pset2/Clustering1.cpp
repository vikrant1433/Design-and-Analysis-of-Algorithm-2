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

// #define sort(x)                       sort(all(x))
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
typedef pair<PII, int> PIII;
typedef vector<PIII> VIII;
class UF
{
	VI id;
	VI size;
	int root(int i);
public:
	
	UF(int N);
	~UF();
	void Union (int p, int q);
	bool connected (int p, int q);
	void printVector();
};
UF::UF(int N)
{
	id.resize(N);
	size.resize(N,1);
	FOR(i,0,N)
	{
		id[i] = i;
	}
}
UF::~UF()
{
	id.clear();
	size.clear();
}
void UF::Union(int p, int q)
{
	if(!connected(p,q))
	{
		int i = root(p);
		int j = root(q);
		if(size[i] > size[j])
		{
			id[j] = i;
			size[i] += size[j];
		}
		else
		{
			id[i] = j;
			size[j] += size[i];
		}
	}
	
}
bool UF::connected(int p, int q)
{
	return root(p)==root(q);
}
int UF::root(int i)
{
	while(i != id[i])
	{
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}
void UF::printVector()
{
	FOR(i,0,sz(id))
		cout<<id[i]<<" ";
	cout<<endl;
	FOR(i,0,sz(id))
		cout<<i<<" ";
	cout<<endl;
	FOR(i,0,sz(size))
		cout<<size[i]<<" ";
	cout<<"\n"<<endl;
}

struct order
{
	bool operator()(const PIII & a, const PIII & b) const
	{
		return a.second < b.second;
	}
};

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen ("clustering1.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int N;
	cin>>N;
	UF v(N+1);
	int p,q,w;
	VIII g;
	while(cin>>p>>q>>w)
	{
		g.pb(mp(mp(p,q),w));
	}
	sort(g.begin(), g.end(), order());
	int SC = 0;
	int i = 0;
	int k = 4;
	while(N >= k)
	{
		p = g[i].first.first;
		q = g[i].first.second;
		if (v.connected(p,q) == false)
		{
			N--;
			SC = g[i].second;
		}
		v.Union(p,q);
		i++;
	}
	cout<<SC<<"\n";
	// v.printVector();

	return 0;
}


