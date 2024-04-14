
#include <bits/stdc++.h>
using namespace std;
int a[31];                                             // mang a luu cach dk hp, giao vien "v" dk day hp "k" => a[k] = v.
int b[11][31] = {0};                                   // mang b luu nhung hp ma giao vien co the day, giao vien "v" co the day hoc phan "k" thi b[v][k] = 1; nguoc lai b[v][k] = 0.
int c[31][31] = {0};                                   // mang c luu cac cap hp xung dot, hp h xung dot hp k thi c[h][k] = c[k][h] = 1, nguoc lai = 0.
int n, m;                                              // dung de luu lan luot so hp va so giao vien
int tMaxLoad = 0, load[11] = {0}, maxLoad = 999999999; // dung cho quy hoach dong, tMaxLoad la max load tam thoi, load[11] dung de luu load hien tai cua giao vien, maxLoad luu gia tri nho nhat hien tai cua max load

// dung de kiem tra cach dk hp co hop le khong, neu hai hp i, k cung dc dk boi giao vien v nhung i, k xung dot tri tra ve false, neu khong tra ve true
bool check(int k, int v)
{
    for (int i = k + 1; i <= n; i++)
    {
        if (a[i] == v && c[k][i] == 1)
        {
            return false;
        }
    }
    return true;
}

// thuat toan nhanh can de xay dung cach dk hp, xay dung tu hp 30 -> hp 1
void Try(int k)
{
    // doan nay dung de lay v trong tap cac UCV thoa man
    for (int v = 1; v <= m; v++)
    {
        if (b[v][k] == 1 && check(k, v))
        {
            // doan nay de cap nhat cach dk hien tai va cac bien trung gian
            a[k] = v;
            load[v]++;
            int p = 0;
            if (load[v] > tMaxLoad)
            {
                tMaxLoad++;
                p = 1;
            }

            // doan nay la doan quy lui
            if (k == 1)
            {
                if (tMaxLoad < maxLoad)
                {
                    maxLoad = tMaxLoad;
                }
            }
            else if (tMaxLoad < maxLoad)
            {
                Try(k - 1);
            }

            // doan nay cap nhat lai bien trung gian
            load[v]--;
            if (p == 1)
            {
                tMaxLoad--;
            }
        }
    }
}

int main()
{
    // nhap m, n
    cin >> m >> n;
    int x, y, z;

    // nhap ma tran b
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        while (x > 0)
        {
            cin >> y;
            b[i][y] = 1;
            x--;
        }
    }

    // nhap ma tran c
    cin >> z;
    while (z > 0)
    {
        cin >> x >> y;
        c[x][y] = 1;
        c[y][x] = 1;
        z--;
    }

    // goi quay lui, cho dk tu hp n ve hp 1.
    Try(n);
    cout << maxLoad;

    return 0;
}
