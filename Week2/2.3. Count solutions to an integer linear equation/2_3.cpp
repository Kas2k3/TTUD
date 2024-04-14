#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6;

int n, M;
vector<int> a(N + 1);
vector<int> x(N + 1);
int nghiem = 0;

void input()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void solve(int k, int sum)
{
    if (sum == M && k == n + 1)
    { // Nếu tổng bằng M và đã duyệt qua tất cả các biến X
        nghiem++;
        return;
    }
    if (k > n || sum > M)
        return; // Nếu đã vượt quá số biến hoặc tổng vượt quá M, kết thúc

    for (int v = 1; v <= M; v++)
    {
        x[k] = v;                     // Thử giá trị của X[k]
        solve(k + 1, sum + a[k] * v); // Duyệt tiếp cho biến X[k+1]
    }
}

int main()
{
    input();
    solve(1, 0); // Bắt đầu từ biến X[1], tổng sum = 0
    cout << nghiem;
    return 0;
}
