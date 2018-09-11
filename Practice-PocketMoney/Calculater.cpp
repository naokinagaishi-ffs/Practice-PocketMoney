//calculaterクラスの実装
#include "Calculater.h"
#include "stdafx.h"


//データの平均値を計算するメソッド
 int CalcAverage(int dataArray[])
{
	int arrayCount = sizeof(dataArray) / sizeof(dataArray[0]);
	int dataSum = 0;

	for (int i = 0; i < arrayCount; ++i)
	{
		dataSum += dataArray[i];
	}

	return dataSum / arrayCount;
}

