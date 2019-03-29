//
//  1759(암호만들기).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 3. 30..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkAnswer(vector<char> &crypography) {
    int consonant = 0;
    int vowel = 0;
    bool flag = false;
    int i = 0;
    while(i <= crypography.size()) {
        if(consonant >= 2 && vowel >= 1) {
            flag = true;
            break;
        }
        if(crypography[i] == 'a' || crypography[i] == 'i' || crypography[i] == 'e' || crypography[i] == 'o' || crypography[i] == 'u') {
            vowel++;
        } else if(crypography[i] != 'a' && crypography[i] != 'i' && crypography[i] != 'e' && crypography[i] != 'o' && crypography[i] != 'u'){
            consonant++;
        }
        i++;
    }
    
    return flag;
}

void recursive(vector<char> &arr, vector<char> crypography, int C, int L, int index) {
    if(crypography.size() == L) {
        //print
        if(checkAnswer(crypography)) {
            for(int i = 0; i < crypography.size(); i++) {
                cout<<crypography[i];
            }
            cout<<endl;
        }
        return;
    }
    
    if(index == C) {
        return;
    }
    
    crypography.push_back(arr[index]);
    recursive(arr, crypography, C, L, index+1);
    crypography.pop_back();
    recursive(arr, crypography, C, L, index+1);
    
}

int main(void) {
    int L, C;
    cin>>L>>C;
    vector<char> arr (C);
    vector<char> crypography;
    for(int i = 0; i < C; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    recursive(arr, crypography, C, L, 0);
    return 0;
}
