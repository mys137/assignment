#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

class treee{
    int levels,n;
    unordered_map<int,vector<int>> adj;

    public:
    int root;
    treee(){
        cout<<"enter max level of tree\n";
        cin>>levels;
        cout<<"Enter the root value of tree\n";
        cin>>root;
        cout<<"enter the maximum children in the tree\n";
        cin>>n;
        queue<int> q;
        q.push({root});

        while(!q.empty()){
            int y = q.front();
            q.pop();
            int nn;
            cout<<"Enter the number of children\n";
            cin>>nn;

            for(int i=0;i<nn;i++){
                int x;
                cin>>x;
                q.push(x);
                adj[y].push_back(x);
            }

        }

        cout<<"The tree is\n";
        display();
    }
    void display(){
        queue<int> q;
        q.push(root);
        q.push(-1);

        int l = 1;
        cout<<"level "<<l<<"        ";
        while(!q.empty()){
            int y = q.front();
            q.pop();
            if(y==-1){
                cout<<endl;
                l++;
                cout<<"level "<< l <<"        ";
                continue;
            }
            cout<<y<<" ";

            if(adj[y].size()==0){
                continue;
            }
            for(auto it:adj[y]){
                q.push(it);
            } 
            q.push(-1);
        }


    }

    void depth_first(int, int, bool&);
    void breadth_first(int, queue<int>&, bool&);

};

void treee::breadth_first(int x,queue<int>& q,bool& flag){
    if(q.empty() || flag){
        return;
    }
    int v = q.front();
    q.pop();
    if(v==x){
        flag==true;
        cout<<"lement found\n";
        return;
    }
    for(auto it: adj[v]){
        q.push(it);
    }
    breadth_first(x,q,flag);
}

void treee::depth_first(int n,int x,bool& flag){
    if(n==x){
        cout<<"Element found\n";
        flag=true;
    }else{
        for(auto it: adj[n]){
            if(!flag){
                depth_first(it,x,flag);
            }
        }
    }

}

int main(){
    treee obj;
    int to_search, choice;
    cout<<"\n ----------------------------------------- ";
    cout<<"\n Enter the element to search for : ";
    cin>>to_search;
    cout<<"\n Choose from the following --> ";
    cout<<"\n\t 1. Depth First Search (DFS) \n\t 2. Breadth First Search(BFS) \n\t 3. Exit";
    while(1)
    {
        cout<<"\n Your Choice = ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                bool flag = false;
                obj.depth_first(obj.root, to_search, flag);
                if(!flag)
                    cout<<"\n\t Element not present!";
                cout<<"\n ----------------------------------------- \n";
                break;
            }
        case 2:
            {
                queue<int> q;
                q.push(obj.root);
                bool flag = false;
                obj.breadth_first(to_search, q, flag);
                if(!flag)
                    cout<<"\n\t Element not present!";
                cout<<"\n ----------------------------------------- \n";
                break;
            }
        case 3:
            return 0;
        }
    }
   return 0;
}