//
//Runnerクラスの宣言
//
#pragma once
#ifndef RUNNER_H
#define RUNNER_H

#include "Worker.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;

class Runner
{
public:
	Runner();	//　コンストラクタ
	~Runner();	//　デストラクタ

	//処理の実行
	void Run();
	

};
#endif // !RUNNER_H
