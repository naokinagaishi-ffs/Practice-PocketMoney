//FFGWorker�̎���

#include "stdafx.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;


//�R���X�g���N�^
FFGWorker::FFGWorker()
{
	//������
	iD = "";
	name = "";
	pocketMoney = 0;

};

//�R���X�g���N�^
FFGWorker::FFGWorker(string iD_, string name_)
{
	//SetID(iD_);
	//SetName(name_);
	
	//������
	iD = iD_;
	name = name_;
	pocketMoney = 0; 
	
};

//�f�X�g���N�^
FFGWorker::~FFGWorker(){}


