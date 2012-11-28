#ifndef _TIME_STRING_H_
#define _TIME_STRING_H_

#include <string>
#include <ctime>
#include <sstream>

class TimeString
{
public:

  enum TimeType {
    TIME_YEAR = 1,
    TIME_MON = 2,
    TIME_DAY = 4,
    TIME_HOUR = 5,
    TIME_MIN = 16, 
    TIME_SEC = 32
  };

  TimeString(void){}
  virtual ~TimeString(void){}

  ///<summary>åªç›éûä‘Çstd::stringå^Ç≈ï‘Ç∑</summary>
  static std::string NowTimeString(int timetype = TIME_YEAR + TIME_MON + TIME_DAY + TIME_HOUR + TIME_MIN + TIME_SEC){
    std::stringstream ss;
    std::time_t t = time(0);
    std::tm *x = localtime(&t);
    if(timetype & 1)  ss << x->tm_year + 1900; // TIME_YEAR
    if(timetype & 2)  ss << x->tm_mon + 1;     // TIME_MON
    if(timetype & 4)  ss << x->tm_mday;        // TIME_DAY
    if(timetype & 8)  ss << x->tm_hour;        // TIME_HOUR
    if(timetype & 16) ss << x->tm_min;         // TIME_MIN
    if(timetype & 32) ss << x->tm_sec;         // TIME_SEC
    return ss.str();
  }
	
};

#endif _TIME_STRING_H_