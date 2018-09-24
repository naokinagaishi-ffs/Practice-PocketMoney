//
//CSVDataInfoクラスの実装部
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVDataInfo.h"


//コンストラクタ
CSVDataInfo:: CSVDataInfo()
{

}
//コンストラクタ
CSVDataInfo::CSVDataInfo(string filePath, vector<string> lines) 
{
    this->fileName = filePath;
    this->lines = lines;
}

//デストラクタ
CSVDataInfo::~CSVDataInfo()
{
    delete []dataInfo;
    dataInfo = NULL;
}

CSVDataInfo* CSVDataInfo::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);

    std::ifstream ifs;  // ファイル読み取り用ストリーム
    ifs.open(*filePath);	// ファイルオープン

    
    if (ifs.fail())
    {
        // ファイルオープンに失敗したらそこで終了
        cout << "ファイルを開けません" << endl;

        //return lineArray; //警告だけ出して、NULLの配列を返す
    }

    while (!ifs.eof())
    {
        string tmpStr;
        getline(ifs, tmpStr);
        lineArray.push_back(tmpStr.c_str());
    }

    CSVDataInfo* dataInfo = new CSVDataInfo(*filePath, lineArray);

        return dataInfo;
}
