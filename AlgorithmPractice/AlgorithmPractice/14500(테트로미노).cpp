//
//  14500(테트로미노).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 17..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 5 5
 1 2 3 4 5
 5 4 3 2 1
 2 3 4 5 6
 6 5 4 3 2
 1 2 1 2 1
 */

int answer = 0;
int N;
int M;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

bool is_range(int x, int y) {
    return (0<=x&&x<M)&&(0<=y&&y<N);
}

void checkMaxSum(vector<vector<int>> &map, int x, int y, int bx, int by, int sum, int depth) {
    if(depth == 4) {
        answer = max(answer, sum);
        return;
    }
    
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(is_range(nx, ny)&& !(nx==bx&&ny==by)) {
            checkMaxSum(map, nx, ny,x,y, sum+map[y][x], depth+1);
        }
    }
}


void checkCrossMaxSum(vector<vector<int>> &map, int x, int y) {
    for(int i=0;i<4;i++) {
        int sum=map[y][x];
        for(int j=0;j<3;j++) {
            int index = i+j;
            if(index>=4) index-=4;
            int nx = x+dx[index];
            int ny = y+dy[index];
            
            if(is_range(nx, ny)) {
                sum+=map[ny][nx];
            }
        }
        answer = max(answer, sum);
    }
}

int main(void) {
    cin>>N>>M;
    vector<vector<int>> map(N, vector<int>(M));
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>map[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            checkMaxSum(map, j, i, j, i, 0, 0);
            checkCrossMaxSum(map, j, i);
        }
    }
    cout<<answer<<endl;
    return 0;
}


