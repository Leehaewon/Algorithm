//
//  1261(알고스팟).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 16..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0, 0, 1, -1};

bool is_range(int x, int y, int N, int M) {
    return (0<=x&&x<M)&&(0<=y&&y<N);
}

void bfs(vector<vector<int>> &map, vector<vector<int>> &doors, int startX, int startY, int N, int M) {
    deque<pair<int, int>> q;
    q.push_back(make_pair(startX, startY));
    doors[startY][startX] = 0;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop_front();
        
        if((cx == M-1) && (cy == N-1)) {
            break;
        }
        for(int i=0;i<4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(is_range(nx, ny, N, M)) {
                if(doors[ny][nx]==-1) {
                    if(map[ny][nx]==0) {
                        doors[ny][nx] = doors[cy][cx];
                        q.push_front(make_pair(nx,ny));
                    } else {
                        doors[ny][nx] = doors[cy][cx]+1;
                        q.push_back(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}

int main(void) {
    int N, M;
    cin>>M>>N;
    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<int>> doors(N, vector<int>(M,-1));
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        for(int j=0;j<M;j++) {
            map[i][j]=s[j]-'0';
        }
    }
    
    bfs(map, doors, 0, 0, N, M);
    
    cout<<doors[N-1][M-1]<<endl;
    return 0;
}
