// C++
#include <bits/stdc++.h>
using namespace std;

const int max_N = 1e6;
const int inf = 1e9;

int n, a[max_N];
int q;
int st[4 * max_N];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
}

long long get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return inf;

    if (l >= u && r <= v)
        return st[id];

    int mid = (l + r) >> 1;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return min(get1, get2);
}

long long solve()
{
    cin >> q;
    int x, y;
    long long sum = 0;
    while (q--)
    {
        cin >> x >> y;
        long long u = get(1, 1, n, x + 1, y + 1);
        sum += u;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << solve();
}
