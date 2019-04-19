//
//  16236(아기상어).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 11..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

struct Fish {
    int x;
    int y;
    int t; // time
};

bool is_range(int x, int y, int N) {
    return (0<=x&&x<N)&&(0<=y&&y<N);
}

bool myCompare(Fish &f1, Fish &f2) {
    if(f1.t < f2.t) {
        return true;
    } else if(f1.t == f2.t) {
        if(f1.y < f2.y) {
            return true;
        } else if(f1.y == f2.y) {
            if(f1.x < f2.x) {
                return true;
            } else
                return false;
        } else
            return false;
    } else {
        return false;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    int fishX = -1;
    int fishY = -1;
    int fishSize = 2;
    int fishEatCount = 0;
    int fishTotalcount = 0;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9) {
                fishX = j;
                fishY = i;
                map[i][j] = 0;
            } else if(map[i][j] != 0) {
                fishTotalcount++;
            }
        }
    }
    vector<vector<bool>> is_visit(N, vector<bool>(N, false));
    vector<Fish> possibleToEatFish;
    queue<Fish> q; // x, y
    
    int time = 0;
    
    while(fishTotalcount>=0) {
        if(fishTotalcount == 0) {
            break;
        }
        
        q.push({fishX, fishY, time});
        is_visit[fishY][fishX] = true;
        
        while(!q.empty()) {
            int cx = q.front().x;
            int cy = q.front().y;
            int ct = q.front().t;
            q.pop();
            
            if(map[cy][cx] != 0 && map[cy][cx] < fishSize) {
                possibleToEatFish.push_back({cx, cy, ct});
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if(is_range(nx, ny, N)&&!is_visit[ny][nx]&&map[ny][nx]<=fishSize) {
                    is_visit[ny][nx] = true;
                    q.push({nx, ny, ct+1});
                }
            }
        }
        
        if(possibleToEatFish.size() == 0) {
            is_visit.clear();
            is_visit.assign(N, vector<bool>(N, false));
            break;
        }
        
        if(possibleToEatFish.size() > 0) {
            sort(possibleToEatFish.begin(), possibleToEatFish.end(), myCompare);
            fishX = possibleToEatFish.front().x;
            fishY = possibleToEatFish.front().y;
            time = possibleToEatFish.front().t;
            map[fishY][fishX] = 0;
            fishEatCount++;
            fishTotalcount--;
            
            if(fishSize == fishEatCount) {
                fishSize++;
                fishEatCount = 0;
            }
            
            possibleToEatFish.clear();
            is_visit.clear();
            is_visit.assign(N, vector<bool> (N, false));
        }
    }
    cout<<time<<endl;
    return 0;
}
