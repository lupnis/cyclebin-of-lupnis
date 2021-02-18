#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;

bool gmap[48][48]={false};
map<char,bitset<48>> wordmap;
map<int,int> keymap;
vector<char> alphabet;
void printMap(){
    cout<<"--------Status Map--------"<<endl;
    for(int i=0;i<48;++i){
        cout<<"Line "<<(i<10?"0"+to_string(i):to_string(i))<<" : ";
        for(int j=0;j<48;++j)cout<<gmap[i][j]<<" ";
        cout<<endl;
    }
    //TODO:Output the cipher text
    cout<<"--------------------------------"<<endl;
}
void initialMap(string stream){
    //cout<<stream.length()<<endl;
    int mv=0;
    for(auto i:stream){
        map<char,bitset<48>>::iterator iter=wordmap.find(i);
        string vv;
        if(iter!=wordmap.end())vv=(iter->second).to_string();
        else vv=bitset<48>(i).to_string();
        for(int j=0;j<48;++j)
            gmap[mv%48][j]^=(vv[j]-'0');
        mv++;
    }
    //printMap();
}
void calcnext(int steps){
    for(int k=0;k<steps;++k){
        bool tempmap[48][48];
        for(int i=0;i<48;++i){
            for(int j=0;j<48;++j){
                int livecount=0;
                if(j!=0)livecount+=gmap[i][j-1];
                if(j!=47)livecount+=gmap[i][j+1];
                if(i!=0)livecount+=gmap[i-1][j];
                if(i!=47)livecount+=gmap[i+1][j];
                if(i!=0&&j!=0)livecount+=gmap[i-1][j-1];
                if(i!=47&&j!=47)livecount+=gmap[i+1][j+1];
                if(i!=0&&j!=47)livecount+=gmap[i-1][j+1];
                if(i!=47&&j!=0)livecount+=gmap[i+1][j-1];
                tempmap[i][j]=(keymap.find(livecount)->second==-1?gmap[i][j]:keymap.find(livecount)->second);
            }
        }
        for(int i=0;i<48;++i)
            for(int j=0;j<48;++j)
                gmap[i][j]=tempmap[i][j];
    }
    //printMap();
}
void initmap(){
    wordmap.insert(pair<char,bitset<48>>('a',bitset<48>(string("010001101010110001001100010111001010000101001001"))));
    wordmap.insert(pair<char,bitset<48>>('b',bitset<48>(string("000000100001000000100001101110100100101110010111"))));
    wordmap.insert(pair<char,bitset<48>>('c',bitset<48>(string("010011101110100101111001110101011110011011111011"))));
    wordmap.insert(pair<char,bitset<48>>('d',bitset<48>(string("010001111101111010111011001001111111101111110001"))));
    wordmap.insert(pair<char,bitset<48>>('e',bitset<48>(string("100110111111011101000010100011000000101100001010"))));
    wordmap.insert(pair<char,bitset<48>>('f',bitset<48>(string("011000110001111000010101010000111010001011110000"))));
    wordmap.insert(pair<char,bitset<48>>('g',bitset<48>(string("111101111101101101001100011110011001010000010010"))));
    wordmap.insert(pair<char,bitset<48>>('h',bitset<48>(string("111010010011000011001100011010010010111110111011"))));
    wordmap.insert(pair<char,bitset<48>>('i',bitset<48>(string("100111110001011010001010110010110111011111011111"))));
    wordmap.insert(pair<char,bitset<48>>('j',bitset<48>(string("101000100111011000010111110100101110111001101111"))));
    wordmap.insert(pair<char,bitset<48>>('k',bitset<48>(string("001000101100110100000100000010101111001110110101"))));
    wordmap.insert(pair<char,bitset<48>>('l',bitset<48>(string("101001001110110100101011100010100110111000001110"))));
    wordmap.insert(pair<char,bitset<48>>('m',bitset<48>(string("111001100011010000001001000000010111001110010011"))));
    wordmap.insert(pair<char,bitset<48>>('n',bitset<48>(string("110100110010010101011110011001111011111111100010"))));
    wordmap.insert(pair<char,bitset<48>>('o',bitset<48>(string("110101100010010100011111011110111000110101110001"))));
    wordmap.insert(pair<char,bitset<48>>('p',bitset<48>(string("011011010011011010110001000111010000001111000110"))));
    wordmap.insert(pair<char,bitset<48>>('q',bitset<48>(string("011111100111000111000110000100011011100110010000"))));
    wordmap.insert(pair<char,bitset<48>>('r',bitset<48>(string("111011000100011100010101010001110110111001011111"))));
    wordmap.insert(pair<char,bitset<48>>('s',bitset<48>(string("010101010011111000110101011010010010010100000100"))));
    wordmap.insert(pair<char,bitset<48>>('t',bitset<48>(string("111111110100100111100000111100011011011001011000"))));
    wordmap.insert(pair<char,bitset<48>>('u',bitset<48>(string("110000000001101100001111100100001010010110011010"))));
    wordmap.insert(pair<char,bitset<48>>('v',bitset<48>(string("000000011101001101100011101100011111010001001110"))));
    wordmap.insert(pair<char,bitset<48>>('w',bitset<48>(string("100100001111000101000001111010110000101110000000"))));
    wordmap.insert(pair<char,bitset<48>>('x',bitset<48>(string("111010111100000100000010000011111101010001110010"))));
    wordmap.insert(pair<char,bitset<48>>('y',bitset<48>(string("111000000110100010000111010100100110001101110110"))));
    wordmap.insert(pair<char,bitset<48>>('z',bitset<48>(string("101110111001110000000011100010010000001110101110"))));
    wordmap.insert(pair<char,bitset<48>>('Q',bitset<48>(string("101011000111111100001110001110100111001101010101"))));
    wordmap.insert(pair<char,bitset<48>>('W',bitset<48>(string("101011111100011100001010010000100000111100101000"))));
    wordmap.insert(pair<char,bitset<48>>('E',bitset<48>(string("111001010111111111111111011011001110001000110101"))));
    wordmap.insert(pair<char,bitset<48>>('R',bitset<48>(string("000110110000110011001110111000100101101010111110"))));
    wordmap.insert(pair<char,bitset<48>>('T',bitset<48>(string("011101110000011111011000011010011000101100111000"))));
    wordmap.insert(pair<char,bitset<48>>('Y',bitset<48>(string("100100110110111101001111000011111011001000110001"))));
    wordmap.insert(pair<char,bitset<48>>('U',bitset<48>(string("011011101111101001010100000001101100111100110010"))));
    wordmap.insert(pair<char,bitset<48>>('I',bitset<48>(string("101001000111101110001100000110110010110110110001"))));
    wordmap.insert(pair<char,bitset<48>>('O',bitset<48>(string("110011111100100010000110110000010100110000001010"))));
    wordmap.insert(pair<char,bitset<48>>('P',bitset<48>(string("100101001010110011110100010001001101111110010110"))));
    wordmap.insert(pair<char,bitset<48>>('A',bitset<48>(string("110010100110111101010111011111010111001001111101"))));
    wordmap.insert(pair<char,bitset<48>>('S',bitset<48>(string("000010111001000111001101001101000111101011011100"))));
    wordmap.insert(pair<char,bitset<48>>('D',bitset<48>(string("100000100011000100011101010010010101101110101001"))));
    wordmap.insert(pair<char,bitset<48>>('F',bitset<48>(string("000011110000100010000101001111000000010110011110"))));
    wordmap.insert(pair<char,bitset<48>>('G',bitset<48>(string("100100010110101101101011001000101011110001001010"))));
    wordmap.insert(pair<char,bitset<48>>('H',bitset<48>(string("100010001001000100100110001000010011110100000100"))));
    wordmap.insert(pair<char,bitset<48>>('J',bitset<48>(string("111110000010110010101000111101011001010000010001"))));
    wordmap.insert(pair<char,bitset<48>>('K',bitset<48>(string("100110010010110000000110000110000001100110110000"))));
    wordmap.insert(pair<char,bitset<48>>('L',bitset<48>(string("111001101011000010000001100010000001000001001000"))));
    wordmap.insert(pair<char,bitset<48>>('Z',bitset<48>(string("000100001000011101101100011100100101110010110111"))));
    wordmap.insert(pair<char,bitset<48>>('X',bitset<48>(string("101000011111011000111011001000111101101100110011"))));
    wordmap.insert(pair<char,bitset<48>>('C',bitset<48>(string("101010101000110100000010010011010111100100001111"))));
    wordmap.insert(pair<char,bitset<48>>('V',bitset<48>(string("011111011010000111100000100100101110101001000000"))));
    wordmap.insert(pair<char,bitset<48>>('B',bitset<48>(string("001001000011011111011111001011010000101000000101"))));
    wordmap.insert(pair<char,bitset<48>>('N',bitset<48>(string("011001000100110000011010101011011110000010010100"))));
    wordmap.insert(pair<char,bitset<48>>('M',bitset<48>(string("011011101010110011010101110101011010001101101101"))));
    wordmap.insert(pair<char,bitset<48>>('0',bitset<48>(string("000001110101101001111100011011011111110001100010"))));
    wordmap.insert(pair<char,bitset<48>>('1',bitset<48>(string("001101011101010001010101110010001001000000010100"))));
    wordmap.insert(pair<char,bitset<48>>('2',bitset<48>(string("110001100101100000000100010011001111000001000000"))));
    wordmap.insert(pair<char,bitset<48>>('3',bitset<48>(string("001001000111010001000011001101100110001101000101"))));
    wordmap.insert(pair<char,bitset<48>>('4',bitset<48>(string("000001110111001100100011001001111010010000101110"))));
    wordmap.insert(pair<char,bitset<48>>('5',bitset<48>(string("001110010101001011010110110100001110001101011000"))));
    wordmap.insert(pair<char,bitset<48>>('6',bitset<48>(string("111001110010100011100111010111011000011010100001"))));
    wordmap.insert(pair<char,bitset<48>>('7',bitset<48>(string("010111111100101000111011000011000110110010010011"))));
    wordmap.insert(pair<char,bitset<48>>('8',bitset<48>(string("010101111110000100000001011110101000011010111010"))));
    wordmap.insert(pair<char,bitset<48>>('9',bitset<48>(string("111110000111011110001001011100010010100110001110"))));
    wordmap.insert(pair<char,bitset<48>>('`',bitset<48>(string("101011101101000110110111100111101101010001111111"))));
    wordmap.insert(pair<char,bitset<48>>('~',bitset<48>(string("110011001011000001101100010001111000010010001110"))));
    wordmap.insert(pair<char,bitset<48>>('!',bitset<48>(string("000111000101111101111010111111011010000000000001"))));
    wordmap.insert(pair<char,bitset<48>>('@',bitset<48>(string("101110010011011001100111101100001111011110011010"))));
    wordmap.insert(pair<char,bitset<48>>('#',bitset<48>(string("011111111111011000100000110100011100000110100100"))));
    wordmap.insert(pair<char,bitset<48>>('$',bitset<48>(string("000111100101001000001001011110011011101110000001"))));
    wordmap.insert(pair<char,bitset<48>>('%',bitset<48>(string("100011011011111001010001110111000011011100100000"))));
    wordmap.insert(pair<char,bitset<48>>('^',bitset<48>(string("000001101110010010100111000110110101000100111100"))));
    wordmap.insert(pair<char,bitset<48>>('&',bitset<48>(string("000111110010110110110010100110001010100111011100"))));
    wordmap.insert(pair<char,bitset<48>>('*',bitset<48>(string("110111000000010011111011101000100100101011011010"))));
    wordmap.insert(pair<char,bitset<48>>('(',bitset<48>(string("101111010110100010000010000111001001110011111101"))));
    wordmap.insert(pair<char,bitset<48>>(')',bitset<48>(string("110001000100110010111000000100011010110111111101"))));
    wordmap.insert(pair<char,bitset<48>>('-',bitset<48>(string("111100000111000010110100110111100110011100100101"))));
    wordmap.insert(pair<char,bitset<48>>('_',bitset<48>(string("000000010001010001000111101001111010001011011010"))));
    wordmap.insert(pair<char,bitset<48>>('=',bitset<48>(string("011001111011000000010100101110001010100001101010"))));
    wordmap.insert(pair<char,bitset<48>>('+',bitset<48>(string("111100001101001011100000110011100011011001001101"))));
    wordmap.insert(pair<char,bitset<48>>('[',bitset<48>(string("101101000111111010011010001111101110100110001001"))));
    wordmap.insert(pair<char,bitset<48>>('{',bitset<48>(string("100000011010110111011101011001101010011001010000"))));
    wordmap.insert(pair<char,bitset<48>>(']',bitset<48>(string("101110010011010111100111100001010010010100100100"))));
    wordmap.insert(pair<char,bitset<48>>('}',bitset<48>(string("111100001101110101111100001001010001010010111010"))));
    wordmap.insert(pair<char,bitset<48>>('\\',bitset<48>(string("001000101101100101010011110100000110110000011010"))));
    wordmap.insert(pair<char,bitset<48>>('|',bitset<48>(string("111110100110101000011100111110011111000001010110"))));
    wordmap.insert(pair<char,bitset<48>>(';',bitset<48>(string("011000001111110101000011010100111101101010101010"))));
    wordmap.insert(pair<char,bitset<48>>(':',bitset<48>(string("011001010001101111100001001010111100101110111010"))));
    wordmap.insert(pair<char,bitset<48>>('\'',bitset<48>(string("110101101011101101001100000100001011011010101100"))));
    wordmap.insert(pair<char,bitset<48>>('\"',bitset<48>(string("100111110000001110010011111001111001011000001001"))));
    wordmap.insert(pair<char,bitset<48>>(',',bitset<48>(string("110111011111100011001110100010011101000100111101"))));
    wordmap.insert(pair<char,bitset<48>>('<',bitset<48>(string("110000011000110010101001001011111010100110000111"))));
    wordmap.insert(pair<char,bitset<48>>('.',bitset<48>(string("100000001001110100110000001010011100101010000101"))));
    wordmap.insert(pair<char,bitset<48>>('>',bitset<48>(string("101111100001100100110001010101101101101111100100"))));
    wordmap.insert(pair<char,bitset<48>>('/',bitset<48>(string("001101000001001010000100011011001010011111100101"))));
    wordmap.insert(pair<char,bitset<48>>('?',bitset<48>(string("001010000011111000010110011101011011011000101101"))));
    wordmap.insert(pair<char,bitset<48>>('+',bitset<48>(string("001011000110000010100011010101100010011111011010"))));
    wordmap.insert(pair<char,bitset<48>>('-',bitset<48>(string("100011000101110010011100001111001100111101001100"))));
    wordmap.insert(pair<char,bitset<48>>('*',bitset<48>(string("001010110101101010010011101000111010110110010011"))));
    wordmap.insert(pair<char,bitset<48>>('/',bitset<48>(string("101111110111011110010101000011110101101100111111"))));
    wordmap.insert(pair<char,bitset<48>>(' ',bitset<48>(string("101000011101110101100001110010111010111100000100"))));

    keymap.insert(pair<int,bool>(0,0));
    keymap.insert(pair<int,bool>(1,0));
    keymap.insert(pair<int,bool>(2,-1));
    keymap.insert(pair<int,bool>(3,1));
    keymap.insert(pair<int,bool>(4,0));
    keymap.insert(pair<int,bool>(5,0));
    keymap.insert(pair<int,bool>(6,0));
    keymap.insert(pair<int,bool>(7,0));
    keymap.insert(pair<int,bool>(8,0));

    for(int i=0;i<26;i++)alphabet.push_back(i+'a');
    for(int i=0;i<26;i++)alphabet.push_back(i+'A');
    for(int i=0;i<10;i++)alphabet.push_back(i+'0');
    alphabet.push_back('#');
    alphabet.push_back('=');
}

void printCode(){
    string finalcode;
    for(int i=0;i<48;i++){
        string keycode;
        for(int j=0;j<48;j++){
            keycode+=to_string(gmap[i][j]);
        }
        finalcode+=alphabet[(abs((long)bitset<24>(keycode).to_ulong())%64)];
    }
    cout<<finalcode;
}
int main(){
    initmap();
    cout<<"Enter string:";
    string ii;
    cin>>ii;
    initialMap(ii);
    calcnext(64);
    cout<<"\x1B[32mCipher Text:\x1B[36m";
    printCode();
    cout<<"\x1B[0m";
    return 0;
}