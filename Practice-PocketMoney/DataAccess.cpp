//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccess.h"
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


//コンストラクタ
DataAccess::DataAccess()
{
	//初期化
	workerArray = NULL;
}

////デストラクタ
DataAccess::~DataAccess(){}

//
//オブジェクトの配列を作るメソッド
//
vector<FFGWorker> DataAccess::CreatWorkerData()
{
    //string dirPath = "C:\\お小遣い練習_";
    string dirPath = "C:\\お小遣い練習_ShiftJis";


    //string dirPath = "C:\\test11";



    vector<string> filePaths  ;//初期化
    vector<string> fileData ;
    try
    {
        //フォルダ内の全てのtxtファイルのパスを取得
        filePaths = SearchFiles(dirPath);

    }
    catch (exception ex)
    {
        //ファイル読めなかった時の処理(想定できない例外)
        cout << "ファイル読み込み時に、例外発生しました" << endl;
        //TODO::イベントログテキストログの二つに出力
    }


    //一行ずつ配列に保存
    for (int i = 0; i < filePaths.size(); ++i)
    {
        
        fileData = ReadCSV(&filePaths[i]);
    }


    vector<FFGWorker> workerArray;

    //for (int i = 0; i < filedata.size(); ++i)
    //{
    //    vector<string> data;
    //    int p = 0;
    //    while ((p = filedata[i].find(",")) != filedata[i].npos)
    //    {
    //        data.push_back(filedata[i].substr(0, p));//カンマ間をdataに格納

    //        filedata[i] = filedata[i].substr(p + 1);//カンマを削る
    //    }

    //    data.push_back(filedata[i]);

    //    FFGWorker tmpWorker ;
    //    tmpWorker.iD = data[0];//ID
    //    tmpWorker.name = data[1];//名前
    //    tmpWorker.pocketMoney = atoi(data[2].c_str());//お金

    //    workerArray.push_back(tmpWorker);
    //}

    return workerArray;
}

//
//CSVファイルを読むメソッド
//
vector<string> DataAccess::ReadCSV(string* filePath)
{

    std::ifstream ifs;  // ファイル読み取り用ストリーム
    ifs.open(*filePath);	// ファイルオープン

    if (ifs.fail()) {	// ファイルオープンに失敗したらそこで終了
        std::cerr << "ファイルを開けません\n";
        
        vector<string> empty(0); 
        return empty; //警告だけ出して、空の配列を返す
    }

    string buf;	// データ一時保管用配列

    int linenum = 0; // データの行数を数える

    // ファイルから1行ずつ読み込み、行数を求める
    while (getline(ifs, buf))
    {
        linenum++;	
    }

    ifs.clear(); // ファイル末尾に到達というフラグをクリア
    ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

    vector<string> lineArray(linenum);

    for (int i = 0; i < linenum; i++)
    {
        getline(ifs, lineArray[i]);
    }

    return lineArray;
}

//
//指定フォルダ内からtxtファイルを検索するメソッド
//
vector<string>DataAccess::SearchFiles(string& dirPath)
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