//Runner�N���X�̎���
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include "WorkerCreater.h"
#include "Calculater.h"
#include "ErrorManager.h"
#include <iostream>
using namespace std;

//�R���X�g���N�^
Runner::Runner(){}

//�f�X�g���N�^
Runner::~Runner() {  }

void Runner::Run()
{

     ErrorManager::CreatLogFile();
     WorkerCreater workers;

	//Worker�^�̃f�[�^�z����쐬;
     vector<FFGWorker*> workerArray;
     workerArray = workers.CreatWorkerDataArray(workerArray);
	
	vector<int> moneyArray (workerArray.size());

     if (0 == moneyArray.size() )
     {
         cout << "�f�[�^���������܂���B" << endl;
     }
     else
     {
         for (int i = 0; i < workerArray.size(); ++i)
         {
             moneyArray[i] = workerArray[i]->pocketMoney;
         }

         printf("���ς̂��������� %d�~�ł�\n", CalcAverage(moneyArray));

     }

}
