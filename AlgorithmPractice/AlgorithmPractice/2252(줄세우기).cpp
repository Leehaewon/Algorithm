//
//  2252(줄세우기).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 10..
//  Copyright © 2019년 이해원. All rights reserved.
//

// 위상정렬
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>> &graph, int N, vector<int> &edges) {
    queue<int> q;
    // 들어오는 간선의 수가 0인 정점들을 queue에 저장
    for(int i=1;i<=N;i++) {
        if(edges[i]==0)
            q.push(i);
    }
    
    while(!q.empty()) {
        int cnode = q.front();
        q.pop();
        cout<<cnode<<" ";
        // cnode 정점과 연결된 모든 정점 check
        for(int i=0;i<graph[cnode].size();i++) {
            edges[graph[cnode][i]]--;
            if(edges[graph[cnode][i]]==0)
                q.push(graph[cnode][i]);
        }
    }
}

int main(void) {
    int N, M;
    cin>>N>>M;
    vector<vector<int>> graph(N+1);
    vector<int> edges(N+1, 0); // 들어오는 간선의 수 저장한 배열
    for(int i=0;i<M;i++) {
        int S,E;
        cin>>S>>E;
        graph[S].push_back(E);
        edges[E]++;
    }
    topologicalSort(graph, N, edges);
    return 0;
}
