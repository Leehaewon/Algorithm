//
//  Programmers_완전탐색(모의고사).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 30..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int> > person; // count, num
    vector<vector<int>> answers_person =  {
        {1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    person.push_back(make_pair(0, 1));
    person.push_back(make_pair(0, 2));
    person.push_back(make_pair(0, 3));
    for(int i = 0; i < answers.size(); i++) {
        int index = i;
        if(answers[i] == answers_person[0][index%10]) {
            person[0].first++;
        }
        if(answers[i] == answers_person[1][index%8]) {
            person[1].first++;
        }
        if(answers[i] == answers_person[2][index%10]) {
            person[2].first++;
        }
    }
    sort(person.begin(), person.end(), greater<pair<int, int> >());
    int maxCount = person[0].first;
    answer.push_back(person[0].second);
    for(int i=1;i<person.size();i++) {
        if(maxCount == person[i].first) {
            answer.push_back(person[i].second);
        } else continue;
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

int main(void) {
    //vector<int> answers = {1, 2, 3, 4, 5};
    vector<int> answers = {1, 3, 2, 4, 2};
    solution(answers);
    return 0;
}

