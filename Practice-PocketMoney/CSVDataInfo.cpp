//
//CSVDataInfoクラスの実装部
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVDataInfo.h"
#include "ErrorManager.h"


//
//コンストラクタ
//
CSVDataInfo:: CSVDataInfo()
{
    this->lines.clear();
    this->lines.resize(0);
}

//
//コンストラクタ
//
CSVDataInfo::CSVDataInfo(string filePath, vector<string> lines) 
{
    this->fileName = filePath;
    
    for (int i = 0; i < lines.size(); ++i)
    {
        this->lines.push_back(lines[i]);
    }
}

//
//デストラクタ
//
CSVDataInfo::~CSVDataInfo()
{
    
    for (unsigned int i = 0; i < this->lines.size(); ++i)
    {
        if (NULL != this->lines[i].c_str())
        {
            delete this->lines[i].c_str();
            lines[i].c_str() == NULL;
        }
    }
}

//
//ファイルパスからインスタンスを生成して返すメソッド
//
CSVDataInfo* CSVDataInfo::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);
    
    std::ifstream ifs;  // ファイル読み取り用ストリーム
    ifs.open(*filePath);	// ファイルオープン


    if (ifs.fail())
    {
        string mesg =  "ファイルを開けません。　";
        mesg += filePath->c_str();
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        return false;
    }

    //一行ずつlineArrayに格納し、最終行まで読み込む。
    while (!ifs.eof())
    {
        string* tmpStr = new string[100];
        getline(ifs, *tmpStr);
        if (!tmpStr->empty())
        {
            lineArray.push_back(*tmpStr);
        }
    }

    return  new CSVDataInfo(*filePath, lineArray);

}

