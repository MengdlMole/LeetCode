#include <iostream>
#include <vector>
#include <queue>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::vector<std::vector<int>> dis(m, std::vector<int>(n, -1));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 0) {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }

    int res = 0;
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] != -1 && dis[ni][nj] == -1) {
                dis[ni][nj] = dis[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && dis[i][j] != -1) {
                res += dis[i][j];
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}