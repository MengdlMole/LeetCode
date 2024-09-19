#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    private:
        int N, M;
        std::vector<std::vector<int>> works;
        std::vector<bool> isWorking;
        int result = 0;
        int track = 0;
    public:
        Solution(int N, int M, std::vector<std::vector<int>> input):N(N), M(M), works(input){
            isWorking = std::vector<bool>(N, false);
        }
    private:
        void backtrack(){
            for(auto work : works){
                if(canSubmit(work)){
                    statusForward(work);
                    track += work[2];
                    backtrack();
                    track -= work[2];
                    statusBack(work);
                }
                else{
                    result = std::max(result, track);
                }
            }
        }
        bool canSubmit(std::vector<int> work){
            if(work[3] == 1) return false;
            for(int i = work[0]-1; i < work[1]; i++){
                if(isWorking[i]) return false;
            }
            return true;
        }
        void statusForward(std::vector<int> work){
            work[3] = 1;
            for(int i = work[0]-1; i < work[1]; i++){
                isWorking[i] = true;
            }
        }
        void statusBack(std::vector<int> work){
            work[3] = 0;
            for(int i = work[0]-1; i < work[1]; i++){
                isWorking[i] = false;
            }
        }
    public:
        int start(){
            backtrack();
            return result;
        }
};

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> works(M, std::vector<int>(4));
    for(int i = 0; i < M; i++){
        std::cin >> works[i][0] >> works[i][1] >> works[i][2];
        works[i][3] = 0;
    }
    
    Solution mySolution(N, M, works);
    int res = mySolution.start();
    std::cout << res;
    
}