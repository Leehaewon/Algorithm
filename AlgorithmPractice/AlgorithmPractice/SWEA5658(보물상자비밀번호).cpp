//
//  SWEA5658(보물상자비밀번호).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 5..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
/*
1
12 10
1B3B3B81F75E
*/


int stringToHex(string s) {
    int result = 0;
    for(int i = 0; i < s.size(); i++) {
        if('0' <= s[i] && s[i] <= '9') {
            result += pow(16, s.size()-i-1)*(s[i] - '0');
        } else {
            result += pow(16, s.size()-i-1)*(s[i] - 'A' + 10);
        }
    }
    return result;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int N, K;
        //string input;
        scanf("%d %d", &N, &K);
        vector<char> inputs (N+1);
        vector<string> answers;
        for(int i = 0; i <= N; i++) {
            scanf("%1c", &inputs[i]);
        }
        
        int numSize = N/4;
        for(int i = 1; i <= N; i++) {
            string temp;
            for(int j = 0; j < numSize; j++) {
                int position = i + j;
                if(position > N) {
                    position -= N;
                }
                temp += inputs[position];
            }
            answers.push_back(temp);
        }
        
        sort(answers.begin(), answers.end(), greater<string>());
        answers.erase(unique(answers.begin(), answers.end()), answers.end());

        cout<<"#"<<t<<" "<<stringToHex(answers[K-1])<<endl;
    }
    return 0;
}
