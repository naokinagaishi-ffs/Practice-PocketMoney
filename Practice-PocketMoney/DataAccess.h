//
//DataAccessクラスの宣言
//データアクセスに関する処理はこのクラスの責務
//
#pragma once
#ifndef DATAACCESS
#define DATAACCESS

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>



class DataAccess
{
public:
	//コンストラクタ
	DataAccess() ;

	//デストラクタ
	~DataAccess();

	//Worker型のデータ配列を作るメソッド
    vector<FFGWorker> CreatWorkerData();

private:
	//ファイルからデータを取得するメソッド
	vector<string> ReadCSV(string* filPpath);

	//指定フォルダ内の.txtファイルを検索するクラス
	vector<string> SearchFiles(string& dirPath);


public:
	//int dataCount;			//配列の数　=　人数
	FFGWorker* workerArray; //worker型のポインタ。動的配列に使う。	

};
#endif // !DATAACCESS
