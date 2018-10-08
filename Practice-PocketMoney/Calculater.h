//
//Calculaterの宣言
//
#pragma once
#ifndef CALCULATER
#define CALCULATER

#include <vector>
using namespace std;

class Calculater
{
public:
    Calculater();
    ~Calculater();

    //
    //配列のポインタを受けとり、平均値を計算
    //
    static int CalcAverage(const vector<int>& dataArray);

};
#endif // !CALCULATER

