//
//  time_string.cc
//  TimeString
//

#include "time_string.h"

const std::string TimeString::day_of_week[] = {
  "月", "火", "水", "木", "金", "土", "日"
};

std::string TimeString::nowTimeString (const int timetype,
                                       const int joint,
                                       const bool twodigits) {
  int tmp_joint = joint;
  std::stringstream output;
  std::time_t timer = time(0);
  std::tm *now_time = localtime(&timer);
  // leading-zeros
  // TIME_YEAR
  if(timetype & 1) {
    output << now_time->tm_year + 1900;
  }
  if(timetype == TIME_DEFAULT) {
    output << decideJoint(tmp_joint % 10);
    tmp_joint /= 10;
  }
  // TIME_MON
  if(timetype & 2) {
    if (twodigits) {
      output << std::setw(2) << std::setfill('0');
    }
    output << now_time->tm_mon + 1;
  }
  if(timetype == TIME_DEFAULT) {
    output << decideJoint(tmp_joint % 10);
    tmp_joint /= 10;
  }
  // TIME_DAY
  if(timetype & 4) {
    if (twodigits) {
      output << std::setw(2) << std::setfill('0');
    }
    output << now_time->tm_mday;
  }
  if(timetype == TIME_DEFAULT) {
    output << decideJoint(tmp_joint % 10);
    tmp_joint /= 10;
  }
  // TIME_HOUR
  if(timetype & 8) {
    if (twodigits) {
      output << std::setw(2) << std::setfill('0');
    }
    output << now_time->tm_hour;
  }
  if(timetype == TIME_DEFAULT) {
    output << decideJoint(tmp_joint % 10);
    tmp_joint /= 10;
  }
  // TIME_MIN
  if(timetype & 16) {
    if (twodigits) {
      output << std::setw(2) << std::setfill('0');
    }
    output << now_time->tm_min;
  }
  if(timetype == TIME_DEFAULT) {
    output << decideJoint(tmp_joint % 10);
    tmp_joint /= 10;
  }
  // TIME_SEC
  if(timetype & 32) {
    if (twodigits) {
      output << std::setw(2) << std::setfill('0');
    }
    output << now_time->tm_sec;
  }
  return output.str();
}

std::string TimeString::decideJoint(const int joint_type) {
  switch (joint_type) {
    case JOINT_HYPHEN:
      return "-";
    case JOINT_UNDER_BAR:
      return "_";
    case JOINT_SPACE:
      return " ";
    case JOINT_CORON:
      return ":";
    case JOINT_SLASH:
      return "/";
    case JOINT_TILDA:
      return "~";
    case JOINT_NO:
    default:
      return "";
  }
}
