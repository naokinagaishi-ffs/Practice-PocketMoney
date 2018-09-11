//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccess.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
Worker* DataAccess::CreatWorkerData()
{
	string filePath = "C:\\Users\\naoki\\Desktop\\FFS\\新人研修補講\\IO\\ioSampleData.txt";

	try
	{
		//ファイルIO処理
		string* filedata = ReadCSV(&filePath);

		//int workerNum = sizeof(filedata) / sizeof(filedata[0]);

		string a = filedata[2];
		
	}
	catch (exception ex)
	{
		//ファイル読めなかった時の処理(想定できない例外)
		//cout << "ファイル読み込み時に、例外発生しました" << endl;
	}

	Worker* rmp = NULL;
	return rmp;
	
}

//CSVファイルを読むメソッド
string* DataAccess::ReadCSV(string* filePath)
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

	string buf;	// データ一時保管用配列

	int linenum = 0; // データの行数を数える

	// ファイルから1行ずつ読み込み、行数を求める
	while (getline(ifs,buf))
	{	
		linenum++;	// 行数をカウントしている
		cout << buf.c_str() << endl;
		string a = buf;
		
	}

	std::cerr << "読み込んだ行数 = " << linenum << "\n";

	ifs.clear(); // ファイル末尾に到達というフラグをクリア
	ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

	string* lineArray;
	lineArray = new string[linenum];	// 行数 linenum 分の配列を動的に確保

	for (int i = 0; i<linenum; i++) 
	{
		string tmp;
		getline(ifs, tmp);
		lineArray[i] = tmp;
	}

	return lineArray;
}

