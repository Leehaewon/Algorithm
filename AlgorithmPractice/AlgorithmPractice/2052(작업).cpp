//
//  2052(작업).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 10..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int topologicalSort(vector<vector<int>> &graph, int N, vector<int> &worktimes, vector<int> &edges) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q; //time, num
    for(int i=1;i<=N;i++) {
        if(edges[i]==0)
            q.push(make_pair(worktimes[i], i));
    }
    
    while(!q.empty()) {
        int ctime = q.top().first;
        int cnode = q.top().second;
        q.pop();
        answer = ctime;

        for(int i=0;i<graph[cnode].size();i++) {
            edges[graph[cnode][i]]--;
            if(edges[graph[cnode][i]]==0)
                q.push(make_pair(ctime+worktimes[graph[cnode][i]], graph[cnode][i]));
        }
    }
    return answer;
}

int main(void) {
    int N;
    cin>>N;
    vector<vector<int>> graph(N+1);
    vector<int> worktimes(N+1);
    vector<int> edges(N+1, 0);
    for(int i=1;i<=N;i++) {
        int M;
        cin>>worktimes[i]>>M;
        for(int j=0;j<M;j++) {
            int S;
            cin>>S;
            graph[S].push_back(i);
            edges[i]++;
        }
    }
    cout<<topologicalSort(graph, N, worktimes, edges)<<endl;
    return 0;
}
