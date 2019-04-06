//
//  14889(스타트와링크).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 6..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int answer = INT_MAX;

void recursive(vector<vector<int>> &map, vector<int> &list, int N, int start, int link) {
    if(list.size() == N) {
        vector<int> startT, linkT;
        for(int i = 0; i < N; i++) {
            if(list[i] == 1) startT.push_back(i);
            else linkT.push_back(i);
        }
        
        int score1 = 0;
        int score2 = 0;
        for(int i = 0; i < N/2-1; i++) {
            for(int j = i + 1; j < N / 2; j++) {
                score1 += map[startT[i]][startT[j]] + map[startT[j]][startT[i]];
                score2 += map[linkT[i]][linkT[j]] + map[linkT[j]][linkT[i]];
            }
            
        }
        
        answer = min(answer, abs(score1 - score2));
        return;
    }
    
    if(start < N / 2) {
        list.push_back(1);
        recursive(map, list, N, start+1, link);
        list.pop_back();
    }
    
    if(link < N / 2) {
        list.push_back(2);
        recursive(map, list, N, start, link+1);
        list.pop_back();
    }
}


int main(void) {
    int N;
    scanf("%d", &N);
    vector<int> list;
    vector<vector<int>> map (N, vector<int> (N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    recursive(map, list, N, 0, 0);
    cout<<answer<<endl;
    return 0;
}
