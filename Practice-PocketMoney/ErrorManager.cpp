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
    file << mesg.c_str();//�Ȃ�Close����Ȃ��H�H
}
//
//�t�@�C���𐶐�����N���X�B�쐬����ꏊ��C�h���C�u�����B
//
void ErrorManager::CreatLogFile()
{
    ofstream outputfile(LOGFILEPATH);
    outputfile.close();
}