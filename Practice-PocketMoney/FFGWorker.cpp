//FFGWorker�̎���

#include "stdafx.h"
#include <iostream>
#include "FFGWorker.h"
using namespace std;


//�R���X�g���N�^
FFGWorker::FFGWorker(string iD_, string name_)
{
	SetID(iD_);
	SetName(name_);
	
};

//�f�X�g���N�^
FFGWorker::~FFGWorker(){}

void FFGWorker::Show()
{
	string a = GetName();
	string b = GetID();
	printf("���O�F%s�CID�F%s�@\n", GetName(), GetID());
}
