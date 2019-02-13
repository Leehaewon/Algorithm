//
//  16235(나무재테크).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 13..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ground {
    vector<int> trees;
    int nutrient;
};

bool is_range(int x, int y, int N) {
    return (0<=x&&x<N)&&(0<=y&&y<N);
}

void nourish(Ground &ground) {
    sort(ground.trees.begin(), ground.trees.end());
    int index=-1;
    for(int i=0;i<ground.trees.size();i++) {
        if(ground.nutrient-ground.trees[i]>=0) {
            ground.nutrient-=ground.trees[i];
            ground.trees[i]+=1;
        } else {
            index=i;
            break;
        }
    }
    
    // delete
    if(index!=-1) {
        int size = (int)ground.trees.size();
        for(int i=size-1;i>=index;i--) {
            ground.nutrient+=ground.trees[i]/2;
            ground.trees.pop_back();
        }
    }
    
}

void spring_summer(vector<vector<Ground>> &map, int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j].trees.size()>0) {
                nourish(map[i][j]);
            }
        }
    }
}


void fall(vector<vector<Ground>> &map, int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j].trees.size()>0) {
                
                for(int k=0;k<map[i][j].trees.size();k++) {
                    if(map[i][j].trees[k]%5==0) {
                        if(is_range(j-1,i-1,N)) map[i-1][j-1].trees.push_back(1);
                        if(is_range(j-1,i,N)) map[i][j-1].trees.push_back(1);
                        if(is_range(j-1,i+1,N)) map[i+1][j-1].trees.push_back(1);
                        if(is_range(j,i-1,N)) map[i-1][j].trees.push_back(1);
                        if(is_range(j,i+1,N)) map[i+1][j].trees.push_back(1);
                        if(is_range(j+1,i-1,N)) map[i-1][j+1].trees.push_back(1);
                        if(is_range(j+1,i,N)) map[i][j+1].trees.push_back(1);
                        if(is_range(j+1,i+1,N)) map[i+1][j+1].trees.push_back(1);
                    }
                }
            }
        }
    }
}

void winter(vector<vector<Ground>> &map, vector<vector<int>> &nutrients, int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            map[i][j].nutrient+=nutrients[i][j];
        }
    }
}

int main(void) {
    int answer = 0;
    int N, M, K;
    cin>>N>>M>>K;
    vector<vector<int>> nutrients(N, vector<int>(N));
    vector<vector<Ground>> map(N, vector<Ground>(N));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>nutrients[i][j];
            map[i][j].nutrient=5;
        }
    }
    for(int i=0;i<M;i++) {
        int x, y, age;
        cin>>y>>x>>age;
        map[y-1][x-1].trees.push_back(age);
    }
    while(K--) {
        spring_summer(map, N);
        fall(map, N);
        winter(map, nutrients, N);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            answer += map[i][j].trees.size();
        }
    }
    cout<<answer<<endl;
    return 0;
}
