//Workerクラスの実装
#include "stdafx.h"
#include "Worker.h"


//コンストラクタ
Worker::Worker() {};
Worker::Worker(string name_) 
{
	Worker::SetName(name_);
};

//デストラクタ
Worker::~Worker(){}


