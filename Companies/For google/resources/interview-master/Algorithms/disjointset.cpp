int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);
	if (parent[xroot] > parent[yroot]) {
		parent[yroot] += parent[xroot];
		parent[xroot] = yroot;
	}
	else {
		parent[xroot] += parent[yroot];
		parent[yroot] = xroot;
	}
}