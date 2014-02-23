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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

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
#define mp 							  make_pair

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef long long LL;
typedef unsigned long long ULL;
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


class Graph
{
	int n;
	vector<bool> nodes;
	vector< vector<int> > g;
public:
	Graph(int n);
	~Graph();
	vector<int>& operator [] (int i);
	bool isVisited(int n);
	void markVisited(int n);
	int numNodes();
};
Graph::Graph(int n)
{
	Graph::n = n;
	nodes.resize(n,0);
	g.resize(n);
}
vector<int>& Graph::operator [] (int i)
{
	return g[i];
}
bool Graph::isVisited(int n)
{
	return nodes[n];
}
void Graph::markVisited(int n)
{
	nodes[n] = true;
}
int Graph::numNodes()
{
	return n;
}
Graph::~Graph()
{
	nodes.clear();
	g.clear();
}

void DFS_visit(Graph& g, int i, stack<int>& s);

void DFS(Graph& g, stack<int>& s)
{
	for(int i = g.numNodes()-1; i>=0; i--)
	{
		if (g.isVisited(i) == false)
		{
			DFS_visit(g, i, s);
		}
	}
}
void DFS_visit(Graph& g, int i, stack<int>& s)
{
    g.markVisited(i);
    // cout<<i<<endl;
	FOR(j,0,sz(g[i]))
	{
		if (g.isVisited(g[i][j]) == false)
		{
			DFS_visit(g, g[i][j], s);
		}
	}
	s.push(i);
}
bool checkSatisfiability(VI & v)
{
	sort(v);
	for (int i = 0; i < sz(v); ++i)
	{
		upper_bound(v.begin(), v.end(), abs(v[i]-2*N))
	}
}
void DFS_REV_visit(Graph& g, int i, int& count, VI& v)
{
	g.markVisited(i);
	v.pb(i);
	count++;
	FOR(j,0,sz(g[i]))
	{
		if (g.isVisited(g[i][j]) == false)
		{
			DFS_REV_visit(g, g[i][j], count);
		}
	}
}
int DFS_REV(Graph& g, stack<int>& s, VI& v)
{
	int scc = 0;
	int count=0;
	// vector<int> vc;
	bool b = true;
	while(!s.empty() && b)
	{
		if(g.isVisited(s.top()) == false)
		{
			DFS_REV_visit(g, s.top(), count, v);
			// vc.pb(count);
			b = checkSatisfiability(v);
			count = 0;
			scc++;
		}
		s.pop();
	}
	// sort(vc.begin(), vc.end(), greater<int>());
	// FOR(i,0,sz(vc))
	// 	cout<<vc[i]<<endl;
	// cout<<endl;
	// vc.clear();
	return scc;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int n; cin>>n;
	int N = n;
	n *= 2;
	Graph g(n+1);
	Graph grev(n+1);
	int i,j;
	while(cin>>i>>j)
	{
		int _i, _j;
		_i = -i;
		_j = -j;

		// translation 

		i += N;
		j += N;
		_i += N;
		_j += N;
		// DEBUG(i)
		// DEBUG(j)
		// DEBUG(_i)
		// DEBUG(_j)
		g[_i].pb(j);
		g[_j].pb(i);

		grev[j].pb(_i);
		grev[i].pb(_j);
	}
	stack<int> s;
	DFS(grev, s);
	// while(!s.empty())
	// {
	// 	cout<<s.top()<<endl;
	// 	s.pop();
	// }
	VI v;
	cout<<DFS_REV(g,s,v)<<endl;

	return 0;
}
