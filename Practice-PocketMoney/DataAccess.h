#pragma once
#ifndef DATAACCESS
#define DATAACCESS

#include "Worker.h"

//データにアクセスするクラスの宣言

class DataAccess
{
public:
	//コンストラクタ
	DataAccess(){}

	//デストラクタ
	~DataAccess(){}

	//ファイルからデータを取得するメソッド
	void CreatWorkerData();
	void ReadCSV(string filepath);


public:
	int dataCount;			//配列の数　=　人数
	FFGWorker* workerArray; //worker型のポインタ。動的配列に使う。	

};
#endif // !DATAACCESS
