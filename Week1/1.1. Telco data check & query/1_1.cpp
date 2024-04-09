// C++
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
using namespace std;

int total_call = 0, check = 1;
unordered_map<string, int> call_num, count_time;

int checkValidPhone(string phone)
{
    if (phone.length() != 10)
        return 0;
    for (int i = 0; i < phone.length(); i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            return 0;
    }
    return 1;
}

int time(string stime, string etime)
{
    int res = 0;
    int a[] = {36000, 3600, 0, 600, 60, 0, 10, 1};
    for (int i = 0; i < stime.length(); i++)
    {
        res += a[i] * (etime[i] - stime[i]);
    }
    return res;
}

void input()
{
    string type, fnum, tnum, date, stime, etime;
    while (true)
    {
        cin >> type;
        if (type == "#")
            break;
        cin >> fnum >> tnum >> date >> stime >> etime;
        if (checkValidPhone(fnum) && checkValidPhone(tnum))
        {
            total_call++;
            call_num[fnum]++;
            count_time[fnum] += time(stime, etime);
        }
        else
        {
            check = 0;
        }
    }
}

void solve()
{
    string type, num;
    while (true)
    {
        cin >> type;
        if (type == "#")
            break;
        if (type == "?check_phone_number")
        {
            if (check == 1)
                cout << "1" << endl;
        }
        if (type == "?number_calls_from")
        {
            cin >> num;
            cout << call_num[num] << endl;
        }
        if (type == "?number_total_calls")
            cout << total_call << endl;
        if (type == "?count_time_calls_from")
        {
            cin >> num;
            cout << count_time[num] << endl;
        }
    }
}
