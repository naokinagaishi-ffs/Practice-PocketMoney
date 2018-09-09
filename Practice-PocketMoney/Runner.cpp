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
	Worker* pW;

	FFGWorker a("abc","122");

	pW = &a;

	a.Show();
	//printf(a.GetName);
}
