//
//CSVDataInfo�N���X�̐錾��
//�e�t�@�C���̏����C���X�^���X�Ńn���h�����O����
//�@���n���h�����O������
//      �E�t�@�C���p�X
//      �E��s���̕������vector�ŕێ�

#pragma once
#ifndef CSVDATAINFO_
#define CSVDATAINFO_

#include <vector>
using namespace std;

class CSVDataInfo
{
public:
    //
    //�R���X�g���N�^
    //
    CSVDataInfo();
    CSVDataInfo(string filePath, vector<string> lines);

    //
    //�f�X�g���N�^
    //
    ~CSVDataInfo();

    //
    //�����o�ϐ�
    //
    vector<string> lines;
    string fileName;

    //�t�@�C������f�[�^���擾���郁�\�b�h
    static CSVDataInfo* ReadCSV(string* filPpath);

};



#endif // CSVDATAINFO_

