//
//Calculater�̐錾
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
    //�z��̃|�C���^���󂯂Ƃ�A���ϒl���v�Z
    //
    static int CalcAverage(const vector<int>& dataArray);

};
#endif // !CALCULATER

