//
//CSVDataInfoクラスの宣言部
//
#pragma once
#ifndef CSVDATAINFO_
#define CSVDATAINFO_

#include <vector>
using namespace std;

class CSVDataInfo
{
public:
    //コンストラクタ
    CSVDataInfo();
    CSVDataInfo(string filePath, vector<string> lines);

    //デストラクタ
    ~CSVDataInfo();

    //メンバ
    vector<string> lines;
    string fileName;
    CSVDataInfo* dataInfo;

    //int lineNum;
    //ファイルからデータを取得するメソッド
    static CSVDataInfo* ReadCSV(string* filPpath);

private:
    


};



#endif // CSVDATAINFO_

