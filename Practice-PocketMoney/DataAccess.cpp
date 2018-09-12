//DataAccessクラスの実装部

#include "stdafx.h"
#include "DataAccess.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



//コンストラクタ
DataAccess::DataAccess()
{
	//初期化
	workerArray = NULL;
}

////デストラクタ
DataAccess::~DataAccess(){}


//オブジェクトの配列を作るメソッド
vector<FFGWorker> DataAccess::CreatWorkerData()
{
    string filePath = "C:\\お小遣い練習\\ioSampleData.txt";

    vector<string> filedata = { "" };//初期化
    try
    {
        //ファイルIO処理。一行ずつ配列に保存
        filedata = ReadCSV(&filePath);
    }
    catch (exception ex)
    {
        //ファイル読めなかった時の処理(想定できない例外)
        cout << "ファイル読み込み時に、例外発生しました" << endl;
        //イベントログの出力

    }

    vector<FFGWorker> workerArray;

    for (int i = 0; i < filedata.size(); ++i)
    {
        vector<string> data;
        int p = 0;
        while ((p = filedata[i].find(",")) != filedata[i].npos)
        {
            data.push_back(filedata[i].substr(0, p));//カンマ間をdataに格納

            filedata[i] = filedata[i].substr(p + 1);//カンマを削る
        }

        data.push_back(filedata[i]);

        FFGWorker a;
        a.iD = data[0];//ID
        a.name = data[1];//名前
        a.pocketMoney = atoi(data[2].c_str());//お金

        workerArray.push_back(a);
    }

    return workerArray;
}
//CSVファイルを読むメソッド
vector<string> DataAccess::ReadCSV(string* filePath)
{

    std::ifstream ifs;  // ファイル読み取り用ストリーム
    ifs.open(*filePath);	// ファイルオープン

    if (ifs.fail()) {	// ファイルオープンに失敗したらそこで終了
        std::cerr << "ファイルを開けません\n";
        exit(1);
    }

    string buf;	// データ一時保管用配列

    int linenum = 0; // データの行数を数える

    // ファイルから1行ずつ読み込み、行数を求める
    while (getline(ifs, buf))
    {
        linenum++;	// 行数をカウントしている
    }

    std::cerr << "読み込んだ行数 = " << linenum << "\n";

    ifs.clear(); // ファイル末尾に到達というフラグをクリア
    ifs.seekg(0, std::ios::beg);	// ファイル先頭に戻る

    vector<string> lineArray(linenum);

    for (int i = 0; i < linenum; i++)
    {
        
        getline(ifs, lineArray[i]);
        
    }

    return lineArray;
}

