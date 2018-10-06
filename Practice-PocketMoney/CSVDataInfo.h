//
//CSVDataInfoクラスの宣言部
//各ファイルの情報をインスタンスでハンドリングする
//　＜ハンドリングする情報＞
//      ・ファイルパス
//      ・一行ずつの文字列をvectorで保持

#pragma once
#ifndef CSVDATAINFO_
#define CSVDATAINFO_

#include <vector>
using namespace std;

class CSVDataInfo
{
public:
    //
    //コンストラクタ
    //
    CSVDataInfo();
    CSVDataInfo(string filePath, vector<string> lines);

    //
    //デストラクタ
    //
    ~CSVDataInfo();

    //
    //メンバ変数
    //
    vector<string> lines;
    string fileName;

    //ファイルからデータを取得するメソッド
    static CSVDataInfo* ReadCSV(string* filPpath);

};



#endif // CSVDATAINFO_

