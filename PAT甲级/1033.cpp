#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Station{
public:
    double price;
    int distance;
    bool operator<(Station & b){
        return this->distance < b.distance;
    }
};

int main_(){
    int Cmax, Distance, Davg, N;
    cin >> Cmax >> Distance >> Davg >> N;
    vector<Station> stations(N);
    for(int i = 0; i < N; i++)
        cin >> stations[i].price >> stations[i].distance;
    sort(stations.begin(), stations.end());
    if(stations[0].distance != 0){
        printf("The maximum travel distance = 0.00\n" );
        return 0;
    }
    Station * curr = &stations[0]; 
    double max_distance = Cmax * Davg;
    double cost = 0.0, last_gas_distance = 0.0;
    while(curr != &stations[N-1]){
        int flag = 0;
        Station * sta = curr;
        while(sta->distance < max_distance){
            if(sta->price < curr->price){flag = 1; break;}
            sta++;
        }if(flag == 1){  // 替换
            cost += (sta->distance - curr->distance - last_gas_distance)/Davg * curr->price;
            curr = sta;
            last_gas_distance = 0.0;
        }if(! flag){//走完最远距离都没有比当前油价低的
            sta = curr + 1;
            Station * min_station = sta;
            while(sta->distance < max_distance){
                if(sta->price < min_station->price)
                    min_station = sta;
                sta++;
            }
            cost += curr->price * Cmax;
            last_gas_distance = max_distance - sta->distance;
            curr = sta;
        }
        max_distance = curr->distance + Cmax * Davg;
    }
    cost += curr->price * (Distance - curr->distance)/Davg;
    printf("%.2f", cost);
    return 0;
}

int main(){
    main_();
    // test();
}


