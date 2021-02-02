#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>

#include "echoc.h"
using namespace std;
typedef std::uint64_t hash_t;
 
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;
 
hash_t hash_(char const* str)
{
hash_t ret{ basis };
while (*str) {
ret ^= *str;
ret *= prime;
str++;
} 
return ret;
} 
constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}
constexpr unsigned long long operator "" _hash(char const* p, size_t)
{
return hash_compile_time(p);
}

 bool OpenANSIControlChar()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return false; }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return false; }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) { return false; }
    return true;
}
void Printtime()
 {
	 SYSTEMTIME sys;
     GetLocalTime( &sys );
     printf("[%d-%02d-%02d %02d:%02d:%02d" BLACK_BOLD(".%03d") "]", 
             sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds);
 }
 void Printhelp()
 {
	 printf( "Thanks for using " MAGENTA_BG_BOLD("echoc") "\nHere are some useages of this program :)\n");
	 printf( "Version: " CYAN_BOLD("0.1.0/gcc\n"));
	 printf(RED_BG_BOLD(" ") CLEAR GREEN_BOLD(" - ") "operator:");
	 printf(
		 "\n" CYAN("-n") "           to begin another line"
		 "\n" CYAN("-b") "           to move forward a letter"
		 "\n" CYAN("-p") "           to add a space"
		 "\n" CYAN("-bp") "          to both back and space"
		 "\n" CYAN("-t") "           to print a time"
		 "\n" CYAN("-c") "           to clear color format"
		 "\n" CYAN("-sw") "          to show contrast color"
		 "\n" CYAN("-h or -help") "  to get help\n");
     printf(YELLOW_BG_BOLD(" ") CLEAR GREEN_BOLD(" $ ") "operator:");
	 printf(
	 "\nWord with a" GREEN_BOLD(" $ ") "operator means the specified words are colored.\nHere are the list of colors(Donnot forget to begin with $):"
     "\n" CLEAR        "CLEAR          " UDLINE               "LINE"         CLEAR
	 "\n" BLACK_S      "BLACK          " BLACK_BOLD_S         "BLACK_BOLD"   CLEAR
	 "\n" RED_S        "RED            " RED_BOLD_S           "RED_BOLD"     CLEAR
	 "\n" GREEN_S      "GREEN          " GREEN_BOLD_S         "GREEN_BOLD"   CLEAR
	 "\n" YELLOW_S     "YELLOW         " YELLOW_BOLD_S        "YELLOW_BOLD"  CLEAR
	 "\n" BLUE_S       "BLUE           " BLUE_BOLD_S          "BLUE_BOLD"    CLEAR
	 "\n" MAGENTA_S    "MAGENTA        " MAGENTA_BOLD_S       "MAGENTA_BOLD" CLEAR
	 "\n" CYAN_S       "CYAN           " CYAN_BOLD_S          "CYAN_BOLD"    CLEAR
	 "\n" WHITE_S      "WHITE          " WHITE_BOLD_S         "WHITE_BOLD"   CLEAR
	 "\nIt also has the background mode:"
     "\nFor example, Add _B after the color code like " GREEN_BG("$GREEN_B") " and " GREEN_BG_BOLD("$GREEN_BOLD_B")
	 "\n" GREEN_BOLD(" * ") "Notice: Add a BR_ between $ and background param color to use a brighter color"
	 "\nFor example, " BRIGHT_GREEN_BG_S"$BR_GREEN_B" CLEAR " has a higher brightness than the" GREEN_BG("$GREEN_B")
	 "\n");
	 printf(CYAN_BG_BOLD(" ") "BUG: I still haven't solved the problem that different texts can't be placed on colored background. Maybe the next version can be better.");
 }
 
 void Classifier(char* input,int type)
 {
	 if(type==0)
	 {
	   switch(hash_(input))
	   { 
		 case "-n"_hash:
		 cout<<endl;
		 break;	 
		 case "-b"_hash:
		 cout<<"\b";
		 break;		 
		 case "-p"_hash:
		 cout<<" ";
		 break;
		 case "-bp"_hash:
		 cout<<"\b"<<" ";
		 break;
		 case "-t"_hash:
		Printtime();
		break;
		case "-c"_hash:
		cout<<CLEAR;
		break;
		case "-sw"_hash:
		cout<<FBSWAP;
		break;
		case "-h"_hash:
		case "-help"_hash:
		Printhelp();
		break;
		 default:
		 printf(RED_BOLD("\n" "invalid param:") UDLINE "%s" CLEAR ,input);
		 break;
	   }
	 }
	 else if(type==1)
	 {
		
	 }
	 else if(type==2)
	 {
		 switch(hash_(input))
	   { 
	   case "$CLEAR"_hash:
	   cout<<CLEAR;
	   break;
	   case "$LINE"_hash:
	   cout<<UDLINE<<"";
	   break;
	   case "$BLACK"_hash:
	   cout<<BLACK_S;
	   break;
	   case "$BLACK_BOLD"_hash:
	   cout<<BLACK_BOLD_S;
	   break;
	   case "$RED"_hash:
	   cout<<RED_S;
	   break;
	   case "$RED_BOLD"_hash:
	   cout<<RED_BOLD_S;
	   break;
	   case "$GREEN"_hash:
	   cout<<GREEN_S;
	   break;
	   case "$GREEN_BOLD"_hash:
	   cout<<GREEN_BOLD_S;
	   break;
	   case "$YELLOW"_hash:
	   cout<<YELLOW_S;
	   break;
	   case "$YELLOW_BOLD"_hash:
	   cout<<YELLOW_BOLD_S;
	   break;
	   case "$BLUE"_hash:
	   cout<<BLUE_S;
	   break;
	   case "$BLUE_BOLD"_hash:
	   cout<<BLUE_BOLD_S;
	   break;
	   case "$MAGENTA"_hash:
	   cout<<MAGENTA_S;
	   break;
	   case "$MAGENTA_BOLD"_hash:
	   cout<<MAGENTA_BOLD_S;
	   break;
	   case "$CYAN"_hash:
	   cout<<CYAN_S;
	   break;
	   case "$CYAN_BOLD"_hash:
	   cout<<CYAN_BOLD_S;
	   break;
	   case "$WHITE"_hash:
	   cout<<WHITE_S;
	   break;
	   case "$WHITE_BOLD"_hash:
	   cout<<WHITE_BOLD_S;
	   break;
	   case "$BRIGHT_BLACK"_hash:
	   cout<<BRIGHT_BLACK_S;
	   break;
	   //鑳屾櫙鑹�
	   
	   case "$BLACK_B"_hash:
	   cout<<BLACK_BG_S;
	   break;
	   case "$BLACK_BOLD_B"_hash:
	   cout<<BLACK_BG_BOLD_S;
	   break;
	   case "$RED_B"_hash:
	   cout<<RED_BG_S;
	   break;
	   case "$RED_BOLD_B"_hash:
	   cout<<RED_BG_BOLD_S;
	   break;
	   case "$GREEN_B"_hash:
	   cout<<GREEN_BG_S;
	   break;
	   case "$GREEN_BOLD_B"_hash:
	   cout<<GREEN_BG_BOLD_S;
	   break;
	   case "$YELLOW_B"_hash:
	   cout<<YELLOW_BG_S;
	   break;
	   case "$YELLOW_BOLD_B"_hash:
	   cout<<YELLOW_BG_BOLD_S;
	   break;
	   case "$BLUE_B"_hash:
	   cout<<BLUE_BG_S;
	   break;
	   case "$BLUE_BOLD_B"_hash:
	   cout<<BLUE_BG_BOLD_S;
	   break;
	   case "$MAGENTA_B"_hash:
	   cout<<MAGENTA_BG_S;
	   break;
	   case "$MAGENTA_BOLD_B"_hash:
	   cout<<MAGENTA_BG_BOLD_S;
	   break;
	   case "$CYAN_B"_hash:
	   cout<<CYAN_BG_S;
	   break;
	   case "$CYAN_BOLD_B"_hash:
	   cout<<CYAN_BG_BOLD_S;
	   break;
	   case "$WHITE_B"_hash:
	   cout<<WHITE_BG_S;
	   break;
	   case "$WHITE_BOLD_B"_hash:
	   cout<<WHITE_BG_BOLD_S;
	   break;
	   
	   case "$BR_BLACK_B"_hash:
	   cout<<BRIGHT_BLACK_BG_S;
	   break;
	   case "$BR_BLACK_BOLD_B"_hash:
	   cout<<BRIGHT_BLACK_BG_BOLD_S;
	   break;
	   case "$BR_RED_B"_hash:
	   cout<<BRIGHT_RED_BG_S;
	   break;
	   case "$BR_RED_BOLD_B"_hash:
	   cout<<BRIGHT_RED_BG_BOLD_S;
	   break;
	   case "$BR_GREEN_B"_hash:
	   cout<<BRIGHT_GREEN_BG_S;
	   break;
	   case "$BR_GREEN_BOLD_B"_hash:
	   cout<<BRIGHT_GREEN_BG_BOLD_S;
	   break;
	   case "$BR_YELLOW_B"_hash:
	   cout<<BRIGHT_YELLOW_BG_S;
	   break;
	   case "$BR_YELLOW_BOLD_B"_hash:
	   cout<<BRIGHT_YELLOW_BG_BOLD_S;
	   break;
	   case "$BR_BLUE_B"_hash:
	   cout<<BRIGHT_BLUE_BG_S;
	   break;
	   case "$BR_BLUE_BOLD_B"_hash:
	   cout<<BRIGHT_BLUE_BG_BOLD_S;
	   break;
	   case "$BR_MAGENTA_B"_hash:
	   cout<<BRIGHT_MAGENTA_BG_S;
	   break;
	   case "$BR_MAGENTA_BOLD_B"_hash:
	   cout<<BRIGHT_MAGENTA_BG_BOLD_S;
	   break;
	   case "$BR_CYAN_B"_hash:
	   cout<<BRIGHT_CYAN_BG_S;
	   break;
	   case "$BR_CYAN_BOLD_B"_hash:
	   cout<<BRIGHT_CYAN_BG_BOLD_S;
	   break;
	   case "$BR_WHITE_B"_hash:
	   cout<<BRIGHT_WHITE_BG_S;
	   break;
	   case "$BR_WHITE_BOLD_B"_hash:
	   cout<<BRIGHT_WHITE_BG_BOLD_S;
	   break;   
	   default:
	   break;
	   }
	   
	 }
	 else{}
 }
 
 void InStream(char* input){	 
	 if(input[0]=='-'&&input[1]!='-')
		 Classifier(input,0);
	// else if(input[0]=='-'&&input[1]=='-')
	//	 Classifier(input,1);
	 else if(input[0]=='$')
		 Classifier(input,2);
	 else
		 cout<<input; 
 }
 
 
 

int main(int argc, char** argv){
	OpenANSIControlChar();
	for(int i=1;i<argc;i++){
	InStream(argv[i]);
	}
	return 0;
}
