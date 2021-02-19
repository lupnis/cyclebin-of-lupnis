#ifndef CACENC_H
#define CACENC_H

#include<iostream>
#include<map>
#include<vector>

using namespace std;

namespace CAC{
    class CACEnc{
    public:
        enum KeyMapStatus:int{
            KEEP=-1,
            DEAD=0,
            ALIVE=1,
        };
        CACEnc(
            unsigned short _calcDepth,
            unsigned int _sideLength,
            vector<char> _alphabet,
            map<int,KeyMapStatus> _keyMap,
            map<char,string> _wordMap){
                sideLength=_sideLength;calcDepth=_calcDepth;
                alphabet=_alphabet;keyMap=_keyMap;wordMap=_wordMap;
                initialized=false;
        }
        string print(void);                      //Return the encrypted text as the string format
        void iterate(void);                 //Run the iteration operation that based on CAC
        void setString(string stream);    //Set the text to be encrypted and initialize the graph
        void clear(void);                 //Reset the statusGraph to the blank status
    private:
        unsigned short calcDepth;                //The controller indicates times of iteration
        unsigned int sideLength;               //The controller indicates side length of the graph
        bool initialized;                        //A verbose to prevent wrong operations
        vector<vector<bool>> statusGraph;        //The status of the graph is stored here
        vector<char> alphabet;                   //The dictionary used to print out text after encryption
        map<int,KeyMapStatus> keyMap;            //Key pairs stored here to decide the next status of the graph
        map<char,string> wordMap;                //the string of bitset can be stored here to generate the graph
    };
}

#endif // !CACENC_H
