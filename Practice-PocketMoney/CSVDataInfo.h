//
//CSVDataInfo�N���X�̐錾��
//
#pragma once
#ifndef CSVDATAINFO_
#define CSVDATAINFO_

#include <vector>
using namespace std;

class CSVDataInfo
{
public:
    //�R���X�g���N�^
    CSVDataInfo();
    CSVDataInfo(string filePath, vector<string> lines);

    //�f�X�g���N�^
    ~CSVDataInfo();

    //�����o
    vector<string> lines;
    string fileName;
    CSVDataInfo* dataInfo;

    //int lineNum;
    //�t�@�C������f�[�^���擾���郁�\�b�h
    static CSVDataInfo* ReadCSV(string* filPpath);

private:
    


};



#endif // CSVDATAINFO_

