#include<bits/stdc++.h>
#include "helper.cpp"
using namespace std;

bool findOverlapping(pair<int,int> n,vector<int> rangeX,vector<int> rangeY){
    if(n.first<rangeX[0] || n.first>rangeX[1]){
        return false;
    }
    if (n.second < rangeY[0] )
    {
        return false;
    }
    if(n.second > rangeY[1] - (n.first - rangeX[0])){
        return false;
    }
    return true;
}

int solve(vector<pair<int,int>> n,P q){
    pair<int, int> A = {q.x+q.d,q.y},B={q.x,q.y},C={q.x,q.y+q.d};

    vector<int> rangeX = findXRange(A, B, C);
    vector<int> rangeY = findYRange(A, B, C);

    int res = 0;

    for (int i = 0; i < n.size();i++){
        // if(n[i].first<rangeX[0]){
        //     continue;
        // }
        // if (n[i].first > rangeX[1])
        // {
        //     break;
        // }
        if(findOverlapping(n[i],rangeX,rangeY)){
            res++;
        }
        
    }

    return res;

}

bool comp(pair<int,int> p,pair<int,int> q){
    return p.first < q.first;
}

int main(){
    vector<int> inputs;
    fstream fs("data_centers_hard_input (1).txt");
    ofstream of("output.txt");
    int x, counter = 0;
    while (fs >> x)
    {
        if (counter < 2)
        {
            counter++;
            continue;
        }
        inputs.push_back(x);
    }
    vector<pair<int, int>> n = buildN(inputs);
    vector<P> q = buildQ(inputs);

    cout << solve(n, q[310374]);
    // sort(n.begin(),n.end(),comp);
    // for (int i = 0; i < q.size();i++){
    //     of << to_string(solve(n, q[i]))<<endl;
    // }
    of.close();
    fs.close();
}