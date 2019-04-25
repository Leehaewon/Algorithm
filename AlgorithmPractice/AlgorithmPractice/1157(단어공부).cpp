//
//  1157(단어공부).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 4. 25..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin>>s;
    int alphabet[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        char temp = tolower(s[i]) - 'a';
        alphabet[temp]++;
    }
    int maxIndex = -1;
    int max = -1;
    int same = 0;
    for(int i = 0; i < 26; i++) {
        if(max < alphabet[i]) {
            max = alphabet[i];
            maxIndex = i;
            same = 0;
        } else if(max == alphabet[i]) {
            same++;
        }
    }
    if(same > 0) {
        cout<<"?"<<endl;
    } else {
        cout<<(char)(maxIndex+'A')<<endl;
    }
    
    return 0;
}
