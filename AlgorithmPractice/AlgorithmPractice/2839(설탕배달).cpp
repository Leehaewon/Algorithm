//
//  2839(설탕배달).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 22..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);
    int divide5 = N / 5;
    int answer = 10000000;
    for(int i = divide5; i >= 0 ; i--) {
        int temp = (N - i * 5);
        if( temp % 3 == 0) {
            answer = min(answer, i + (temp / 3));
        }
    }
    if(answer == 10000000) {
        answer = -1;
    }
    printf("%d\n", answer);
    return 0;
}
