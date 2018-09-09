//Runnerクラスの宣言
#include "stdafx.h"
#include "Runner.h"
#include "FFGWorker.h"
#include <iostream>
using namespace std;

//コンストラクタ
Runner::Runner(){}

//デストラクタ
Runner::~Runner() {  }

void Runner::Run()
{
	FFGWorker a("abc","122");

	Runner::Show(&a);
	
}

void Runner::Show(const Worker* worker)
{
	printf("名前：%s", worker->name);
}
