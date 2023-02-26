#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define MAX 1001

using namespace std;

vector<int> v[MAX];
bool visited[MAX];
int n, m, s, a, b;

void init() {
  	for (int i = 1; i <= n; i++)
    	visited[i] = false;

  	return;
}

void dfs(int s) {
  	stack<int> st;

	st.push(s);
	while (true) {
		if (st.empty()) break;
		int now = st.top();
		st.pop();
		if (visited[now]) continue;
		visited[now] = true;
		cout << now << " ";
		for (int i = v[now].size() - 1; i >= 0; i--)
			st.push(v[now].at(i));
	}

	return;
}

void bfs(int s) {
	queue<int> q;

	q.push(s);
	while (true) {
		if (q.empty()) break;
		int now = q.front();
		q.pop();
		if (visited[now]) continue;
		visited[now] = true;
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++)
			q.push(v[now].at(i));
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> s;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	init();
	dfs(s);

	cout << "\n";

	init();
	bfs(s);

  	return 0;
}