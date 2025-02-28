#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool Win(vector<vector<char>>& grid,char win){
        for(int i=0;i<3;i++){
            if(grid[i][0]==grid[i][1] && grid[i][2]==grid[i][1] && grid[i][0]==win) return true;
            if(grid[0][i]==grid[1][i] && grid[2][i]==grid[1][i] && grid[0][i]==win) return true;
        }
        return (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[0][0]==win) || (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[2][0]==win);
    }

    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3,vector<char>(3,' '));
        for(int i=0;i<moves.size();i++){
            if(i%2==0) grid[moves[i][0]][moves[i][1]]='A';
            else grid[moves[i][0]][moves[i][1]]='B';
        }
        if(Win(grid,'A')) return "A";
        if(Win(grid,'B')) return "B";
        if(moves.size()==9) return "Draw";
        return "Pending";
    }
};