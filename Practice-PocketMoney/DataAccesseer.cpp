//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccesser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <Windows.h>
#include <locale> 
#include <codecvt> 
#include <cstdio>
#include "CSVDataInfo.h"

using namespace std;

//
//コンストラクタ
//
DataAccesser::DataAccesser()
{
	//初期化
    this->workerArray_=NULL;
}

//
//デストラクタ
//
DataAccesser::~DataAccesser()
{
    delete[] this->workerArray_;
    this->workerArray_ = NULL;

}

//
//オブジェクトの配列を作るメソッド
//
bool DataAccesser::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    //返り値用の変数
    bool resultJudge = true;
    
    //string dirPath = "C:\\お小遣い練習_ShiftJis_";//コマンドラインから入力するようにあとで変更
    //string dirPath = "C:\\お小遣い練習_ShiftJis";
    string dirPath = "C:\\お小遣い練習_ShiftJis_";


    vector<string> filePaths(NULL);

    //vectorのfilePathsにパスが入るまでwhile分を抜けない
    while (filePaths.empty())
    {
        //cout << "フォルダパスを入力してください" << endl; 
        //cin >> dirPath ;

        //フォルダ内の全てのtxtファイルのパスを取得
        filePaths = SearchFiles(dirPath);
        if (filePaths.empty())
        {
            cout << "フォルダ内にファイルが存在しません." << endl;
            cout << "フォルダをもう一度入力してください" << endl;
        }
    }

    vector<string> fileData(NULL);
    
    //ファイルインスタンスを作成し、vectorでハンドリング。
    vector<CSVDataInfo*> CSVDataInfos(NULL);
    if (filePaths.empty())
    {
        resultJudge = false;
        
    }
    else
    {
        for (int i = 0; i < filePaths.size(); ++i)
        {
            CSVDataInfo* tmp = CSVDataInfo::ReadCSV(&filePaths[i]);
            CSVDataInfos.push_back(tmp);
        }
    }
    

    //TODO::ファイルインスタンスのメンバが正常かチェック。
    //TODO::異常なファイルインスタンスは削除し、vectorのインデックスをいじる


    //正常なファイルインスタンスからのみWorkerデータを作成
    for (int i = 0; i < CSVDataInfos.size(); ++i)
    {
        //FFGWorker tmp = CreatFFGWorker()
        //workerArray.push_back()

        int lineNum = CSVDataInfos[i]->lines.size();
        for (int j = 0; j < lineNum; ++j)
        {
            //vector<string> tmp = CSVDataInfos[i]->lines;
            ////tmp[j]
            //workerArray.push_back(CreatFFGWorker(tmp[j]));

            workerArray.push_back((CreatFFGWorker(CSVDataInfos[i]->lines)));

        }
       
    }


    return resultJudge;
}


//
//指定フォルダ内からtxtファイルを検索するメソッド。１要素に１ファイルのパスを含む
//
vector<string>DataAccesser::SearchFiles(string& dirPath)
{

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;

	vector<string> fileNames;   
	string extention = "txt";
     
	string searchName = dirPath + "\\*." + extention;


     hFind = FindFirstFile(searchName.c_str(), &win32fd);
     
     if (hFind == INVALID_HANDLE_VALUE)
     {
         //ログだけ出力して、空の配列を返す
         cout << "フォルダまたは、ファイルが存在しません" << endl;
     }
     else
     {
         do
         {
             fileNames.push_back(dirPath + "\\" + win32fd.cFileName);

         } while (FindNextFile(hFind, &win32fd));
     }

     FindClose(hFind);

     return fileNames;
}

//
//dataからFFGWorker1人分のインスタンスを作成するメソッド
//
FFGWorker* DataAccesser:: CreatFFGWorker(vector<string> strWorkerInfo)
{
    workerArray_ = new FFGWorker[strWorkerInfo.size()];
    vector<string> data(NULL);
    for (int i = 0; i < strWorkerInfo.size(); i++)
    {
        int p = 0;
        while ((p = strWorkerInfo[i].find(",")) != strWorkerInfo[i].npos)
        {
            data.push_back(strWorkerInfo[i].substr(0, p));//カンマ間をdataに格納

            strWorkerInfo[i] = strWorkerInfo[i].substr(p + 1);//カンマを削る
        }

        data.push_back(strWorkerInfo[i]);

    }

    workerArray_->iD          = data[0];
    workerArray_->name        = data[1];
    workerArray_->pocketMoney = atoi(data[2].c_str());

    return workerArray_;

}
