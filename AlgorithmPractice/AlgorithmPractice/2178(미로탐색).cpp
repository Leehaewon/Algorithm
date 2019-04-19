//
//  2178(미로탐색).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 19..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool is_range(int x, int y, int N, int M) {
    return (0<=x&&x<M)&&(0<=y&&y<N);
}

void bfs(vector<vector<int>> &map, vector<vector<int>> &d, int N, int M) {
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    d[0][0] = 1;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(cx == M-1 && cy == N-1) {
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(is_range(nx, ny, N, M)&&map[ny][nx]==1) {
                if(d[ny][nx] == -1) {
                    d[ny][nx] = d[cy][cx] + 1;
                    q.push(make_pair(nx, ny));
                } else {
                    d[ny][nx] = min(d[cy][cx] + 1, d[ny][nx]); // 이 부분이 포인트!
                }
            }
        }
    }
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> map (N, vector<int> (M, 0));
    vector<vector<int>> d (N, vector<int> (M, -1));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    bfs(map, d, N, M);
    printf("%d\n", d[N-1][M-1]);
    return 0;
}
