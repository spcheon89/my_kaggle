#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define MAX_VALUE 200000

bool check[MAX_VALUE];
int dist[MAX_VALUE];

int main(){
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    check[n] = true;
    dist[n] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node-1 >= 0){
            if(check[node-1] == false){
                check[node-1] = true;
                dist[node-1] = dist[node] + 1;
                q.push(node-1);
            }
        }

        if(node+1 < MAX_VALUE){
            if(check[node+1] == false){
                check[node+1] = true;
                dist[node+1] = dist[node] + 1;
                q.push(node+1);
            }
        }

        if(node*2 < MAX_VALUE){
            if(check[node*2] == false){
                check[node*2] = true;
                dist[node*2] = dist[node] + 1;
                q.push(node*2);
            }
        }
    }

    cout << dist[k];
    return 0;
}
