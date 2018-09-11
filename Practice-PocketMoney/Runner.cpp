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
	Worker* workerArray= data.CreatWorkerData();
	
	vector<int> pocketMoneyArray (data.dataCount);

	for (int i = 0; i < pocketMoneyArray.size() ; ++i)
	{
		pocketMoneyArray[i] = data.workerArray[i].pocketMoney;
	}

	printf("平均のお小遣いは %d",CalcAverage(&pocketMoneyArray[0]));

	//printf("データ数：%d", dataAccesser.dataCount);

}

void Runner::Show(const Worker& worker)
{
	printf("名前：%s", worker.name.c_str());
}
