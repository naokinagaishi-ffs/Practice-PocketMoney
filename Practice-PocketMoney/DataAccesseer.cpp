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
vector<FFGWorker> DataAccesser::CreatWorkerDataArray()
{
    
    //string dirPath = "C:\\お小遣い練習_ShiftJis_";//コマンドラインから入力するようにあとで変更
    string dirPath = "C:\\お小遣い練習_ShiftJis";

    vector<string> filePaths(NULL);

    //vectorのfilePathsにパスが入るまでwhile分を抜けない
    while (filePaths.empty())
    {
        //cout << "フォルダパスを入力してください" << endl; 
        //cin >> dirPath ;

        //フォルダ内の全てのtxtファイルのパスを取得
        filePaths = SearchFiles(dirPath);

        cout << "フォルダ内にファイルが存在しません." << endl;
    }

    vector<string> fileData(NULL);
    
    ファイルごとにインスタンスを作成（メンバは行数と、一行ずつを格納したvector）
    ファイルインスタンスから、Workerのインスタンスを作成






    try
    {
        //一行ずつ配列に保存
        for (int i = 0; i < filePaths.size(); ++i)
        {
            fileData= ReadCSV(&filePaths[i]);

        }

    }
    catch (exception ex)
    {
        //CSVを読めなかった時の処理(想定できない例外)
        cout << "ファイル読み込み時に、例外発生しました" << endl;
        //TODO::イベントログテキストログの二つに出力
    }


    

    vector<FFGWorker> workerArray(NULL);


    return workerArray;
}

//
//CSVファイルを読むメソッド。１要素に１行を格納したvectorを返す
//
vector<string> DataAccesser::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);

    std::ifstream ifs;  // ファイル読み取り用ストリーム
    ifs.open(*filePath);	// ファイルオープン

    if (ifs.fail()) 
    {
        // ファイルオープンに失敗したらそこで終了
        cout << "ファイルを開けません" << endl;
        
        return lineArray; //警告だけ出して、NULLの配列を返す
    }

    while (!ifs.eof())
    {
        string tmpStr ;
        getline(ifs, tmpStr);
        lineArray.push_back(tmpStr.c_str());
    }
    return lineArray;
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
bool DataAccesser:: CreatFFGWorker(vector<string> strWorkerInfo, 
                                   FFGWorker* worker)
{
    
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

    worker->iD          = data[0];
    worker->name        = data[1];
    worker->pocketMoney = atoi(data[2].c_str());

    return worker;

}
