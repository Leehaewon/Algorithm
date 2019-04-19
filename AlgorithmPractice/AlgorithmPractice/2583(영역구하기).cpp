//
//  2583(영역구하기).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 19..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool is_range(int x, int y, int N, int M) {
    return (0<=x&&x<M)&&(0<=y&&y<N);
}

int bfs(vector<vector<bool>> &map, vector<vector<bool>> &is_visit, int x, int y, int N, int M) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    int count = 1;
    is_visit[y][x] = true;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(is_range(nx, ny, N, M)&&!is_visit[ny][nx]&&map[ny][nx]) {
                q.push(make_pair(nx, ny));
                is_visit[ny][nx] = true;
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int M, N, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<vector<bool>> map (N, vector<bool> (M, true));
    vector<vector<bool>> is_visit (N, vector<bool> (M, false));
    vector<int> areaSize;
    int answer = 0;
    for(int k = 0; k < K; k++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = y1; i < y2 ; i++) {
            for(int j = x1 ; j < x2; j++) {
                map[i][j] = false;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j]&&!is_visit[i][j]) {
                int area = bfs(map, is_visit, j, i, N, M);
                areaSize.push_back(area);
                answer++;
            }
        }
    }
    sort(areaSize.begin(), areaSize.end());
    cout<<answer<<endl;
    for(int i = 0; i < areaSize.size(); i++) {
        cout<<areaSize[i]<<" ";
    }
    cout<<endl;
    return 0;
}
