//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccess.h"
#include "FFGWorker.h"
#include <iostream>
#include <fstream>
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
	//workerArray = new FFGWorker[2];//[1]で例外とぶのはなぜ？？
	//workerArray[0].name = "aaa";
	//workerArray[0].iD = "id01";
	//workerArray[0].pocketMoney = 1000;
	//workerArray[1].name = "bbb";
	//workerArray[1].iD = "id02";
	//workerArray[1].pocketMoney = 4000;

	//dataCount = sizeof(workerArray)/sizeof(workerArray[0]);//上手く行かない
	dataCount = 2;

	//string a = *filePath;
	std::ifstream ifs;  // ファイル読み取り用ストリーム
	ifs.open(*filePath);	// ファイルオープン

	if (ifs.fail()) {	// ファイルオープンに失敗したらそこで終了
		std::cerr << "ファイルを開けません\n";
		exit(1);
	}

	char buf[256];	// データ一時保管用配列

	int linenum = 0; // データの行数を数える

	while (ifs.getline(buf, sizeof(buf))) {	// ファイルから1行ずつ読み込む
		linenum++;	// 行数をカウントしている
	}

	std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	char* lineArray;
	lineArray = new char[linenum];	// 行数 linenum 分の配列を動的に確保

	for (int i = 0; i<linenum; i++) {
		ifs.getline(buf, sizeof(buf));	// 一行読み込んで…
		char* a = buf;
		lineArray[i] = *buf;// それを配列に格納
	}

	// これで、arr[0]～arr[linenum-1] に計 linenum 個のデータが格納された

}

