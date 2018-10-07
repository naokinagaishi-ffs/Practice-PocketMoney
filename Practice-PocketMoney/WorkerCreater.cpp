//DataAccessクラスの実装部

#include "stdafx.h"
#include "WorkerCreater.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include "CSVDataInfo.h"
#include "CSVAccesser.h"
#include "ErrorManager.h"
using namespace std;

//
//コンストラクタ
//
WorkerCreater::WorkerCreater()
{
	//初期化
    this->workerArray_=NULL;
}

//
//デストラクタ
//
WorkerCreater::~WorkerCreater()
{
    delete[] this->workerArray_;
    this->workerArray_ = NULL;

}

//
//オブジェクトの配列を作るメソッド
vector<FFGWorker*> WorkerCreater::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    string dirPath = "";
    vector<string> filePaths(NULL);
    cout << "フォルダパスを入力してください" << endl; 
    cin >> dirPath ;

    //フォルダ内の全てのtxtファイルのパスを取得
    filePaths = CSVAccesser::SearchFiles(dirPath);
    if (filePaths.empty())
    {
        string mesg = "フォルダまたはファイルが存在しません.\n";
        std::cout << mesg;
        ErrorManager::WriteErrotTxt(mesg);
        return vector<FFGWorker*>(NULL);
    }

    //ファイルインスタンスを作成し、vectorでハンドリング。
    vector<CSVDataInfo*> csvDataInfos(NULL);
    for (int i = 0; i < filePaths.size(); ++i)
    {
        csvDataInfos.push_back(CSVAccesser::ReadCSV(&filePaths[i]));
    }

    //FFGWorkerのインスタンスを生成
    for (int i = 0; i < csvDataInfos.size(); ++i)
    {
        vector<string> fileLines = csvDataInfos[i]->lines;
        for (int j = 0; j < fileLines.size(); ++j)
        {
            FFGWorker* tmpWorker = CreatFFGWorker(fileLines[j]);
            if (tmpWorker != NULL)
            {
                workerArray.push_back(tmpWorker);
            }
            else
            {
                string mesg = "不正データを含むファイルは" + csvDataInfos[i]->fileName + "　です\n";
                cout << mesg << endl;
                ErrorManager::WriteErrotTxt(mesg);
            }
        }

    }
    return workerArray;
}


//
//FFGWorker1人分のインスタンスを作成するメソッド
//
FFGWorker* WorkerCreater::CreatFFGWorker(string strWorkerInfo)
{
    workerArray_ = new FFGWorker[strWorkerInfo.size()];
    vector<string> data(NULL);
    data = Split(strWorkerInfo, ',');
    if (!CheckOneLine(data))
    {
        return NULL;
    }
    try
    {
        workerArray_->iD = data[0];
        workerArray_->name = data[1];
        workerArray_->pocketMoney = atoi(data[2].c_str());
    }
    catch (...)
    {
        return NULL;
    }

    return workerArray_;

}


//
//delimeter区切りで、文字列をvectorに保存して返すメソッド
//
vector<string> WorkerCreater::Split(const string& input, char delimiter)
{
    istringstream stream(input);

    string field;
    vector<string> result;
    while (getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}

//
//ファイル一行分のチェックを行うメソッド
//
bool WorkerCreater::CheckOneLine(vector<string> line)
{
    const int ELEMENTNUMBER = 3;
    string mesg = "";

    //要素数のチェック
    if (line.size() != ELEMENTNUMBER)
    {
        mesg = "データのフィールド数が不正です。データを除外しました。";
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        return false;
    }

    //データ内に欠損があるかのチェック
    for (int j = 0; j < ELEMENTNUMBER; ++j)
    {
        if (line[j].empty())
        {
            mesg = "データ中に空のフィールド数があります。データを除外しました。";
            cout << mesg << endl;
            ErrorManager::WriteErrotTxt(mesg);
            return false;
        }
    }

    //数値変換できるかのチェック
    if (!all_of(line[2].cbegin(), line[2].cend(), isdigit))
    {
        mesg = "お金を数値に変換できません。データを除外しました。";
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        return false;

    }

    return true;
}

