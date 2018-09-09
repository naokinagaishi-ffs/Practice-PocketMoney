#pragma once
#ifndef RUNNER_H
#define RUNNER_H

#include "Worker.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;

//Ruunerクラスの宣言
class Runner
{
public:
	Runner();	//　コンストラクタ
	~Runner();	//　デストラクタ

	//処理の実行
	void Run();
	
	void Show(const Worker& worker);

};
#endif // !RUNNER_H
