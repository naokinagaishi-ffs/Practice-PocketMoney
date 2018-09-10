//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccess.h"
#include "FFGWorker.h"
using namespace std;

//コンストラクタ
DataAccess::DataAccess()
{
	//初期化
	workerArray = NULL;
}

//デストラクタ
DataAccess::~DataAccess(){}

void DataAccess::CreatWorkerData()
{
	try
	{
		//ファイルIO処理
		ReadCSV("ファイルパスを入力");
		
	}
	catch (exception ex)
	{
		//ファイル読めなかった時の処理(想定できない例外)
		//cout << "ファイル読み込み時に、例外発生しました" << endl;
	}
	
}

void DataAccess::ReadCSV(string filepath)
{
	//仮実装
	workerArray = new FFGWorker[1];
	workerArray[0].name = "aaa";
	workerArray[0].iD = "id01";
	workerArray[0].name = "1000";
	workerArray[1].name = "bbb";
	workerArray[1].iD = "id02";
	workerArray[1].name = "4000";

	dataCount = sizeof(workerArray)/sizeof(workerArray[0]);

}

