//
//  SWEA7088(은기의송아지세기).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 31..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// cout 양이 많을 때는 무조껀 scanf로, 
int main(void) {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int N, Q;
        scanf("%d %d", &N, &Q);
        vector<vector<int>> calves (3, vector<int> (N+2, 0));
        vector<vector<int>> answer (Q+1, vector<int> (3, 0));
        for(int i = 1; i <= N; i++) {
            int input;
            scanf("%d", &input);
            calves[input-1][i]++;
            for(int j = 0; j < 3; j++) {
                calves[j][i+1] = calves[j][i];
            }
        }
        printf("#%d\n", t);
        for(int i = 1; i <= Q; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            for(int j = 0; j < 3; j++) {
                printf("%d ",calves[j][end] - calves[j][start-1]);
            }
            printf("\n");
        }
    }
    return 0;
}
