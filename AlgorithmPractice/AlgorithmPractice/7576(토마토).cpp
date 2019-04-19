//
//  7576(토마토).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 19..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool is_range(int x, int y, int N, int M) {
    return (0<=x&&x<M)&&(0<=y&&y<N);
}

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);
    vector<vector<int>> map (N, vector<int> (M, 0));
    vector<vector<bool>> is_visit(N, vector<bool> (M, false));
    queue<pair<int, int> > q;
    vector<pair<int, int> > ripeningTomato;
    int ripenTomato = 0;
    int notTomato = 0;
    int answer = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == -1)
                notTomato++;
            else if(map[i][j] == 1) {
                ripenTomato++;
                q.push(make_pair(j, i));
                is_visit[i][j] = true;
            }
        }
    }
    if(notTomato + ripenTomato == N * M) {
        answer = 0;
    } else {
        while(true) {
            while(!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    
                    if(is_range(nx, ny, N, M)&&!is_visit[ny][nx]&&map[ny][nx]==0) {
                        is_visit[ny][nx] = true;
                        ripenTomato++;
                        ripeningTomato.push_back(make_pair(nx, ny));
                    }
                }
            }
            
            if(ripeningTomato.size() == 0) {
                break;
            }
            
            for(int i = 0; i < ripeningTomato.size();i++) {
                q.push(make_pair(ripeningTomato[i].first, ripeningTomato[i].second));
            }
            ripeningTomato.clear();
            answer++;
        }
        if(notTomato + ripenTomato != N * M) {
            answer = -1;
        }
    }
    cout<<answer<<endl;
    return 0;
}
