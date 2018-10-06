//
//ErrorManagerの実装部
//
#include "stdafx.h"
#include "ErrorManager.h"
#include <fstream>

static const string LOGFILEPATH = "PocketManyLog.txt";

ErrorManager::ErrorManager()
{
}

//
//デストラクタ
//
ErrorManager::~ErrorManager()
{

}

//
//テキストにエラーメッセージを書き込むクラス
//
void ErrorManager::WriteErrotTxt(string mesg)
{

    fstream file(LOGFILEPATH, ios_base::app);
    file << mesg.c_str();//なぜCloseいらない？？
}
//
//ファイルを生成するクラス。作成する場所はCドライブ直下。
//
void ErrorManager::CreatLogFile()
{
    ofstream outputfile(LOGFILEPATH);
    outputfile.close();
}