//
//DataAccessクラスの宣言
//データアクセスに関する処理はこのクラスの責務
//
#pragma once
#ifndef DATAACCESSER
#define DATAACCESSER

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>



class DataAccesser
{
public:
     //
	//コンストラクタ
     //
	DataAccesser() ;


     //
	//デストラクタ
     //
	~DataAccesser();

#pragma region publicメソッド
     //
     //Worker型のデータ配列を作るメソッド
     //
     vector<FFGWorker> CreatWorkerDataArray();

#pragma endregion

#pragma region private メソッド
private:
    //ファイルからデータを取得するメソッド
    vector<string> ReadCSV(string* filPpath);

    //指定フォルダ内の.txtファイルを検索するクラス
    vector<string> SearchFiles(string& dirPath);

    //vector<string> => vector<FFGWorker>
    bool CreatFFGWorker(vector<string> strWorkerInfo, FFGWorker* worker);
#pragma endregion


#pragma region メンバ変数
private:

    //
    //配列の先頭ポインタ。FFGWorkerのインスタンスを保持
    //Getterのみ
    FFGWorker* workerArray_;

#pragma endregion

#pragma region Getter
public:
    //
    //FFGworker配列の先頭ポインタを返す
    //
    FFGWorker* WorekrArray() { return workerArray_; }

#pragma endregion



};
#endif // !DATAACCESS
