//
//  16234(인구이동).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 17..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

bool is_range(int x, int y, int N) {
    return (0<=x&&x<N)&&(0<=y&&y<N);
}
// 합쳐지는 나라 v에 보관
bool bfs(vector<vector<int>> &map, vector<vector<bool>> &is_visit, int x, int y, int N, int L, int R) {
    bool flag = false;
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    q.push(make_pair(x,y));
    is_visit[y][x] = true;
    v.push_back(make_pair(x,y));
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(is_range(nx, ny, N)&&!is_visit[ny][nx]) {
                if(L<=abs(map[cy][cx]-map[ny][nx])&&abs(map[cy][cx]-map[ny][nx])<=R) {
                    is_visit[ny][nx] = true;
                    q.push(make_pair(nx, ny));
                    v.push_back(make_pair(nx, ny));
                }
            }
        }
    }
    if(v.size()<=1) {
        flag = false;
    } else {
        int sum=0;
        for(int i=0;i<v.size();i++) {
            sum+=map[v[i].second][v[i].first];
        }
        for(int i=0;i<v.size();i++) {
            map[v[i].second][v[i].first]=sum/v.size();
        }
        v.clear();
        flag = true;
    }
    return flag;
}

int main(void) {
    int N, L, R;
    cin>>N>>L>>R;
    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<bool>> is_visit(N, vector<bool>(N,false));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>map[i][j];
        }
    }
    
    int count=0;
    while(true) {
        bool flag = false;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(!is_visit[i][j]) {
                    if(bfs(map, is_visit, j, i, N, L, R)) {
                        flag = true;
                    }
                }
            }
        }
        if(flag) {
            count++;
        } else {
            break;
        }
        is_visit.clear();
        is_visit.assign(N, vector<bool>(N,false));
        
    }
    cout<<count<<endl;
    
    return 0;
}


