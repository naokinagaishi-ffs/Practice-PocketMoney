//Runner�N���X�̎���
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccess.h"
#include "Calculater.h"
#include <iostream>
using namespace std;

//�R���X�g���N�^
Runner::Runner(){}

//�f�X�g���N�^
Runner::~Runner() {  }

void Runner::Run()
{
	//FFGWorker a("abc","122");

	//Runner::Show(a);

	DataAccess data;

	//Worker�^�̃f�[�^�z����쐬;
	data.CreatWorkerData();
	
	int* pocketMoneyArray = NULL;
	pocketMoneyArray = new int[data.dataCount ];
	for (int i = 0; i < data.dataCount ; ++i)
	{
		int a = data.workerArray[i].pocketMoney;
		pocketMoneyArray[i] = data.workerArray[i].pocketMoney;
	}

	printf("���ς̂��������� %d �~�B\n",CalcAverage(pocketMoneyArray));

	//printf("�f�[�^���F%d", dataAccesser.dataCount);

}

void Runner::Show(const Worker& worker)
{
	printf("���O�F%s", worker.name.c_str());
}
