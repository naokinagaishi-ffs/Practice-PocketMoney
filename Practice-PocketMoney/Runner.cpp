//Runnerクラスの実装
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "DataAccesser.h"
#include "Calculater.h"
#include <iostream>
using namespace std;

//コンストラクタ
Runner::Runner(){}

//デストラクタ
Runner::~Runner() {  }

void Runner::Run()
{

	DataAccesser data;

	//Worker型のデータ配列を作成;
     vector<FFGWorker*> workerArray(NULL);
     data.CreatWorkerDataArray(workerArray);
	
	vector<int> pocketMoneyArray (workerArray.size());
	int a = pocketMoneyArray.size();
	for (int i = 0; i < workerArray.size() ; ++i)
	{
		pocketMoneyArray[i] = workerArray[i]->pocketMoney;
	}

	printf("平均のお小遣いは %d円です\n",CalcAverage(pocketMoneyArray));

}
