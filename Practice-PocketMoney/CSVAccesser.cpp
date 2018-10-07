//
//CSVAccesserクラスの実装部
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <locale> 
#include <codecvt> 
#include <cstdio>
#include "ErrorManager.h"
#include "CSVAccesser.h"


//
//コンストラクタ
//
CSVAccesser::CSVAccesser()
{
}

//
//デストラクタ
//
CSVAccesser::~CSVAccesser()
{
}


//
//ファイルパスからインスタンスを生成して返すメソッド
//
CSVDataInfo* CSVAccesser::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);

    std::ifstream ifs;
    ifs.open(*filePath);

    if (ifs.fail())
    {
        string mesg = "ファイルを開けません。　";
        mesg += filePath->c_str();
        cout << mesg << endl;
        ErrorManager::WriteErrotTxt(mesg);
        ifs.close();
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

//
//指定フォルダ内からtxtファイルを検索するメソッド。
//戻り値のvectorには、１要素に１ファイルのパスを含む
//
vector<string>CSVAccesser::SearchFiles(string& dirPath)
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



