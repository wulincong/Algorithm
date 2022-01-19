#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Custom
{
public:
    int c_hour, c_minute, c_second, s_hour, s_minute, s_second;
    int playing_time;
    bool is_VIP, is_served = false;

    Custom(int, int, int, int, bool);
};

Custom::Custom(int c_h, int c_m, int c_s, int p, bool is_V):
c_hour(c_h), c_minute(c_m), c_second(c_s), is_VIP(is_V){}

class table{
public:
    int e_hour = 8, e_minute = 0, e_second = 0;  //服务截至时间
    bool is_VIP = false;
    int serve_number = 0;
    int serve_index;
    void Serve(Custom * C){
        serve_number++;
        C->s_hour = e_hour;
        C->s_minute = e_minute;
        C->s_second = e_second;
        C->is_served = true;
        if(C->playing_time >= 120) 
            e_hour += 2;  //大于两小时就截断为两小时
        else{
            e_hour += C->playing_time / 60;

        }
    }
};

Custom * pick(vector<Custom> &customs){ 
    for(auto it : customs){
        if(it.is_VIP == true & !it.is_served) return &it;
    }
    return NULL;
}

table * pick_table(vector<table> &tables){//选出最早结束的桌子
    return &tables[0];
}

bool cmp(Custom &a, Custom &b){
    return a.s_hour < b.s_hour;
}

int main(){
    int N;
    cin >> N;
    vector<Custom> customers;
    for(int i=0; i<N; i++){
        int h, m, s, p, v;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &v);
        bool is_VIP = v == 1 ? true : false;
        customers.push_back(Custom(h, m, s, p, is_VIP));
    }
    int K, M;
    cin >> K >> M;
    vector<table> tables(K);
    for(int i=0; i < M; i++){
        int index;
        cin >> index;
        tables[index].is_VIP = true;
    }   
    //初始化
    Custom * cus_pointer = & customers[0];
    for(int i=0; i<K; i++){
        if(tables[i].is_VIP){ //如果当前桌子是vip桌子，pick一个未服务的vip用户
            if(Custom * c = pick(customers)){
                tables[i].Serve(c);
            }   //找到一个vip用户
        }else{ // 没找到vip
            if(!cus_pointer->is_served)
                tables[i].Serve(cus_pointer++);
            else cus_pointer++; //如果此人已被服务过，跳过
        }
    }
    while(cus_pointer != &customers[N-1]){
        table * t = pick_table(tables);  //最早结束的桌子
        if(t->is_VIP){ //如果当前桌子是vip桌子，pick一个未服务的vip用户
            if(Custom * c = pick(customers)){
                t->Serve(c);
            }   //找到一个vip用户
        }else{ // 没找到vip
            if(!cus_pointer->is_served)
                t->Serve(cus_pointer++);
            else cus_pointer++; //如果此人已被服务过，跳过
        }
    }

    sort(customers.begin(), customers.end(), cmp);
    for(auto it:customers){
        
    }

}


