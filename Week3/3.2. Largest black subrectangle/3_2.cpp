// C++
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && heights[i] < heights[s.top()])
        {
            int height = heights[s.top()];
            s.pop();
            int width = (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int height = heights[s.top()];
        s.pop();
        int width = (s.empty() ? n : n - s.top() - 1);
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // Tính diện tích lớn nhất của hình chữ nhật
    int maxRectangle = 0;
    vector<int> histogram(m, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0)
            {
                histogram[j] = 0;
            }
            else
            {
                histogram[j] += matrix[i][j];
            }
        }
        maxRectangle = max(maxRectangle, maxRectangleArea(histogram));
    }

    cout << maxRectangle << endl;

    return 0;
}
