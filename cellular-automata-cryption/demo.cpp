#include <iostream>
#include <map>
#include <vector>
#include <bitset>

#include "cac.h"

using namespace std;
using namespace CAC;

map<char, string> _48map;
map<int, CACEnc::KeyMapStatus> _48key;
vector<char> _48alphabet;

void initGraph()
{
    _48map.insert(pair<char, string>('a', (string("010001101010110001001100010111001010000101001001"))));
    _48map.insert(pair<char, string>('b', (string("000000100001000000100001101110100100101110010111"))));
    _48map.insert(pair<char, string>('c', (string("010011101110100101111001110101011110011011111011"))));
    _48map.insert(pair<char, string>('d', (string("010001111101111010111011001001111111101111110001"))));
    _48map.insert(pair<char, string>('e', (string("100110111111011101000010100011000000101100001010"))));
    _48map.insert(pair<char, string>('f', (string("011000110001111000010101010000111010001011110000"))));
    _48map.insert(pair<char, string>('g', (string("111101111101101101001100011110011001010000010010"))));
    _48map.insert(pair<char, string>('h', (string("111010010011000011001100011010010010111110111011"))));
    _48map.insert(pair<char, string>('i', (string("100111110001011010001010110010110111011111011111"))));
    _48map.insert(pair<char, string>('j', (string("101000100111011000010111110100101110111001101111"))));
    _48map.insert(pair<char, string>('k', (string("001000101100110100000100000010101111001110110101"))));
    _48map.insert(pair<char, string>('l', (string("101001001110110100101011100010100110111000001110"))));
    _48map.insert(pair<char, string>('m', (string("111001100011010000001001000000010111001110010011"))));
    _48map.insert(pair<char, string>('n', (string("110100110010010101011110011001111011111111100010"))));
    _48map.insert(pair<char, string>('o', (string("110101100010010100011111011110111000110101110001"))));
    _48map.insert(pair<char, string>('p', (string("011011010011011010110001000111010000001111000110"))));
    _48map.insert(pair<char, string>('q', (string("011111100111000111000110000100011011100110010000"))));
    _48map.insert(pair<char, string>('r', (string("111011000100011100010101010001110110111001011111"))));
    _48map.insert(pair<char, string>('s', (string("010101010011111000110101011010010010010100000100"))));
    _48map.insert(pair<char, string>('t', (string("111111110100100111100000111100011011011001011000"))));
    _48map.insert(pair<char, string>('u', (string("110000000001101100001111100100001010010110011010"))));
    _48map.insert(pair<char, string>('v', (string("000000011101001101100011101100011111010001001110"))));
    _48map.insert(pair<char, string>('w', (string("100100001111000101000001111010110000101110000000"))));
    _48map.insert(pair<char, string>('x', (string("111010111100000100000010000011111101010001110010"))));
    _48map.insert(pair<char, string>('y', (string("111000000110100010000111010100100110001101110110"))));
    _48map.insert(pair<char, string>('z', (string("101110111001110000000011100010010000001110101110"))));
    _48map.insert(pair<char, string>('Q', (string("101011000111111100001110001110100111001101010101"))));
    _48map.insert(pair<char, string>('W', (string("101011111100011100001010010000100000111100101000"))));
    _48map.insert(pair<char, string>('E', (string("111001010111111111111111011011001110001000110101"))));
    _48map.insert(pair<char, string>('R', (string("000110110000110011001110111000100101101010111110"))));
    _48map.insert(pair<char, string>('T', (string("011101110000011111011000011010011000101100111000"))));
    _48map.insert(pair<char, string>('Y', (string("100100110110111101001111000011111011001000110001"))));
    _48map.insert(pair<char, string>('U', (string("011011101111101001010100000001101100111100110010"))));
    _48map.insert(pair<char, string>('I', (string("101001000111101110001100000110110010110110110001"))));
    _48map.insert(pair<char, string>('O', (string("110011111100100010000110110000010100110000001010"))));
    _48map.insert(pair<char, string>('P', (string("100101001010110011110100010001001101111110010110"))));
    _48map.insert(pair<char, string>('A', (string("110010100110111101010111011111010111001001111101"))));
    _48map.insert(pair<char, string>('S', (string("000010111001000111001101001101000111101011011100"))));
    _48map.insert(pair<char, string>('D', (string("100000100011000100011101010010010101101110101001"))));
    _48map.insert(pair<char, string>('F', (string("000011110000100010000101001111000000010110011110"))));
    _48map.insert(pair<char, string>('G', (string("100100010110101101101011001000101011110001001010"))));
    _48map.insert(pair<char, string>('H', (string("100010001001000100100110001000010011110100000100"))));
    _48map.insert(pair<char, string>('J', (string("111110000010110010101000111101011001010000010001"))));
    _48map.insert(pair<char, string>('K', (string("100110010010110000000110000110000001100110110000"))));
    _48map.insert(pair<char, string>('L', (string("111001101011000010000001100010000001000001001000"))));
    _48map.insert(pair<char, string>('Z', (string("000100001000011101101100011100100101110010110111"))));
    _48map.insert(pair<char, string>('X', (string("101000011111011000111011001000111101101100110011"))));
    _48map.insert(pair<char, string>('C', (string("101010101000110100000010010011010111100100001111"))));
    _48map.insert(pair<char, string>('V', (string("011111011010000111100000100100101110101001000000"))));
    _48map.insert(pair<char, string>('B', (string("001001000011011111011111001011010000101000000101"))));
    _48map.insert(pair<char, string>('N', (string("011001000100110000011010101011011110000010010100"))));
    _48map.insert(pair<char, string>('M', (string("011011101010110011010101110101011010001101101101"))));
    _48map.insert(pair<char, string>('0', (string("000001110101101001111100011011011111110001100010"))));
    _48map.insert(pair<char, string>('1', (string("001101011101010001010101110010001001000000010100"))));
    _48map.insert(pair<char, string>('2', (string("110001100101100000000100010011001111000001000000"))));
    _48map.insert(pair<char, string>('3', (string("001001000111010001000011001101100110001101000101"))));
    _48map.insert(pair<char, string>('4', (string("000001110111001100100011001001111010010000101110"))));
    _48map.insert(pair<char, string>('5', (string("001110010101001011010110110100001110001101011000"))));
    _48map.insert(pair<char, string>('6', (string("111001110010100011100111010111011000011010100001"))));
    _48map.insert(pair<char, string>('7', (string("010111111100101000111011000011000110110010010011"))));
    _48map.insert(pair<char, string>('8', (string("010101111110000100000001011110101000011010111010"))));
    _48map.insert(pair<char, string>('9', (string("111110000111011110001001011100010010100110001110"))));
    _48map.insert(pair<char, string>('`', (string("101011101101000110110111100111101101010001111111"))));
    _48map.insert(pair<char, string>('~', (string("110011001011000001101100010001111000010010001110"))));
    _48map.insert(pair<char, string>('!', (string("000111000101111101111010111111011010000000000001"))));
    _48map.insert(pair<char, string>('@', (string("101110010011011001100111101100001111011110011010"))));
    _48map.insert(pair<char, string>('#', (string("011111111111011000100000110100011100000110100100"))));
    _48map.insert(pair<char, string>('$', (string("000111100101001000001001011110011011101110000001"))));
    _48map.insert(pair<char, string>('%', (string("100011011011111001010001110111000011011100100000"))));
    _48map.insert(pair<char, string>('^', (string("000001101110010010100111000110110101000100111100"))));
    _48map.insert(pair<char, string>('&', (string("000111110010110110110010100110001010100111011100"))));
    _48map.insert(pair<char, string>('*', (string("110111000000010011111011101000100100101011011010"))));
    _48map.insert(pair<char, string>('(', (string("101111010110100010000010000111001001110011111101"))));
    _48map.insert(pair<char, string>(')', (string("110001000100110010111000000100011010110111111101"))));
    _48map.insert(pair<char, string>('-', (string("111100000111000010110100110111100110011100100101"))));
    _48map.insert(pair<char, string>('_', (string("000000010001010001000111101001111010001011011010"))));
    _48map.insert(pair<char, string>('=', (string("011001111011000000010100101110001010100001101010"))));
    _48map.insert(pair<char, string>('+', (string("111100001101001011100000110011100011011001001101"))));
    _48map.insert(pair<char, string>('[', (string("101101000111111010011010001111101110100110001001"))));
    _48map.insert(pair<char, string>('{', (string("100000011010110111011101011001101010011001010000"))));
    _48map.insert(pair<char, string>(']', (string("101110010011010111100111100001010010010100100100"))));
    _48map.insert(pair<char, string>('}', (string("111100001101110101111100001001010001010010111010"))));
    _48map.insert(pair<char, string>('\\', (string("001000101101100101010011110100000110110000011010"))));
    _48map.insert(pair<char, string>('|', (string("111110100110101000011100111110011111000001010110"))));
    _48map.insert(pair<char, string>(';', (string("011000001111110101000011010100111101101010101010"))));
    _48map.insert(pair<char, string>(':', (string("011001010001101111100001001010111100101110111010"))));
    _48map.insert(pair<char, string>('\'', (string("110101101011101101001100000100001011011010101100"))));
    _48map.insert(pair<char, string>('\"', (string("100111110000001110010011111001111001011000001001"))));
    _48map.insert(pair<char, string>(',', (string("110111011111100011001110100010011101000100111101"))));
    _48map.insert(pair<char, string>('<', (string("110000011000110010101001001011111010100110000111"))));
    _48map.insert(pair<char, string>('.', (string("100000001001110100110000001010011100101010000101"))));
    _48map.insert(pair<char, string>('>', (string("101111100001100100110001010101101101101111100100"))));
    _48map.insert(pair<char, string>('/', (string("001101000001001010000100011011001010011111100101"))));
    _48map.insert(pair<char, string>('?', (string("001010000011111000010110011101011011011000101101"))));
    _48map.insert(pair<char, string>('+', (string("001011000110000010100011010101100010011111011010"))));
    _48map.insert(pair<char, string>('-', (string("100011000101110010011100001111001100111101001100"))));
    _48map.insert(pair<char, string>('*', (string("001010110101101010010011101000111010110110010011"))));
    _48map.insert(pair<char, string>('/', (string("101111110111011110010101000011110101101100111111"))));
    _48map.insert(pair<char, string>(' ', (string("101000011101110101100001110010111010111100000100"))));

    _48key.insert(pair<int, CACEnc::KeyMapStatus>(0, CACEnc::DEAD));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(1, CACEnc::ALIVE));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(2, CACEnc::KEEP));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(3, CACEnc::ALIVE));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(4, CACEnc::DEAD));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(5, CACEnc::DEAD));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(6, CACEnc::DEAD));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(7, CACEnc::DEAD));
    _48key.insert(pair<int, CACEnc::KeyMapStatus>(8, CACEnc::DEAD));

    for (int i = 0; i < 26; i++)
        _48alphabet.push_back(i + 'a');
    for (int i = 0; i < 26; i++)
        _48alphabet.push_back(i + 'A');
    for (int i = 0; i < 10; i++)
        _48alphabet.push_back(i + '0');
    _48alphabet.push_back('#');
    _48alphabet.push_back('=');
}
int main()
{
    initGraph();
    CACEnc _48CAC(64, 48, _48alphabet, _48key, _48map);
    cout<<_48CAC.print()<<endl;

    cout<<"------------------------"<<endl;
    _48CAC.clear();
   cout<<"Enter string:";
    string ii;
    cin>>ii;
    _48CAC.setString(ii);
    _48CAC.iterate();
    cout<<_48CAC.print()<<endl;
    return 0;
}