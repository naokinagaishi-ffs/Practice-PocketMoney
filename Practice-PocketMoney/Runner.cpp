//Runner�N���X�̎���
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccess.h"
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

	DataAccess dataAccesser;
	dataAccesser.CreatWorkerData();
	
	//for (int i = 0; )
	printf("�f�[�^���F", dataAccesser.dataCount);

}

void Runner::Show(const Worker& worker)
{
	printf("���O�F%s", worker.name.c_str());
}
