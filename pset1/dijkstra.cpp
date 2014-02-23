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

	vector< vector<PII> > g;
public:
	Graph(int n);
	~Graph();
	vector <int> d;
	vector<PII>& operator [] (int i);
	bool isVisited(int n);
	void markVisited(int n);
	void addEdge(int i, int j, int weight);
	int numNodes();
};
Graph::Graph(int n)
{
	Graph::n = n;
	d.resize(n,INT_MAX);
	nodes.resize(n,0);
	g.resize(n);
}
vector<PII>& Graph::operator [] (int i)
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
void Graph::addEdge(int i, int j, int weight)
{
	g[i].pb(mp(j,weight));
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

struct Order
{
    bool operator()(PII const& a, PII const& b) const
    {
        return a.second > b.second;
    }
};

void readGraph(Graph & g)
{
	string line;

	ifstream infile("in.txt"); // dijkstraData.txt
	int i,j,w;
	char c;
	while(getline(infile, line))
	{

		istringstream iss(line);
		iss>>i;
		while(iss>>j>>c>>w)
		{
			g.addEdge(i,j,w);
		}
	}

}

#define MAX_NODE 201
int main()
{
    freopen("out.txt","w",stdout);
	Graph g(MAX_NODE);
	int s=1; // cin>>s;
	readGraph(g);
	priority_queue<PII, VII, Order > Q;
	Q.push(mp(s,0));
	g.d[s] = 0;
	while(!Q.empty())
	{
		PII n = Q.top();
		int i =  n.first;
		int wCurr = n.second;
		for(int j=0, size=sz(g[i]); j < size; j++)z
		{
			int v = g[i][j].first;
			if(g.isVisited(v) == false)
			{
				int wEdge = g[i][j].second;
				if (wCurr + wEdge < g.d[v])
				{
					g.d[v] = wCurr + wEdge;
					PII temp = mp(v,g.d[v]);
					Q.push(temp);
				}

			}
		} 
		g.markVisited(i);
		Q.pop();
	}
    FOR(i,1,MAX_NODE)
        cout<<g.d[i]<<endl;
	return 0;
}
