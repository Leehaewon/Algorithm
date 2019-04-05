//
//  SWEA1953(탈주범검거).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 5..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

const bool mapDir[8][4] = {
    {false, false, false, false},
    {true, true, true, true},
    {true, false, true, false},
    {false, true, false, true},
    {true, true, false, false},
    {false, true, true, false},
    {false, false, true, true},
    {true, false, false, true}
};

struct Node {
    int x;
    int y;
    int arrivaltime;
};

bool is_range(int x, int y, int M, int N) {
    return (0<=x&&x<M)&&(0<=y&&y<N);
}


int main(void) {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int N, M, R, C, L;
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        vector<vector<int>> map (N, vector<int> (M, 0));
        vector<vector<bool>> is_visit (N, vector<bool> (M, false));
        queue<Node> q;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        int answer = 1;
        int now = 1;
        q.push({C, R, now});
        is_visit[R][C] = true;

        while(true) {
            if(now == L) {
                break;
            }
            
            while(q.front().arrivaltime == now) {
                int cx = q.front().x;
                int cy = q.front().y;
                int cnow = q.front().arrivaltime;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    if(mapDir[map[cy][cx]][i]) {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];
                        
                        if(is_range(nx, ny, M, N)&&!is_visit[ny][nx]&&map[ny][nx]!=0) {
                            for(int j = 0; j < 4; j++) {
                                if(mapDir[map[ny][nx]][j]&&(dx[i] + dx[j]) == 0 && (dy[i] + dy[j]) == 0) {
                                    is_visit[ny][nx] = true;
                                    q.push({nx, ny, cnow+1});
                                    answer++;
                                }
                            }
                        }
                    }
                }
            }
            now++;
        }
        printf("#%d %d\n", t, answer);
    }
    return 0;
}
