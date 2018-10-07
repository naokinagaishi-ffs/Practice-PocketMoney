//
//CSVDataInfoクラスの実装部
//

#include "stdafx.h"
#include "CSVDataInfo.h"
#include "ErrorManager.h"

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

