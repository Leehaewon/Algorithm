//
//  2503(숫자야구).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 6..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Baseball {
    int mNum, mStrike, mBall;
    
    Baseball(int num, int strike, int ball) : mNum(num), mStrike(strike), mBall(ball) {}
    int firNum = mNum / 100;
    int sedNum = mNum % 100 / 10;
    int thdNum = mNum % 10;
};

int main() {
    int n = 0, result = 0;
    vector<Baseball> baseball;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int number, strike, ball;
        cin >> number >> strike >> ball;
        baseball.push_back(Baseball(number, strike, ball));
    }
    
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                if (i == j || j == k || k == i) continue;
                
                bool pass = true;
                for (int l = 0; l < n; l++) {
                    int strike = 0, ball = 0;
                    
                    if (i == baseball[l].firNum) strike++;
                    if (j == baseball[l].sedNum) strike++;
                    if (k == baseball[l].thdNum) strike++;
                    if (baseball[l].firNum == j || baseball[l].firNum == k) ball++;
                    if (baseball[l].sedNum == i || baseball[l].sedNum == k) ball++;
                    if (baseball[l].thdNum == i || baseball[l].thdNum == j) ball++;
                    if (strike != baseball[l].mStrike || ball != baseball[l].mBall)    pass = false;
                }
                
                if (pass)
                    result++;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}

