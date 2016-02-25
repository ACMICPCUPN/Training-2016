#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <set>
#include <vector>

#define num first
#define color second

using namespace std;

typedef pair<int, char> Ficha;

struct cmp
{
    bool operator ()(const Ficha &a, const Ficha &b)
    {
        return (a.color == b.color)? a.num < b.num : a.color < b.color;
    }    
};

string suits = "bgry";

int main()
{
    int T, M, n, group[4][101];
    char c;        
    set<Ficha, cmp> v;
    bool is_group, is_run;
    
    cin >> T;
    while(T--)
    {
        cin >> M;
        is_run = is_group = false;
        for (int i = 0; i < 4; ++i)        
            memset(group[i], 0, sizeof(group[i]));
        for(short i = 0, ii; i < M; i++)
        {
            cin >> n >> c;            
            v.insert(make_pair(n, c));
            ii = suits.find(c);            
            if(not group[ii][n])
                group[ii][n]++;
            if((group[0][n] + group[1][n] + group[2][n] + group[3][n]) >= 3)
                is_group = true;
        }
        if(is_group)
            cout << "YES" << endl;
        else
        {
            int len = v.size();
            vector<Ficha> arr(v.begin(), v.end());            
            for(int i = 0; !is_run and i < len - 2; i++)
            {
                bool same = (arr[i].color == arr[i + 1].color and  arr[i + 1].color == arr[i + 2].color);
                bool consecutivos = (arr[i].num + 1 == arr[i + 1].num and arr[i + 1].num + 1 == arr[i + 2].num);
                if(same and consecutivos)                
                    is_run = true;
            }
            cout << (is_run? "YES" : "NO") << endl;
        }
        v.clear();
    }
    return 0;
}
