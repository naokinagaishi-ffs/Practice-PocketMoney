//
//DataAccessクラスの宣言
//データアクセスに関する処理はこのクラスの責務
//
#pragma once
#ifndef WORKERCREATER_
#define WORKERCREATER_

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>

class WorkerCreater
{
public:
     //
	//コンストラクタ
     //
    WorkerCreater() ;


     //
	//デストラクタ
     //
	~WorkerCreater();

#pragma region publicメソッド
     //
     //Worker型のデータ配列を作るメソッド
     //
     vector<FFGWorker*>  CreatWorkerDataArray(vector<FFGWorker*> workerArray);

#pragma endregion

#pragma region private メソッド
private:
    //
    //指定フォルダ内の.txtファイルを検索するメソッド
    //
    vector<string> SearchFiles(string& dirPath);

    //
    //文字列からFFGWorkerのインスタンスを作成するメソッド
    //
    FFGWorker*  CreatFFGWorker(string strWorkerInfo);

    //
    //delimeter区切りで、文字列をvectorに保存して返すメソッド
    //
    vector<string> Split(const std::string& input, char delimiter);

    //
    //ファイル一行分のチェックを行うメソッド
    //
    bool CheckOneLine(vector<string> lineData);


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
#endif // !WORKERCREATER_
