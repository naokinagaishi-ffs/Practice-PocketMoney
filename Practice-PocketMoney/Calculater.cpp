//
//�v�Z�̊֐��̎���
//
#include "stdafx.h"
#include "Calculater.h"

//�f�[�^�̕��ϒl���v�Z���郁�\�b�h�B�z��̐擪�A�h���X���󂯎��
 int CalcAverage(const vector<int>& dataArray)
{
	int arrayCount = dataArray.size();
	int dataSum = 0;

	for (int i = 0; i < arrayCount; ++i)
	{
		dataSum += dataArray[i];
	}

	return dataSum / arrayCount;
}

