//Runner�N���X�̎���
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccesser.h"
#include "Calculater.h"
#include "ErrorManager.h"
#include <iostream>
using namespace std;

//�R���X�g���N�^
Runner::Runner(){}

//�f�X�g���N�^
Runner::~Runner() {  }

void Runner::Run()
{

     ErrorManager::CreatLogFile();
	DataAccesser data;

	//Worker�^�̃f�[�^�z����쐬;
     vector<FFGWorker*> workerArray;
     workerArray = data.CreatWorkerDataArray(workerArray);
	
	vector<int> pocketMoneyArray (workerArray.size());
	for (int i = 0; i < workerArray.size() ; ++i)
	{
		pocketMoneyArray[i] = workerArray[i]->pocketMoney;
	}

	printf("���ς̂��������� %d�~�ł�\n",CalcAverage(pocketMoneyArray));

}
