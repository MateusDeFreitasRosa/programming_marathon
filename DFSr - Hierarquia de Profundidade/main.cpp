#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

bool graph[MAXN][MAXN];
int color[MAXN];
int dfsNum[MAXN];
int num;
int n;
int blanc;
bool existBreak;

void printBlanc(int n) {
    for (int i=0; i<n; i++) {
        cout << " ";
    }
}

void dfs(int u, int p) {
    // 0 -> White. Não foi visitado.
    // 1 -> Gray. Está sendo verificado seus visinhos.
    // 2 -> Black. Já foi visitad.
    if (dfsNum[u] == 0) {
        color[u] = 1;
        dfsNum[u] =  ++num;
        for(int v=0; v<n; v++) {
            if (graph[u][v] && v != p) {
                printBlanc(blanc);
                if (color[v] == 0) {
                    cout << u << "-" << v << " pathR(G," << v << ")" << endl;
                }
                else {
                    cout << u << "-" << v << endl;
                }
                if (graph[v][u]) {
                    printBlanc(blanc+2);
                    cout << v << "-" << u << endl;
                }

                existBreak = false;
                blanc +=2;
                dfs(v,u);
                blanc -=2;
            }
        }
        color[u] = 2;
    }

}

int main()
{
    int casos, v,e;
    cin >> casos;
    int x1,x2;
    for (int c=0; c<casos; c++) {
        memset(graph,0, sizeof(graph));
        memset(color, 0, sizeof(color));
        memset(dfsNum, 0, sizeof(dfsNum));
        num = 0;
        blanc = 2;
        cin >> v >> e;
        n = v;
        for (int vertices=0; vertices<e; vertices++) {
            cin >> x1 >> x2;
            graph[x1][x2] = 1;
        }
        cout << "Caso " << c+1 << ":" << endl;

        existBreak = false;
        for(int i=0; i<v; i++) {
            if (dfsNum[i] == 0) {
                dfs(i, -1);
                if (existBreak == false) {
                    cout << endl;
                    existBreak = true;
                }
            }
        }

    }
    return 0;
}
