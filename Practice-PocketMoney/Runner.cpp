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
	Worker* pW;

	FFGWorker a("abc","122");

	pW = &a;

	a.Show();
	//printf(a.GetName);
}
