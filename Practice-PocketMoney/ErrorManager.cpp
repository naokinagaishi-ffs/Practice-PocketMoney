//
//ErrorManager�̎�����
//
#include "stdafx.h"
#include "ErrorManager.h"
#include <fstream>

static const string LOGFILEPATH = "PocketManyLog.txt";

ErrorManager::ErrorManager()
{
}

//
//�f�X�g���N�^
//
ErrorManager::~ErrorManager()
{

}

//
//�e�L�X�g�ɃG���[���b�Z�[�W���������ރN���X
//
void ErrorManager::WriteErrotTxt(string mesg)
{
    fstream file(LOGFILEPATH, ios_base::app);
    file << mesg.c_str();
    file.close();
}
//
//�t�@�C���𐶐�����N���X�B
//
void ErrorManager::CreatLogFile()
{
    ofstream outputfile(LOGFILEPATH);
    outputfile.close();
}