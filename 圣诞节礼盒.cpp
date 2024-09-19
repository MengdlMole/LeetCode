#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    // 输入数据
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> boxs(N, std::vector<int>(3));
    for(int i = 0; i < N; i++){
        std::cin >> boxs[i][0] >> boxs[i][1] >> boxs[i][2];
    }

    // 字典排序
    std::sort(boxs.begin(), boxs.end());

    // 解决问题
    // dp[i] = max{dp[j] + h[i]}
    std::vector<int> dp(N, 0);
    dp[0] = boxs[0][2];
    int res = 0;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(boxs[i][0] > boxs[j][0] && boxs[i][1] > boxs[j][1] && boxs[i][2] > boxs[j][2]){
                dp[i] = std::max(dp[i], dp[j] + boxs[i][2]);
            }
        }
        res = std::max(res, dp[i]);
        // std::cout << res << std::endl;
    }

    std::cout << res;
}