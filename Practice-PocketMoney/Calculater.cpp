//
//計算の関数の実装
//
#include "stdafx.h"
#include "Calculater.h"
#include <iostream>
using namespace std;

//
//コンストラクタ
//
Calculater::Calculater()
{
}

//
//デストラクタ
//
Calculater::~Calculater()
{
}

//
//データの平均値を計算するメソッド。配列の先頭アドレスを受け取る
// 
int Calculater::CalcAverage(const vector<int>& dataArray)
{
	int arrayCount = dataArray.size();
	
     if (arrayCount == 0)
     {
         cout << "０割りしています" << endl;
         return 0;

     }

     int dataSum = 0;
     for (int i = 0; i < arrayCount; ++i)
	{
		dataSum += dataArray[i];
	}

	return dataSum / arrayCount;
}

