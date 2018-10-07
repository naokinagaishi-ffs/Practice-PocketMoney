//
//計算の関数の実装
//
#include "stdafx.h"
#include "Calculater.h"
#include <iostream>
using namespace std;

//データの平均値を計算するメソッド。配列の先頭アドレスを受け取る
 int CalcAverage(const vector<int>& dataArray)
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

