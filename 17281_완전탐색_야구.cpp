#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, inning[55][9], score = 0, Max = 0;
bool check[9];
vector<int> v;
void play()
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        bool home[4] = {false};
        int out = 0;
        while (out != 3)
        {
            home[0] = true;
            if (inning[i][v[j]] == 0) out++;
            else
            {
                for (int k = 3; k >= 0; k--)
                {
                    if (home[k])
                    {
                        if (k + inning[i][v[j]] > 3)
                        {
                            score++;
                            home[k] = false;
                        }
                        else
                        {
                            home[k + inning[i][v[j]]] = true;
                            home[k] = false;
                        }
                    }
                }
            }
            j++;
            if (j == 9) j = 0;
        }
    }
    return;
}
void playorder(int location)
{
    if (location == 9)
    {
        play();
        Max = max(Max, score);
        score = 0;
        return;
    }
    if (location == 3)
    {
        v.push_back(0);
        playorder(location + 1);
        v.pop_back();
        return;
    }
    for (int i = 1; i < 9; i++)
    {
        if (!check[i] || location == 3)
        {
            v.push_back(i);
            check[i] = true;
            playorder(location + 1);
            check[i] = false;
            v.pop_back();
        }
    }
    return;
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &inning[i][j]);
    playorder(0);
    printf("%d\n", Max);
}
