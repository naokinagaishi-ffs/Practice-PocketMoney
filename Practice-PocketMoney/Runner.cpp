//Runner�N���X�̎���
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccesser.h"
#include "Calculater.h"
#include <iostream>
using namespace std;

//�R���X�g���N�^
Runner::Runner(){}

//�f�X�g���N�^
Runner::~Runner() {  }

void Runner::Run()
{

	DataAccesser data;

	//Worker�^�̃f�[�^�z����쐬;
     vector<FFGWorker*> workerArray(NULL);
     data.CreatWorkerDataArray(workerArray);
	
	vector<int> pocketMoneyArray (workerArray.size());
	int a = pocketMoneyArray.size();
	for (int i = 0; i < workerArray.size() ; ++i)
	{
		pocketMoneyArray[i] = workerArray[i]->pocketMoney;
	}

	printf("���ς̂��������� %d�~�ł�\n",CalcAverage(pocketMoneyArray));

}
