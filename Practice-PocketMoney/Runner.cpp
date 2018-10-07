//Runnerクラスの実装
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "WorkerCreater.h"
#include "Calculater.h"
#include "ErrorManager.h"
#include <iostream>
using namespace std;

//コンストラクタ
Runner::Runner(){}

//デストラクタ
Runner::~Runner() {  }

void Runner::Run()
{

     ErrorManager::CreatLogFile();
     WorkerCreater workers;

	//Worker型のデータ配列を作成;
     vector<FFGWorker*> workerArray;
     workerArray = workers.CreatWorkerDataArray(workerArray);
	
	vector<int> moneyArray (workerArray.size());

     if (0 == moneyArray.size() )
     {
         cout << "データが一つもありません。" << endl;
     }
     else
     {
         for (int i = 0; i < workerArray.size(); ++i)
         {
             moneyArray[i] = workerArray[i]->pocketMoney;
         }

         printf("平均のお小遣いは %d円です\n", CalcAverage(moneyArray));

     }

}
