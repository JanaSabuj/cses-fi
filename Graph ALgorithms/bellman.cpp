int n;
struct Edge {
	int u, v, wt;
	bool operator<(Edge const& e) {
		return wt < e.wt;
	}
	Edge(int a, int b, int c) {
		u = a;
		v = b;
		wt = c;
	}
};
vector<Edge> veclist;


void bellman_ford() {
	// 1. Propagation phase
	int x;
	for (int i = 0; i < n; ++i) {
		x = -1;
		for (auto e : veclist) {
			int u = e.u;
			int v = e.v;
			int wt = e.wt;

			if (dist[u] == INF) continue;
			if (dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
				dist[v] = max(dist[v], NINF);// lower bound of minima - NINF
				x = v;
			}
		}
	}

	if (x == -1) {
		// no neg cycle
		return;
	}

	//2. Neg cycle resolution phase
	for (int i = 0; i < n - 1; ++i) {
		for (auto e : veclist) {
			int u = e.u;
			int v = e.v;
			int wt = e.wt;

			if (dist[u] == INF) continue;
			// dist[v] = max(dist[v], NINF);
			if (dist[u] + wt < dist[v]) {
				dist[v] = NINF;// v is part of a neg cycle / reachable from neg cycle
			}
		}
	}
}


