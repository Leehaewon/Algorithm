//
//  10971(외판원순회2).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 30..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(void) {
    int N;
    cin>>N;
    vector<int> sequence (N);
    vector<vector<int>> weights (N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        sequence[i] = i;
        for(int j = 0; j < N; j++) {
            cin>>weights[i][j];
        }
    }
    // 도시에 갈 수없을 때도 weights[i][j] = 0 이라는 것 중요
    int answer = INT_MAX;
    do{
        int temp = 0;
        int start = sequence[0];
        bool flag = false;
        
        for(int i = 0; i < N-1; i++) {
            if(weights[sequence[i]][sequence[i+1]] == 0) {
                flag = true;
                continue;
            }
            temp += weights[sequence[i]][sequence[i+1]];
        }
        if(flag) {
            continue;
        }
        if(weights[sequence[N-1]][start] == 0) {
            continue;
        }
        temp+= weights[sequence[N-1]][start];
        answer = min(answer, temp);
        
    } while(next_permutation(sequence.begin(), sequence.end()));
    
    cout<<answer<<endl;
    return 0;
}
