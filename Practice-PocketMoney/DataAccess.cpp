//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccess.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;

//コンストラクタ
DataAccess::DataAccess()
{
	//初期化
	workerArray = NULL;
}

////デストラクタ
DataAccess::~DataAccess(){}


//オブジェクトの配列を作るメソッド
void DataAccess::CreatWorkerData()
{
	string filePath = "C:\\Users\\naoki\\Desktop\\FFS\\新人研修補講\\IO\\ioSampleData.txt";

	try
	{
		//ファイルIO処理
	
		ReadCSV(&filePath);
		
	}
	catch (exception ex)
	{
		//ファイル読めなかった時の処理(想定できない例外)
		//cout << "ファイル読み込み時に、例外発生しました" << endl;
	}
	
}

//CSVファイルを読むメソッド
void DataAccess::ReadCSV(string* filePath)
{
	//仮実装
	workerArray = new FFGWorker[2];//[1]で例外とぶのはなぜ？？
	workerArray[0].name = "aaa";
	workerArray[0].iD = "id01";
	workerArray[0].pocketMoney = 1000;
	workerArray[1].name = "bbb";
	workerArray[1].iD = "id02";
	workerArray[1].pocketMoney = 4000;

	//dataCount = sizeof(workerArray)/sizeof(workerArray[0]);//上手く行かない
	dataCount = 2;

	//string a = *filePath;

}

