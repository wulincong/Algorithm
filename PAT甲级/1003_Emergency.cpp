#include <iostream>
#define MAXV 510
#define INF 10000000
using namespace std;

int Map[MAXV][MAXV], weight[MAXV], dis[MAXV], pre[MAXV], members[MAXV], num[MAXV];
bool vis[MAXV];

int main(int argc, char **argv){
    int i, N, M, C1, C2;
    cin >> N >> M >> C1 >> C2; 
    for (int i=0; i < N; i++) 
        cin >> weight[i];
    //初始化
    for(i=0; i < N; i++)
        dis[i] = INF;
        vis[i] = false;
        members[i] = 0;
        for (int j = 0; j < N; j++) 
            Map[i][j] = INF;
    int a, b, c;
    for(int i=0; i < M; i++){
        cin >> a >> b >> c;
        Map[a][b] = Map[b][a] = c;
    }

    dis[C1] = 0;  //出发点距离为0
    members[C1] = weight[C1];  //成员是路径上权重和
    num[C1] = 1;
    for(int i = 0; i < N; i++){
        int min = -1, mindis = INF;
        for(int j = 0; j < N ; j++){
            if(dis[j] < mindis && !vis[j]){
                min =  j;
                mindis = dis[j];
            }
        }
        if(min == -1) break;
        vis[min] = true;
        for(int j = 0; j < N; j++){
            if(!vis[j] && Map[min][j] != INF ){
                if( dis[min] + Map[min][j] < dis[j]){
                    dis[j] = dis[min] + Map[min][j];
                    num[j] = num[min];  //路径数量
                    members[j] = members[min] + weight[j];
                }else if(dis[min] + Map[min][j] == dis[j]){
                    num[j] = num[min] + num[j];
                    //如果后面的路径上成员大于前面的，需要更新成员数量
                    if(members[min] + weight[j] > members[j]) 
                        members[j] = members[min] + weight[j];
                }
            }
        }
    }
    cout << num[C2] << " " << members[C2] << endl;
    return 0;
}











