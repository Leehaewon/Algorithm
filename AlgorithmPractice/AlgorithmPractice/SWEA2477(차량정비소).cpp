//
//  SWEA2477(차량정비소).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 4..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>

// 미해결
using namespace std;
/*
1
2 2 6 1 2
3 2
4 2
0 0 1 2 3 4
 */

int main(void) {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int N, M, K, A, B;
        scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
        vector<vector<int>> askCounter (N);
        vector<vector<int>> repairCounter (M);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > askCounterLine; // time, num
        queue<pair<int, int> > repairCounterLine; // time, num
        vector<int> askCounterTime (N);
        vector<int> repairCounterTime (M);
        vector<pair<int, int> > askCounterCheck (N, make_pair(0, 0)); // time, num
        vector<pair<int, int> > repairCounterCheck (M, make_pair(0, 0));
        for(int i = 0; i < N; i++) {
            scanf("%d", &askCounterTime[i]);
        }
        for(int i = 0; i < M; i++) {
            scanf("%d", &repairCounterTime[i]);
        }
        for(int i = 0; i < K; i++) {
            int input;
            scanf("%d", &input);
            askCounterLine.push(make_pair(input, i+1));
        }
        
        int tempN = 0;
        int tempM = 0;
        int time = 0;
        int tempK = 0;
        while(true) {
            if(tempK == K)
                break;
            // 정비창구에서 끝난사람 먼저 빼주기

            if(tempM > 0) {
                for(int i = 0; i < M; i++) {
                    repairCounterCheck[i].first--;
                    if(repairCounterCheck[i].first == 0) {
                        tempM--;
                        tempK++;
                    }
                    if(repairCounterCheck[i].first < 0) {
                        repairCounterCheck[i].first = 0;
                    }
                }
            }
            
            
            // 접수창구에서 끝난 사람 빼주기
            if(tempN > 0) {
                for(int i = 0; i < N; i++) {
                    askCounterCheck[i].first--;
                    if(askCounterCheck[i].first == 0) {
                        repairCounterLine.push(make_pair(time, askCounterCheck[i].second)); // time, num
                        tempN--;
                    }
                    if(askCounterCheck[i].first < 0) {
                        askCounterCheck[i].first = 0;
                    }
                }
            }
            
            // 접수창구에서 끝난 사람 정비창구에 넣어주기
            while(tempM < M) {
                if(tempM == M) {
                    break;
                }
                if(repairCounterLine.size() > 0) {
                    int customerTime = repairCounterLine.front().first;
                    int customerNum = repairCounterLine.front().second;
                    if(time >= customerTime) {
                        for(int i = 0; i < N; i++) {
                            if(repairCounterCheck[i].first == 0) {
                                repairCounterLine.pop();
                                repairCounterCheck[i].first = repairCounterTime[i];
                                repairCounterCheck[i].second = customerNum;
                                repairCounter[i].push_back(customerNum);
                                tempM++;
                                break;
                            }
                        }
                    } else
                        break;
                } else {
                    break;
                }
            }
            
            // 접수창구에 넣어주기
            while(tempN < N) {
                if(tempN == N)
                    break;
                if(askCounterLine.size() > 0) {
                    int customerTime = askCounterLine.top().first;
                    int customerNum = askCounterLine.top().second;
                    if(time >= customerTime) {
                        for(int i = 0; i < N; i++) {
                            if(askCounterCheck[i].first == 0) {
                                askCounterLine.pop();
                                askCounterCheck[i].first = askCounterTime[i];
                                askCounterCheck[i].second = customerNum;
                                askCounter[i].push_back(customerNum);
                                tempN++;
                                break;
                            }
                        }
                    } else
                        break;
                } else {
                    break;
                }
            }
            time++;
        }
        
        int answer = 0;
        for(int i = 0; i < askCounter[A-1].size(); i++) {
            int value = askCounter[A-1][i];
            for(int j = 0; j < repairCounter[B-1].size(); j++) {
                if(value == repairCounter[B-1][j]) {
                    answer += value;
                }
            }
        }
        if(answer == 0) {
            answer = -1;
        }
        printf("#%d %d\n", t, answer);
    }
}

