//FFGWorkerの実装

#include "stdafx.h"
#include <iostream>
#include "FFGWorker.h"
using namespace std;


//コンストラクタ
FFGWorker::FFGWorker(string iD_, string name_)
{
	SetID(iD_);
	SetName(name_);
	
};

//デストラクタ
FFGWorker::~FFGWorker(){}

void FFGWorker::Show()
{
	string a = GetName();
	string b = GetID();
	printf("名前：%s，ID：%s　\n", GetName(), GetID());
}
