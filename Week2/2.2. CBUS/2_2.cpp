// C++
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 23;

int n, k; // n la so diem don, diem tra, k la tai cua xe bus
int c[MAXN][MAXN];
int x[MAXN];
bool visted[MAXN] = {false};
int sum = 0, load = 0;
int res = 1e9;
int c_min = 1e9;

void input()
{
    cin >> n >> k;
    int i, j;

    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (i != j)
            {
                c_min = min(c_min, c[i][j]);
            }
        }
    }
    x[0] = 0;
}

bool check(int i)
{
    if (visted[i])
        return false;
    if (i <= n && load == k)
        return false;
    if (i > n && !visted[i - n])
        return false;

    return true;
}

void Try(int t)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (check(i))
        {
            x[t] = i;
            // cap nhat bien trung gian visted, sum, load
            sum += c[x[t - 1]][i];
            visted[i] = true;

            if (i <= n)
            {
                load++;
            }
            else
            {
                load--;
            }
            //--------------------------------------------

            if (t == 2 * n)
            {
                sum += c[x[2 * n]][0];
                res = min(res, sum);
                sum -= c[x[2 * n]][0];
            }
            else if (t < 2 * n && sum + (2 * n - t) * c_min < res)
            { // su dung can duoi la res, neu sum >= res thi khong duyet nua
                Try(t + 1);
            }

            // tra lai gia tri bien trung gian visted, sum, load
            if (i <= n)
            {
                load--;
            }
            else
            {
                load++;
            }

            visted[i] = false;
            sum -= c[x[t - 1]][i];
            //--------------------------------------------
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();

    Try(1);

    cout << res;

    return 0;
}
