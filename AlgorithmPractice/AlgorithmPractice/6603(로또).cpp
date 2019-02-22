//
//  6603(로또).cpp
//  AlgorithmPractice
//
//  Created by 이해원 on 2019. 2. 21..
//  Copyright © 2019년 이해원. All rights reserved.
//

#include <iostream>
#include <vector>

/*
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
 */
using namespace std;

void recursive(vector<int> &lotto, vector<int> &inputs, int m, int n, int index) {
    if(lotto.size()==n) {
        for(int i=0;i<lotto.size();i++) {
            cout<<lotto[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    if(index==m) {
        return;
    }
    
    lotto.push_back(inputs[index]);
    recursive(lotto, inputs, m, n, index+1);
    lotto.pop_back();
    recursive(lotto, inputs, m, n, index+1);
}

int main(void) {
    int input;
    cin>>input;
    while(input!=0) {
        vector<int> v (input);
        vector<int> lotto;
        for(int i=0;i<input;i++) {
            cin>>v[i];
        }
        recursive(lotto, v, input, 6, 0);
        cout<<endl;
        cin>>input;
    }
    return 0;
}
