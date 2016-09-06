#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define max 100

double betweeness[max][max] = {0};
vi adjList[max],A,B;
int n,i,j,a,b;
double credit[max]= {0};

void firstSecondThirdStep(int u)
{
    int  lvl[max]= {0},visit[max] = {0};
    vi child[max];
    queue<int> q;
    cout << "Modified bfs:\n";
    q.push(u);
    lvl[u] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        visit[v] = 1;
        cout << v << " ";
        for(j=0; j<adjList[v].size(); j++)
        {
            if((lvl[adjList[v][j]] == 0 || lvl[adjList[v][j]] > lvl[v]) && visit[adjList[v][j]] == 0)
            {
                q.push(adjList[v][j]);
                child[v].push_back(adjList[v][j]);
                lvl[adjList[v][j]] = lvl[v] + 1;
            }
        }
    }

    cout << "\n\nchild: \n";
    for(j=1; j<=n; j++)
    {
        cout << j << " -> ";
        for(int k = 0; k<child[j].size(); k++)
            cout << child[j][k] << " ";
        cout << endl;
    }

    vi parent[max];
    for(j=1; j<= n; j++)
        for(int k = 0; k < child[j].size(); k++)
            parent[child[j][k]].push_back(j);

    cout << "\nparent: \n";
    for(j=1; j<=n; j++)
    {
        cout << j << " -> ";
        for(int k = 0; k<parent[j].size(); k++)
            cout << parent[j][k] << " ";
        cout << endl;
    }
    cout << endl;

    // 02-05-2015
    cout << "Leaf:\n";
    queue<int> temp2;
    double temp[max]= {0},visitFrCredit[max]= {0};
    for(i=1; i<=n; i++)
        if(child[i].size() == 0)
        {
            cout << i << " ";
            visitFrCredit[i] = 1;
            temp[i] = 1;
            temp2.push(i);
        }
    cout << endl;
    int temp3[max];
    for(i=1; i<=n; i++)
        temp3[i] = child[i].size();


    while(!temp2.empty())
    {
        int m = temp2.front();
        temp2.pop();

        for(i=0; i<parent[m].size(); i++)
        {
            temp[parent[m][i]] += temp[m]/parent[m].size();
            temp3[parent[m][i]]--;
            if(temp3[parent[m][i]]==0 && child[parent[m][i]].size() !=0)
                temp[parent[m][i]]++;
            if(visitFrCredit[parent[m][i]] == 0)
            {
                temp2.push(parent[m][i]);
                visitFrCredit[parent[m][i]] = 1;
            }
        }
    }



    cout << "Credit: \n";
    for(i=1; i<=n; i++)
        cout << temp[i] << " " ;
    cout << endl;

    cout << "Not Final : \n";
    temp[u] = 0;
    for(i=1; i<=n; i++)
    {
        if(temp[i] == 0)
            continue;
        for(j = 0; j<parent[i].size(); j++)
        {
            betweeness[i][parent[i][j]] += temp[i]/parent[i].size();
            cout << "("<< i << "," << parent[i][j] << ") -> "<< betweeness[i][parent[i][j]] << endl;
        }
    }
    cout << endl << endl;
}



int main()
{
    freopen("girvanNewman.txt","r",stdin);
    cin >> n;
    while(scanf("%d %d",&a,&b) && (a || b))
    {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        A.push_back(a);
        B.push_back(b);
    }

    for(i=1; i<=n; i++)
    {
        cout << i << " -> ";
        for(j=0; j<adjList[i].size(); j++)
            cout << adjList[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for(int k=1; k<=n; k++)
    {
        cout << "Root: " << k << endl;
        firstSecondThirdStep(k);
    }

    cout << "Final:\n";
    for(i=0; i<A.size(); i++)
        cout <<  "(" << A[i] << "," << B[i] << ") -> " << betweeness[A[i]][B[i]] << endl;

    return 0;
}
