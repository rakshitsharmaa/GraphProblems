#include<iostream>
using namespace std;

int R, C;
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void PrintMat(char mat[][50]) {
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}
void flodFill(char mat[][50], int i, int j, char ch, char color) {
    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return;
    }
    if (mat[i][j] != ch)
    {
        return;
    }
    mat[i][j] = color;
    PrintMat(mat);
    cout << endl;
    for (int k = 0; k < 4; k++)
    {
        flodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen( "inputForFloodFill.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> R >> C;
    char mat[R][50];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> mat[i][j];
        }
    }
    PrintMat(mat);
    flodFill(mat, 8, 13, '.', 'r');
    PrintMat(mat);

}