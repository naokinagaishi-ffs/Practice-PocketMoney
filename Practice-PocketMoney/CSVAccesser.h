//
//CSVAccesserクラスの宣言部
//

#pragma once
#ifndef CSVACCEESSER_
#define CSVACCEESSER_
#include "CSVDataInfo.h"

class CSVAccesser
{
public:
    //
    //コンストラクタ
    //
    CSVAccesser();

    //
    //デストラクタ
    //
    ~CSVAccesser();

    //
    //ファイルパスからインスタンスを生成して返すメソッド
    //
    static CSVDataInfo* ReadCSV(string* filPpath);

    //
    //指定フォルダ内からtxtファイルを検索するメソッド。１要素に１ファイルのパスを含む
    //
    static vector<string>SearchFiles(string& dirPath);

};


#endif // !CSVACCEESSER_

