#include <bits/stdc++.h>

using namespace std;

struct DisjointSet{
    int sets;
    int* parent;
    int* members;
    
    void init(int n){ // O(v)
        sets = n;
        parent = new int[n];
        members = new int[n];
        for(int i = 0; i < n; i++)
            parent[i] = i, members[i] = 1;
    }
    
    int find(int a){ // O(1)
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
    
    int setsize(int a){ // O(1)
        return members[find(a)];
    }
    
    bool joined(int a, int b){ // O(1)
        return find(a) == find(b);
    }
    
    void join(int a, int b){ // O(1)
        if(joined(a, b)) return;
        members[find(b)] += members[find(a)];
        parent[find(a)] = find(b);
        sets--;
    }
};

#define MAXN 105

vector < pair < int, pair <int, int> > > aristas; 
vector <int> usadas;
int answer, answer2;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		aristas.clear();
		usadas.clear();
		answer = 0;
		answer2 = (1 << 30);
		for(int i = 0; i < M; i++){
			pair <int, int> a;
			int b;
			cin >> a.first >> a.second >> b;
			a.first--;
			a.second--;
			aristas.push_back(make_pair(b, a));
		}
		sort(aristas.begin(), aristas.end());
		DisjointSet grafo;
		grafo.init(N);
		for(int i = 0; i < M; i++){
			if(!grafo.joined(aristas[i].second.first, aristas[i].second.second)){
				answer += aristas[i].first;
				grafo.join(aristas[i].second.first, aristas[i].second.second);
				usadas.push_back(i);
			}
		}
		for(int j = 0; j < usadas.size(); j++){
			int costo = 0;
			DisjointSet G;
			G.init(N);
			for(int i = 0; i < M; i++){
				if(i == usadas[j])
					continue;
				if(!G.joined(aristas[i].second.first, aristas[i].second.second)){
					costo += aristas[i].first;
					G.join(aristas[i].second.first, aristas[i].second.second);
				}
			}
			if(G.sets == 1)
			answer2 = min(costo, answer2);
		}
		cout << answer << " " << answer2 << endl;
	}
	return 0;
}