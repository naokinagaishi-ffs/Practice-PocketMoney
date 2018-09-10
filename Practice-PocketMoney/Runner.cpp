//Runnerクラスの実装
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccess.h"
#include <iostream>
using namespace std;

//コンストラクタ
Runner::Runner(){}

//デストラクタ
Runner::~Runner() {  }

void Runner::Run()
{
	//FFGWorker a("abc","122");

	//Runner::Show(a);

	DataAccess dataAccesser;
	dataAccesser.CreatWorkerData();
	
	//for (int i = 0; )
	printf("データ数：", dataAccesser.dataCount);

}

void Runner::Show(const Worker& worker)
{
	printf("名前：%s", worker.name.c_str());
}
