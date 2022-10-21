#include<bits/stdc++.h>
using namespace std;

// Global variables and macros
int i = 0;
#define N (323802 * 2) - 3
#define Q (310753 * 3) + N

// defining structure
struct P
{
    int x, y, d;
};


vector<pair<int,int>> buildN(vector<int> inputs){
    vector<pair<int, int>> n;
    while (i <= N)
    {
        pair<int, int> p = {inputs[i], inputs[i + 1]};
        n.emplace_back(p);
        i += 2;
    }
    return n;
}

vector<P> buildQ(vector<int> inputs){
    vector<P> q;
    while (i <= Q)
    {
        P p = {inputs[i], inputs[i + 1], inputs[i + 2]};
        q.push_back(p);
        i += 3;
    }
    return q;
}

vector<int> findXRange(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    vector<int> res;
    int fromX = INT_MAX,toX=INT_MIN;        //setting range
    if (A.first < B.first)
    {
        if (A.first < C.first)
        {
            fromX = A.first;
        }
        else
        {
            fromX = C.first;
        }
    }
    else
    {
        if (B.first < C.first)
        {
            fromX = B.first;
        }
        else
        {
            fromX = C.first;
        }
    }

    if (A.first > B.first)
    {
        if (A.first > C.first)
        {
            toX = A.first;
        }
        else
        {
            toX = C.first;
        }
    }
    else
    {
        if (B.first > C.first)
        {
            toX = B.first;
        }
        else
        {
            toX = C.first;
        }
    }
    res.emplace_back(fromX);
    res.emplace_back(toX);
    return res;
}

vector<int> findYRange(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    vector<int> res;
    int fromY = INT_MAX, toY = INT_MIN;
    if (A.second < B.second)
    {
        if (A.second < C.second)
        {
            fromY = A.second;
        }
        else
        {
            fromY = C.second;
        }
    }
    else
    {
        if (B.second < C.second)
        {
            fromY = B.second;
        }
        else
        {
            fromY = C.second;
        }
    }

    if (A.second > B.second)
    {
        if (A.second > C.second)
        {
            toY = A.second;
        }
        else
        {
            toY = C.second;
        }
    }
    else
    {
        if (B.second > C.second)
        {
            toY = B.second;
        }
        else
        {
            toY = C.second;
        }
    }
    res.emplace_back(fromY);
    res.emplace_back(toY);
    return res;
}
