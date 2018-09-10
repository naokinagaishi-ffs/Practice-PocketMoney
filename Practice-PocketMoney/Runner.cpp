//Runnerクラスの実装
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccess.h"
#include "Calculater.h"
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

	DataAccess data;

	//Worker型のデータ配列を作成;
	data.CreatWorkerData();
	
	int* pocketMoneyArray = NULL;
	pocketMoneyArray = new int[data.dataCount ];
	for (int i = 0; i < data.dataCount ; ++i)
	{
		int a = data.workerArray[i].pocketMoney;
		pocketMoneyArray[i] = data.workerArray[i].pocketMoney;
	}

	printf("平均のお小遣いは %d 円。\n",CalcAverage(pocketMoneyArray));

	//printf("データ数：%d", dataAccesser.dataCount);

}

void Runner::Show(const Worker& worker)
{
	printf("名前：%s", worker.name.c_str());
}
