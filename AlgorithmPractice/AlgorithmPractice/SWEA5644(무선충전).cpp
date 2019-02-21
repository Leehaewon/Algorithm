//
//  SWEA5644(무선충전).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 20..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

/*
1
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70

1
5 2
2 2 4 4 2
4 4 2 2 0
1 1 3 40
10 10 3 40
 */
const int dx[5] = {0,0,1,0,-1};
const int dy[5] = {0,-1,0,1,0};

using namespace std;

bool is_range(int x, int y) {
    return (0<=x&&x<10)&&(0<=y&&y<10);
}
void saveRangeBC(vector<vector<vector<pair<int,int> >>> &map, int x, int y,int BCno, int C, int P) {
    map[y][x].push_back(make_pair(P,BCno));
    for(int k=0;k<=C;k++) {
        for(int c=1;c+k<=C;c++) {
            if(is_range(x+c, y-k)) map[y-k][x+c].push_back(make_pair(P,BCno));
            if(is_range(x-c, y+k)) map[y+k][x-c].push_back(make_pair(P,BCno));
            if(is_range(x+k, y+c)) map[y+c][x+k].push_back(make_pair(P,BCno));
            if(is_range(x-k, y-c)) map[y-c][x-k].push_back(make_pair(P,BCno));
        }
    }
}

int main(void) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int M, A;
        cin >> M >> A;
        vector<vector<pair<int, int> >> user(2);
        vector<vector<vector<pair<int, int> >>> map(10, vector<vector<pair<int, int> >>(10));
        user[0].push_back(make_pair(0, 0));
        user[1].push_back(make_pair(9, 9));
        int cx = 0;
        int cy = 0;
        for (int i = 0; i<M; i++) {
            int input;
            cin >> input;
            cx += dx[input];
            cy += dy[input];
            user[0].push_back(make_pair(cx, cy));
        }
        cx = 9;
        cy = 9;
        for (int i = 0; i<M; i++) {
            int input;
            cin >> input;
            cx += dx[input];
            cy += dy[input];
            user[1].push_back(make_pair(cx, cy));
        }
        for (int i = 0; i<A; i++) {
            int X, Y, C, P;
            cin >> X >> Y >> C >> P;
            saveRangeBC(map, X - 1, Y - 1, i, C, P);
        }
        int sum = 0;
        
        for (int i = 0; i<=M; i++) {
            int userX1 = user[0][i].first;
            int userY1 = user[0][i].second;
            int userX2 = user[1][i].first;
            int userY2 = user[1][i].second;
            sort(map[userY1][userX1].begin(), map[userY1][userX1].end(), greater<pair<int, int> >());
            sort(map[userY2][userX2].begin(), map[userY2][userX2].end(), greater<pair<int, int> >());
            
            if (map[userY1][userX1].size() == 0 && map[userY2][userX2].size() == 0) {
            }
            else if (map[userY1][userX1].size() == 0) {
                sum += map[userY2][userX2][0].first;
            }
            else if (map[userY2][userX2].size() == 0) {
                sum += map[userY1][userX1][0].first;
            }
            else {
                
                sum += map[userY1][userX1][0].first;
                sum += map[userY2][userX2][0].first;
                
                if (map[userY1][userX1][0].second == map[userY2][userX2][0].second) {
                    
                    sum -= map[userY1][userX1][0].first;
                    
                    if (map[userY1][userX1].size() >= 2 && map[userY2][userX2].size() >= 2) {
                        if (map[userY1][userX1][1].first > map[userY2][userX2][1].first) {
                            sum += map[userY1][userX1][1].first;
                        }
                        else {
                            sum += map[userY2][userX2][1].first;
                        }
                        
                    }
                    else {
                        if (map[userY1][userX1].size() >= 2) {
                            sum += map[userY1][userX1][1].first;
                        }
                        else if(map[userY2][userX2].size() >= 2){
                            sum += map[userY2][userX2][1].first;
                        }
                    }
                    
                }
            }
            
            
        }
        cout <<"#"<<T <<" "<< sum << endl;
        
    }
    return 0;
}
