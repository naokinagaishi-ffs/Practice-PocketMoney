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
	Worker* workerArray= data.CreatWorkerData();
	
	vector<int> pocketMoneyArray (data.dataCount);

	for (int i = 0; i < pocketMoneyArray.size() ; ++i)
	{
		pocketMoneyArray[i] = data.workerArray[i].pocketMoney;
	}

	printf("���ς̂��������� %d",CalcAverage(&pocketMoneyArray[0]));

	//printf("�f�[�^���F%d", dataAccesser.dataCount);

}

void Runner::Show(const Worker& worker)
{
	printf("���O�F%s", worker.name.c_str());
}
