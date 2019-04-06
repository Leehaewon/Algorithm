//
//  1697(숨바꼭질).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 6..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

// bfs 할때 visit check 필수
int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    queue<pair<int, int> > q; // position, time
    vector<bool> is_visit (10000001, false);
    int answer = 0;
    q.push(make_pair(N, 0));
    is_visit[N] = true;
    
    while(!q.empty()) {
        int cposition = q.front().first;
        int ctime = q.front().second;
        q.pop();
        
        if(cposition == K) {
            answer = ctime;
            break;
        }
        
        if(cposition-1 >= 0 && !is_visit[cposition-1]) {
            is_visit[cposition-1] = true;
            q.push(make_pair(cposition-1, ctime+1));
        }
        
        if(cposition+1 <= 100000 && !is_visit[cposition+1]) {
            is_visit[cposition+1] = true;
            q.push(make_pair(cposition+1, ctime+1));
        }
        
        if(cposition*2 <= 100000 && !is_visit[cposition*2]) {
            is_visit[cposition*2] = true;
            q.push(make_pair(cposition*2, ctime+1));
        }
        
    }
    cout<<answer<<endl;
    
    return 0;
}


