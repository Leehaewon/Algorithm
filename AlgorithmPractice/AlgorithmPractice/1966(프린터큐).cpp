//
//  1966(프린터큐).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 6..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <deque>

using namespace std;

// deque 이용법 다시 확인

int main(void) {
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);
        deque<pair<int, int> > dq; // 중요도, 문서번호
        vector<pair<int, int> > documents (N, make_pair(0, 0)); // 중요도, 출력순서
        int sequence = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &documents[i].first);
            dq.push_back(make_pair(documents[i].first, i));
        }
        
        while(!dq.empty()) {
            int importantNum = dq.front().first;
            int documentNum = dq.front().second;
            bool flag = true;
            
            for(int i = 0; i < dq.size()-1; i++) {
                if(dq.at(i+1).first > importantNum) {
                    flag = false;
                    break;
                }
            }
            dq.pop_front();
            
            if(flag) {
                sequence++;
                documents[documentNum].second = sequence;
            } else {
                dq.push_back(make_pair(importantNum, documentNum));
            }
        }
        cout<<documents[M].second<<endl;
    }
    return 0;
}
