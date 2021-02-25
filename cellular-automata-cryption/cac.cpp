#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#include <math.h>

#include "cac.h"

using namespace std;
namespace CAC
{
    void CACEnc::clear()
    {
        CACEnc::statusGraph.clear();
        for (int i = 0; i < sideLength; ++i)
        {
            vector<bool> subtemp;
            for (int j = 0; j < sideLength; ++j)
                subtemp.push_back(0);
            CACEnc::statusGraph.push_back(subtemp);
        }
        initialized = 0;
    }
    string charToBitString(char c)
    {
        int v=abs((int)c);
        string temp;
        while (v > 0)
        {
            temp += to_string(v % 2);
            v /= 2;
        }
        return temp;
    }
    void CACEnc::setString(string stream)
    {
        int mv = 0;
        for (auto i : stream)
        {
            map<char, string>::iterator iter = wordMap.find(i);
            string outputCode;
            if (iter != wordMap.end())
                outputCode = iter->second;
            else
                outputCode = charToBitString(i);
            for(int i=outputCode.length();i<sideLength;++i)outputCode="0"+outputCode;
            for (int j = 0; j < sideLength; ++j)
                CACEnc::statusGraph[mv % sideLength][j] = CACEnc::statusGraph[mv % sideLength][j] ^ (outputCode[j] - '0');
            mv++;
        }
        initialized = 1;
    }

    string CACEnc::print()
    {
        string cipherText;
        if (!initialized)
            return string("Uninitialized exception");
        for (int i = 0; i < sideLength; ++i)
        {
            string temp;
            for (int j = 0; j < sideLength; ++j)
                temp += to_string(CACEnc::statusGraph[i][j]);
            cipherText += alphabet[bitset<32>(temp).to_ulong() % alphabet.size()];
        }
        return cipherText;
    }

    void CACEnc::iterate()
    {
        vector<vector<bool>> temp;
        for (int i = 0; i < sideLength; ++i)
        {
            vector<bool> subtemp;
            for (int j = 0; j < sideLength; ++j)
                subtemp.push_back(0);
            temp.push_back(subtemp);
        }
        for (int t = 0; t < CACEnc::calcDepth; ++t)
        {
            for (int i = 0; i < sideLength; ++i)
            {
                for (int j = 0; j < sideLength; ++j)
                {
                    int aliveCount = 0;
                    if (j != 0)
                        aliveCount += CACEnc::statusGraph[i][j - 1];
                    if (j != sideLength-1)
                        aliveCount += CACEnc::statusGraph[i][j + 1];
                    if (i != 0)
                        aliveCount += CACEnc::statusGraph[i - 1][j];
                    if (i != sideLength-1)
                        aliveCount += CACEnc::statusGraph[i + 1][j];
                    if (i != 0 && j != 0)
                        aliveCount += CACEnc::statusGraph[i - 1][j - 1];
                    if (i != sideLength-1 && j != sideLength-1)
                        aliveCount += CACEnc::statusGraph[i + 1][j + 1];
                    if (i != 0 && j != sideLength-1)
                        aliveCount += CACEnc::statusGraph[i - 1][j + 1];
                    if (i != sideLength-1 && j != 0)
                        aliveCount += CACEnc::statusGraph[i + 1][j - 1];
                    temp[i][j] = (keyMap.find(aliveCount)->second == KeyMapStatus::KEEP ? CACEnc::statusGraph[i][j] : keyMap.find(aliveCount)->second);
                }
            }
            for (int i = 0; i < sideLength; ++i)
                for (int j = 0; j < sideLength; ++j)
                    CACEnc::statusGraph[i][j] = temp[i][j];
        }
    }
}
