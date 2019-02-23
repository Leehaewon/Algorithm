//
//  SWEA2382(미생물격리).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 23..
//  Copyright © 2019년 이해원. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, -1, 1, 0, 0};

struct Ground {
    vector<pair<int, int>> organism; //amount, num
    bool flag=true;
};

struct Organism {
    int num;
    int x; //
    int y; //
    int d; //
    int amount;
};

int main(void) {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N,M,K;
        cin>>N>>M>>K;
        vector<vector<Ground>> map(N, vector<Ground>(N));
        vector<Organism> organisms;
        for(int i=0;i<N;i++) {
            map[i][0].flag = false;
            map[i][N-1].flag = false;
            map[0][i].flag = false;
            map[N-1][i].flag = false;
        }
        for(int i=0;i<K;i++) {
            int X, Y, C, D;
            cin>>Y>>X>>C>>D;
            organisms.push_back({i,X,Y,D,C});
            map[Y][X].organism.push_back(make_pair(D, i));
        }
        while(M>0) {
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    map[i][j].organism.clear();
                }
            }
            for(int i=0;i<organisms.size();i++) {
                if(organisms[i].amount>0) {
                    int prevX = organisms[i].x;
                    int prevY = organisms[i].y;
                    int prevD = organisms[i].d;
                    
                    organisms[i].x = prevX + dx[prevD];
                    organisms[i].y = prevY + dy[prevD];
                    
                    if(map[organisms[i].y][organisms[i].x].flag) {
                        map[organisms[i].y][organisms[i].x].organism.push_back(make_pair(organisms[i].amount, organisms[i].num));
                    } else {
                        organisms[i].amount/=2;
                        if(prevD==1) {
                            organisms[i].d=2;
                        } else if(prevD==2) {
                            organisms[i].d=1;
                        } else if(prevD==3) {
                            organisms[i].d=4;
                        } else if(prevD==4) {
                            organisms[i].d=3;
                        }
                        map[organisms[i].y][organisms[i].x].organism.push_back(make_pair(organisms[i].amount, organisms[i].num));
                    }
                }
            }
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    if(map[i][j].organism.size()>=2) {
                        sort(map[i][j].organism.begin(), map[i][j].organism.end(), greater<pair<int, int> >());
                        
                        for(int k=1;k<map[i][j].organism.size();k++) {
                            organisms[map[i][j].organism[k].second].d = organisms[map[i][j].organism[0].second].d;
                            organisms[map[i][j].organism[0].second].amount+=organisms[map[i][j].organism[k].second].amount;
                            organisms[map[i][j].organism[k].second].amount=0;
                            map[i][j].organism[k].first=0;
                        }
                    }
                }
            }
            
            M--;
        }
        int answer = 0;
        for(int i=0;i<organisms.size();i++) {
            answer += organisms[i].amount;
        }
        cout<<"#"<<t<<" "<<answer<<endl;
    }
    return 0;
}

