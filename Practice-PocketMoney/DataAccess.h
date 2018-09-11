#pragma once
#ifndef DATAACCESS
#define DATAACCESS

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>

//データにアクセスするクラスの宣言

class DataAccess
{
public:
	//コンストラクタ
	DataAccess() ;

	//デストラクタ
	~DataAccess();

	//Worker型のデータ配列を作るメソッド
	Worker* CreatWorkerData();

	//ファイルからデータを取得するメソッド
	vector<string> ReadCSV(string* filPpath);


public:
	int dataCount;			//配列の数　=　人数
	FFGWorker* workerArray; //worker型のポインタ。動的配列に使う。	

};
#endif // !DATAACCESS
