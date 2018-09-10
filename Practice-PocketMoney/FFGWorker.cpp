//FFGWorkerの実装

#include "stdafx.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;


//コンストラクタ
FFGWorker::FFGWorker()
{
	//初期化
	iD = "";
	name = "";
	pocketMoney = 0;

};

//コンストラクタ
FFGWorker::FFGWorker(string iD_, string name_)
{
	//SetID(iD_);
	//SetName(name_);
	
	//初期化
	iD = iD_;
	name = name_;
	pocketMoney = 0; 
	
};

//デストラクタ
FFGWorker::~FFGWorker(){}


