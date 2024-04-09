// C++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int escape_maze(vector<vector<int>> &maze, int start_row, int start_col)
{
    int n = maze.size();
    int m = maze[0].size();

    // Kiểm tra hợp lệ của vị trí xuất phát
    if (start_row < 0 || start_row >= n || start_col < 0 || start_col >= m || maze[start_row][start_col] == 1)
    {
        return -1;
    }

    // Khởi tạo mảng visited để theo dõi những ô đã được kiểm tra
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Hàng đợi để duyệt theo chiều rộng (BFS)
    queue<pair<int, int>> q;

    // Thêm vị trí xuất phát vào hàng đợi và đánh dấu đã thăm
    q.push({start_row, start_col});
    visited[start_row][start_col] = true;

    // Số bước di chuyển
    int steps = 0;

    // Các hướng di chuyển (lên, xuống, trái, phải)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int size = q.size();

        // Duyệt qua từng ô trong hàng đợi (cùng bước di chuyển)
        for (int i = 0; i < size; ++i)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == 0 || row == n - 1 || col == 0 || col == m - 1)
            {
                // Nếu đến biên, trả về số bước di chuyển
                return steps;
            }

            // Thử di chuyển qua các ô kề
            for (int k = 0; k < 4; ++k)
            {
                int newRow = row + dx[k];
                int newCol = col + dy[k];

                // Kiểm tra hợp lệ của ô mới
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && maze[newRow][newCol] == 0 && !visited[newRow][newCol])
                {
                    // Thêm ô mới vào hàng đợi và đánh dấu đã thăm
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }

        // Tăng số bước di chuyển sau mỗi bước duyệt
        ++steps;
    }

    // Nếu không tìm thấy đường thoát, trả về -1
    return -1;
}

int main()
{
    int n, m, start_row, start_col;
    cin >> n >> m >> start_row >> start_col;

    // Đọc dữ liệu mê cung từ bàn phím
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }

    // Gọi hàm escape_maze và in kết quả
    int result = escape_maze(maze, start_row - 1, start_col - 1);
    cout << ((result == -1) ? -1 : result + 1) << endl;

    return 0;
}
