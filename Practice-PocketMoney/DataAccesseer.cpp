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
#include <cctype>
#include <algorithm>
#include "CSVDataInfo.h"
#include "ErrorManager.h"

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
vector<FFGWorker*> DataAccesser::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    //string dirPath = "C:\\お小遣い練習_ShiftJis_";//コマンドラインから入力するようにあとで変更
    string dirPath = "C:\\お小遣い練習_ShiftJis";
    //string dirPath = "C:\\お小遣練習_ShiftJis_";


    vector<string> filePaths(NULL);
    //cout << "フォルダパスを入力してください" << endl; 
    //cin >> dirPath ;

    //フォルダ内の全てのtxtファイルのパスを取得
    filePaths = SearchFiles(dirPath);
    if (filePaths.empty())
    {
        string mesg = "フォルダまたはファイルが存在しません.\n";
        cout << mesg;
        ErrorManager::WriteErrotTxt(mesg);
        return vector<FFGWorker*>();
    }


    //ファイルインスタンスを作成し、vectorでハンドリング。
    vector<CSVDataInfo*> csvDataInfos(NULL);
    for (int i = 0; i < filePaths.size(); ++i)
    {
        csvDataInfos.push_back(CSVDataInfo::ReadCSV(&filePaths[i]));
    }

    //正常なファイルインスタンスからのみWorkerデータを作成
    for (int i = 0; i < csvDataInfos.size(); ++i)
    {
        vector<string> tmpLines = csvDataInfos[i]->lines;
        if (CheckOneLine(tmpLines))
        {
            int lineNum = tmpLines.size();
            for (int j = 0; j < lineNum; ++j)
            {
                workerArray.push_back((CreatFFGWorker(tmpLines[j])));
            }
        }
        else
        {
            string mesg = csvDataInfos[i]->fileName + "が不正なファイルです\n";
            cout << mesg << endl;
            ErrorManager::WriteErrotTxt(mesg);
        }

    }

    return workerArray;
}


//
//指定フォルダ内からtxtファイルを検索するメソッド。１要素に１ファイルのパスを含む
//
vector<string>DataAccesser::SearchFiles(string& dirPath)
{

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;

	vector<string> fileNames(NULL);   
	string extention = "txt";
     
	string searchName = dirPath + "\\*." + extention;


     hFind = FindFirstFile(searchName.c_str(), &win32fd);
     
     if (hFind == INVALID_HANDLE_VALUE)
     {
         //ファイルパスがない場合は、何も処理しない。
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
FFGWorker* DataAccesser::CreatFFGWorker(string strWorkerInfo)
{
    vector<string> data(NULL);
    data = Split(strWorkerInfo, ',');
    workerArray_->iD = data[0];
    workerArray_->name = data[1];
    workerArray_->pocketMoney = atoi(data[2].c_str());

    return workerArray_;

}


//
//delimeter区切りで、文字列をvectorに保存して返すメソッド
//
vector<string> DataAccesser::Split(const string& input, char delimiter)
{
    istringstream stream(input);

    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

//
//ファイル一行分のチェックを行うメソッド
//
bool DataAccesser::CheckOneLine(vector<string> lines)
{
    const int ELEMENTNUMBER = 3;
    string mesg = "";

    for (int i = 0; i < lines.size(); ++i)
    {
        vector<string> oneLine = Split(lines[i], ',');

        //要素数のチェック
        if (oneLine.size() != ELEMENTNUMBER)
        {
            mesg = "データのフィールド数が不正です。";
            cout << mesg << endl;
            ErrorManager::WriteErrotTxt(mesg);
            return false;
        }

        //データ内に欠損があるかのチェック
        for (int j = 0; j < ELEMENTNUMBER; ++j)
        {
            if (oneLine[j].empty())
            {
                mesg = "データ中に空のフィールド数があります。";
                cout << mesg ;
                ErrorManager::WriteErrotTxt(mesg);
                return false;
            }
        }

        //数値変換できるかのチェック
        //if (!all_of(oneLine[2].cbegin(), oneLine[2].cend(), isdigit))
        //{
        //    mesg = "お金を数値に変換できません。";
        //    cout << mesg ;
        //    ErrorManager::WriteErrotTxt(mesg);
        //    return false;

        //}

    }

    return true;
}

