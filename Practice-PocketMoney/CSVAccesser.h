//
//CSVAccesser�N���X�̐錾��
//

#pragma once
#ifndef CSVACCEESSER_
#define CSVACCEESSER_
#include "CSVDataInfo.h"

class CSVAccesser
{
public:
    //
    //�R���X�g���N�^
    //
    CSVAccesser();

    //
    //�f�X�g���N�^
    //
    ~CSVAccesser();

    //
    //�t�@�C���p�X����C���X�^���X�𐶐����ĕԂ����\�b�h
    //
    static CSVDataInfo* ReadCSV(string* filPpath);

    //
    //�w��t�H���_������txt�t�@�C�����������郁�\�b�h�B�P�v�f�ɂP�t�@�C���̃p�X���܂�
    //
    static vector<string>SearchFiles(string& dirPath);

};


#endif // !CSVACCEESSER_

