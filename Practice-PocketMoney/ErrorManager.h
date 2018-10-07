//
//ErrorManagerクラスの宣言
//Error時のメッセージをログに書き込む。
//
//※※
//異常系が出るたびに、ファイルへアクセスするのは良くない。
//　→　シングルトンで、エラー情報をハンドリングし、最後にエラーを書き込むべき。
//      シングルトンを勉強してから、変更すること、、、、、

#pragma once
#ifndef ERROEMANAGER_
#define ERROEMANAGER_

#include "Runner.h"

using namespace std;
class ErrorManager
{
public:
    ErrorManager();
    ~ErrorManager();

    //
    //テキストにエラーメッセージを書き込むクラス
    //
    static void WriteErrotTxt(string mesg);
    
    //
    //ファイルを生成するクラス。作成する場所はCドライブ直下。
    //プログラムの一番最初に呼ばれる。
    //
    static void CreatLogFile();

};

#endif//ERROEMANAGER_
