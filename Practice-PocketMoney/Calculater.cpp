//
//�v�Z�̊֐��̎���
//
#include "stdafx.h"
#include "Calculater.h"
#include <iostream>
using namespace std;

//�f�[�^�̕��ϒl���v�Z���郁�\�b�h�B�z��̐擪�A�h���X���󂯎��
 int CalcAverage(const vector<int>& dataArray)
{
	int arrayCount = dataArray.size();
	
     if (arrayCount == 0)
     {
         cout << "�O���肵�Ă��܂�" << endl;
         return 0;

     }

     int dataSum = 0;
     for (int i = 0; i < arrayCount; ++i)
	{
		dataSum += dataArray[i];
	}

	return dataSum / arrayCount;
}

