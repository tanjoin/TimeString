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
    TIME_HOUR = 8,
    TIME_MIN = 16, 
    TIME_SEC = 32,
    TIME_DEFAULT = 63
  };

  enum TimeJoint {
    JOINT_NO = 0,
    JOINT_HYPHEN = 1,
    JOINT_UNDER_BAR = 2,
    JOINT_SPACE = 3,
    JOINT_CORON = 4,
    JOINT_SLASH = 5,
    JOINT_TILDA = 6,
    JOINT_DEFAULT = 44355
  };

  TimeString(void){}
  virtual ~TimeString(void){}

  ///<summary>現在時間をstd::string型で返す</summary>
  static std::string NowTimeString (const int timetype = TIME_YEAR
                                                 + TIME_MON 
                                                 + TIME_DAY 
                                                 + TIME_HOUR 
                                                 + TIME_MIN 
                                                 + TIME_SEC,
                                    const int joint = JOINT_SLASH
                                              + JOINT_SLASH * 10
                                              + JOINT_SPACE * 100
                                              + JOINT_CORON * 1000
                                              + JOINT_CORON * 10000,
                                    const bool twodigits = true) {
    int tmp_joint = joint;
    std::stringstream ss;
    std::time_t t = time(0);
    std::tm *x = localtime(&t);
    if(timetype & 1)  ss << x->tm_year + 1900;                           // TIME_YEAR
    if(timetype == TIME_DEFAULT) {
      ss << DecideJoint(tmp_joint % 10);
      tmp_joint /= 10;
    }
    if(timetype & 2)  ss << DecideFixTime(x->tm_mon + 1, twodigits);     // TIME_MON
    if(timetype == TIME_DEFAULT) {
      ss << DecideJoint(tmp_joint % 10);
      tmp_joint /= 10;
    }
    if(timetype & 4)  ss << DecideFixTime(x->tm_mday, twodigits);        // TIME_DAY
    if(timetype == TIME_DEFAULT) {
      ss << DecideJoint(tmp_joint % 10);
      tmp_joint /= 10;
    }
    if(timetype & 8)  ss << DecideFixTime(x->tm_hour, twodigits);        // TIME_HOUR
    if(timetype == TIME_DEFAULT) {
      ss << DecideJoint(tmp_joint % 10);
      tmp_joint /= 10;
    }
    if(timetype & 16) ss << DecideFixTime(x->tm_min, twodigits);         // TIME_MIN
    if(timetype == TIME_DEFAULT) {
      ss << DecideJoint(tmp_joint % 10);
      tmp_joint /= 10;
    }
    if(timetype & 32) ss << DecideFixTime(x->tm_sec, twodigits);         // TIME_SEC
    return ss.str();
  }

  static std::string DecideFixTime (int time, bool twodigits) {
    if(twodigits){
      return FixTime(time);
    } else {
      std::stringstream ss;
      ss << time;
      return ss.str();
    }
  }
	
  static std::string FixTime (int time) {
    if (time < 10) {
      std::stringstream ss;
      ss << "0";
      ss << time;
      return ss.str();
    } else {
      std::stringstream ss;
      ss << time;
      return ss.str();
    }
  }

  static std::string DecideJoint (int joint_type) {
    if (joint_type == JOINT_NO)        return "";
    if (joint_type == JOINT_HYPHEN)    return "-";
    if (joint_type == JOINT_UNDER_BAR) return "_";
    if (joint_type == JOINT_SPACE)     return " ";
    if (joint_type == JOINT_CORON)     return ":";
    if (joint_type == JOINT_SLASH)     return "/";
    if (joint_type == JOINT_TILDA)     return "~";
  }
};

#endif _TIME_STRING_H_