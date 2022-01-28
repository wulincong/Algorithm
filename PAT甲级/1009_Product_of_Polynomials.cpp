#include <iostream>
#include <vector>

using namespace std;

int main(int argc ,char **argv){
    int K1, K2, tmp_exp;
    float tmp_coe;
    vector<float> N1(1001,0);
    vector<float> N2(1001,0);
    vector<float> result(2001,0);
    cin >> K1;
    for(int i = 0; i < K1; i++){
        cin >> tmp_exp >> tmp_coe;
        N1[tmp_exp] = tmp_coe;
    }
    cin >> K2;
    for(int i = 0; i < K2; i++){
        cin >> tmp_exp >> tmp_coe;
        N2[tmp_exp] = tmp_coe;
    }

    for(int i = 0; i < 1001 ; i++){
        for(int j = 0; j < 1001 ; j++){
            result[i+j] += N1[i] * N2[j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < 2001 ; i++){
        if(result[i] != 0){
            cnt++;
        }
    }
    cout << cnt << " ";
    for(int i = 2001; i >= 0; i--){
        if(result[i] != 0){
            // float res = (int)((result[i] + 0.05) * 10) / 10.0;
            printf("%d %.1f", i, result[i]);
            cnt--;
            if(cnt != 0) cout << " ";
        }
    }

    return 0;
}