//calculater�N���X�̎���
#include "Calculater.h"
#include "stdafx.h"


//�f�[�^�̕��ϒl���v�Z���郁�\�b�h
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

