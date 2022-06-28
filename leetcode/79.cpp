#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> vis{7, vector<bool>(7, false)};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[0].size(); j++){
                fill(vis.begin(), vis.end(), vector<bool>(7, false));
                if(board[i][j] == word[0] && dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, int i, string word) {
        if(i == word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ) return false;
        if(vis[x][y]) return false;
        if(board[x][y] != word[i] ) return false;
        vis[x][y] = true;
        if(dfs(board, x - 1, y, i + 1, word)
        || dfs(board, x+1, y, i + 1, word)
        || dfs(board, x, y-1, i + 1, word)
        || dfs(board, x, y+1, i + 1, word)) return true;
        vis[x][y] = false;
        return false;
    }
};
