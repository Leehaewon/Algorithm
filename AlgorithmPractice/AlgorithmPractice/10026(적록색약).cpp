//
//  10026(적록색약).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 9..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

bool is_range(int x, int y, int N) {
    return (0<=x&&x<N)&&(0<=y&&y<N);
}
void bfs(vector<vector<char>> &map, vector<vector<bool>> &is_visit, int x, int y, int N) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    is_visit[y][x] = true;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(is_range(nx, ny, N)&&!is_visit[ny][nx]&&map[cy][cx]==map[ny][nx]) {
                is_visit[ny][nx] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

void bfsRG(vector<vector<char>> &map, vector<vector<bool>> &is_visit, int x, int y, int N) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    is_visit[y][x] = true;
    if(map[y][x]=='G') map[y][x]='R';
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(is_range(nx, ny, N)&&!is_visit[ny][nx]) {
                if(map[cy][cx]==map[ny][nx]) {
                    is_visit[ny][nx] = true;
                    q.push(make_pair(nx,ny));
                } else if(map[cy][cx]=='R'&&map[ny][nx]=='G') {
                    is_visit[ny][nx] = true;
                    q.push(make_pair(nx,ny));
                    map[ny][nx] = 'R';
                }
            }
        }
    }
}
int main(void) {
    int N;
    cin>>N;
    vector<vector<char>> map(N, vector<char>(N));
    vector<vector<bool>> is_visit(N, vector<bool>(N, false));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>map[i][j];
        }
    }
    int answer = 0;
    int answerRG = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!is_visit[i][j]) {
                bfs(map, is_visit, j, i, N);
                answer++;
            }
        }
    }
    is_visit.clear();
    is_visit.assign(N, vector<bool>(N, false));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!is_visit[i][j]) {
                bfsRG(map, is_visit, j, i, N);
                answerRG++;
            }
        }
    }
    cout<<answer<<" "<<answerRG<<endl;
    return 0;
}
