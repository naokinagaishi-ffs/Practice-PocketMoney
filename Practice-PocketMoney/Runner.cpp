//Runner�N���X�̐錾
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;

//�R���X�g���N�^
Runner::Runner(){}

//�f�X�g���N�^
Runner::~Runner() {  }

void Runner::Run()
{
	FFGWorker a("abc","122");

	Runner::Show(&a);
	
}

void Runner::Show(const Worker* worker)
{
	printf("���O�F%s", worker->name);
}
