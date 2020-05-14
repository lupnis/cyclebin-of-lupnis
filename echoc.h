#ifndef _HEADER_ECHOC_
#define _HEADER_ECHOC_

//前景色
#define CSI                       "\x1B["    //控制符
#define CLEAR                     CSI "0m"   //恢复
#define UDLINE                    CSI "4m"   //下划线
#define FBSWAP                    CSI "7m"   //反色
#define BLACK_S                   CSI "0;30m"  
#define BLACK_BOLD_S              CSI "1;30m" 
#define RED_S                     CSI "0;31m"
#define RED_BOLD_S                CSI "1;31m"
#define GREEN_S                   CSI "0;32m"
#define GREEN_BOLD_S              CSI "1;32m"
#define YELLOW_S                  CSI "0;33m"
#define YELLOW_BOLD_S             CSI "1;33m"
#define BLUE_S                    CSI "0;34m"
#define BLUE_BOLD_S               CSI "1;34m"
#define MAGENTA_S                 CSI "0;35m"
#define MAGENTA_BOLD_S            CSI "1;35m"
#define CYAN_S                    CSI "0;36m"
#define CYAN_BOLD_S               CSI "1;36m"
#define WHITE_S                   CSI "0;37m"
#define WHITE_BOLD_S              CSI "1;37m"
#define BRIGHT_BLACK_S            CSI "0;90m"
//背景色
#define BLACK_BG_S                CSI "40m"
#define BLACK_BG_BOLD_S           CSI "40;1m"
#define RED_BG_S                  CSI "41m"
#define RED_BG_BOLD_S             CSI "41;1m"
#define GREEN_BG_S                CSI "42m"
#define GREEN_BG_BOLD_S           CSI "42;1m"
#define YELLOW_BG_S               CSI "43m"
#define YELLOW_BG_BOLD_S          CSI "43;1m"
#define BLUE_BG_S                 CSI "44m"
#define BLUE_BG_BOLD_S            CSI "44;1m"
#define MAGENTA_BG_S              CSI "45m"
#define MAGENTA_BG_BOLD_S         CSI "45;1m"
#define CYAN_BG_S                 CSI "46m"
#define CYAN_BG_BOLD_S            CSI "46;1m"
#define WHITE_BG_S                CSI "47m"
#define WHITE_BG_BOLD_S           CSI "47;1m"
#define BRIGHT_BLACK_BG_S         CSI "100m"
#define BRIGHT_BLACK_BG_BOLD_S    CSI "100;1m"
#define BRIGHT_RED_BG_S           CSI "101m"
#define BRIGHT_RED_BG_BOLD_S      CSI "101;1m"
#define BRIGHT_GREEN_BG_S         CSI "102m"
#define BRIGHT_GREEN_BG_BOLD_S    CSI "102;1m"
#define BRIGHT_YELLOW_BG_S        CSI "103m"
#define BRIGHT_YELLOW_BG_BOLD_S   CSI "103;1m"
#define BRIGHT_BLUE_BG_S          CSI "104m"
#define BRIGHT_BLUE_BG_BOLD_S     CSI "104;1m"
#define BRIGHT_MAGENTA_BG_S       CSI "105m"
#define BRIGHT_MAGENTA_BG_BOLD_S  CSI "105;1m"
#define BRIGHT_CYAN_BG_S          CSI "106m"
#define BRIGHT_CYAN_BG_BOLD_S     CSI "106;1m"
#define BRIGHT_WHITE_BG_S         CSI "107m"
#define BRIGHT_WHITE_BG_BOLD_S    CSI "107m"

//前景方法
#define BLACK(x)            BLACK_S x CLEAR
#define BLACK_BOLD(x)       BLACK_BOLD_S x CLEAR
#define RED(x)              RED_S x CLEAR
#define RED_BOLD(x)         RED_BOLD_S x CLEAR
#define GREEN(x)            GREEN_S x CLEAR
#define GREEN_BOLD(x)       GREEN_BOLD_S x CLEAR
#define YELLOW(x)           YELLOW_S x CLEAR
#define YELLOW_BOLD(x)      YELLOW_BOLD_S x CLEAR
#define BLUE(x)             BLUE_S x CLEAR
#define BLUE_BOLD(x)        BLUE_BOLD_S x CLEAR
#define MAGENTA(x)          MAGENTA_S x CLEAR
#define MAGENTA_BOLD(x)     MAGENTA_BOLD_S x CLEAR
#define CYAN(x)             CYAN_S x CLEAR
#define CYAN_BOLD(x)        CYAN_BOLD_S x CLEAR
#define WHITE(x)            WHITE_S x CLEAR
#define WHITE_BOLD(x)       WHITE_BOLD_S x CLEAR
#define BRIGHT_BLACK(x)     BRIGHT_BLACK_S x CLEAR
//背景方法
#define BLACK_BG(x)         BLACK_BG_S x CLEAR
#define BLACK_BG_BOLD(x)    BLACK_BG_BOLD_S x CLEAR
#define RED_BG(x)           RED_BG_S x CLEAR
#define RED_BG_BOLD(x)      RED_BG_BOLD_S x CLEAR
#define GREEN_BG(x)         GREEN_BG_S x CLEAR
#define GREEN_BG_BOLD(x)    GREEN_BG_BOLD_S x CLEAR
#define YELLOW_BG(x)        YELLOW_BG_S x CLEAR
#define YELLOW_BG_BOLD(x)   YELLOW_BG_BOLD_S x CLEAR
#define BLUE_BG(x)          BLUE_BG_S x CLEAR
#define BLUE_BG_BOLD(x)     BLUE_BG_BOLD_S x CLEAR
#define MAGENTA_BG(x)       MAGENTA_BG_S x CLEAR
#define MAGENTA_BG_BOLD(x)  MAGENTA_BG_BOLD_S x CLEAR
#define CYAN_BG(x)          CYAN_BG_S x CLEAR
#define CYAN_BG_BOLD(x)     CYAN_BG_BOLD_S x CLEAR
#define WHITE_BG(x)         WHITE_BG_S x CLEAR
#define WHITE_BG_BOLD(x)    WHITE_BG_BOLD_S x CLEAR
#define BRIGHT_BLACK_BG(x)         BRIGHT_BLACK_BG_S x CLEAR
#define BRIGHT_BLACK_BG_BOLD(x)    BRIGHT_BLACK_BG_BOLD_S x CLEAR
#define BRIGHT_RED_BG(x)           BRIGHT_RED_BG_S x CLEAR
#define BRIGHT_RED_BG_BOLD(x)      BRIGHT_RED_BG_BOLD_S x CLEAR
#define BRIGHT_GREEN_BG(x)         BRIGHT_GREEN_BG_S x CLEAR
#define BRIGHT_GREEN_BG_BOLD(x)    BRIGHT_GREEN_BG_BOLD_S x CLEAR
#define BRIGHT_YELLOW_BG(x)        BRIGHT_YELLOW_BG_S x CLEAR
#define BRIGHT_YELLOW_BG_BOLD(x)   BRIGHT_YELLOW_BG_BOLD_S x CLEAR
#define BRIGHT_BLUE_BG(x)          BRIGHT_BLUE_BG_S x CLEAR
#define BRIGHT_BLUE_BG_BOLD(x)     BRIGHT_BLUE_BG_BOLD_S x CLEAR
#define BRIGHT_MAGENTA_BG(x)       BRIGHT_MAGENTA_BG_S x CLEAR
#define BRIGHT_MAGENTA_BG_BOLD(x)  BRIGHT_MAGENTA_BG_BOLD_S x CLEAR
#define BRIGHT_CYAN_BG(x)          BRIGHT_CYAN_BG_S x CLEAR
#define BRIGHT_CYAN_BG_BOLD(x)     BRIGHT_CYAN_BG_BOLD_S x CLEAR
#define BRIGHT_WHITE_BG(x)         BRIGHT_WHITE_BG_S x CLEAR
#define BRIGHT_WHITE_BG_BOLD(x)    BRIGHT_WHITE_BG_BOLD_S x CLEAR

//#define Print(x,...) printf( xxx, ##__VA_ARGS__)
//#define Log  (x,...) printf(echoc::Printtime(), xxx, ##__VA_ARGS__)
namespace echoc{
	class echoc{	
	public:
	void print(const char* content,...);
	void log(const char* content,...);
	
	private:
	bool OpenANSIControlChar();
	void Printtime();
	void InStream(char* input);
	void Classifier(char* input);
	
	};
};
#endif