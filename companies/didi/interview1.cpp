// 求二维矩阵中联通域的个数

#include<iostream>
#include<queue>

using namespace std;

const int N = 10;
const int M = 12;
bool b_isTraver[N][M];

struct axis
{
    int x;
    int y;
};

char g_field[N][M] =
{
    {'w','.','.','.','.','.','.','.','.','w','w','.'},
    {'.','w','w','w','.','.','.','.','.','w','w','w'},
    {'.','.','.','.','w','w','.','.','.','w','w','.'},
    {'.','.','.','.','.','.','.','.','.','w','w','.'},
    {'.','.','.','.','.','.','.','.','.','w','.','.'},
    {'.','.','w','.','.','.','.','.','.','w','.','.'},
    {'.','w','.','w','.','.','.','.','.','w','w','.'},
    {'w','.','w','.','w','.','.','.','.','.','w','.'},
    {'.','w','.','w','.','.','.','.','.','.','w','.'},
    {'.','.','w','.','.','.','.','.','.','.','w','.'},
};

void get_con(queue<axis> &q){
    while (!q.empty())
    {
        for (int i = -1; i <= 1; ++ i)
        {
            for (int j = -1; j <= 1; ++ j)
            {
                if ( (q.front().x+i >= 0) && (q.front().x+i < N) && (q.front().y+j >= 0) && (q.front().y+j < M) && b_isTraver[q.front().x+i][q.front().y+j] == false )
                {
                    b_isTraver[q.front().x+i][q.front().y+j] = true;

                    if (g_field[q.front().x+i][q.front().y+j] == 'w')
                    {
                        axis tmp;
                        tmp.x = q.front().x+i;
                        tmp.y = q.front().y+j;

                        q.push(tmp);
                    }
                }
            }
        }
        q.pop();
    }
}

int main(){

    // 连通组的个数
    int conn = 0;

    // 初始化标志数组
    int i, j;
    for (i = 0; i < N; ++ i){
        for (j = 0; j < M; ++ j)
            b_isTraver[i][j] = false;
    }

    queue<axis> q;

    for (i = 0; i < N; ++ i){
        for (j = 0; j < M; ++ j){
            if (!b_isTraver[i][j] && g_field[i][j] == 'w'){
                ++ conn;

                cout << i << ' ' << j << endl;
                axis tmp;
                tmp.x = i;
                tmp.y = j;
                q.push(tmp);

                b_isTraver[i][j] = true;
                get_con(q);
            }
        }
    }

    cout << conn << endl;

    return 0;
}
