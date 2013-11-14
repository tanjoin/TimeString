//
//  time_string.h
//  TimeString
//

#ifndef _TIME_STRING_H_
#define _TIME_STRING_H_

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

class TimeString
{
public:
  /// <summary> コンストラクタ・デストラクタ </summary>
  TimeString(void){}
  virtual ~TimeString(void){}

  /// <summary> 表示する日時を調整するためのフラグ </summary>
  typedef enum TimeType : unsigned int {
    TIME_YEAR    = 1,
    TIME_MON     = 2,
    TIME_DAY     = 4,
    TIME_HOUR    = 8,
    TIME_MIN     = 16,
    TIME_SEC     = 32,
    TIME_DEFAULT = 63
  } TimeType;

  /// <summary> 間に挟む文字列を数字を並べることで任意に設定するためのフラグ </summary>
  /// <remark> 先頭から[年^月^日^時^分^秒]  </remark>
  typedef enum TimeJoint : unsigned int {
    JOINT_NO        = 0,
    JOINT_HYPHEN    = 1,
    JOINT_UNDER_BAR = 2,
    JOINT_SPACE     = 3,
    JOINT_CORON     = 4,
    JOINT_SLASH     = 5,
    JOINT_TILDA     = 6,
    JOINT_DEFAULT   = 44355
  } TimeJoint;

  /// <summary> 曜日の日本語文字列リスト </summary>
  static const int day_of_week_count = 7;
  static const std::string day_of_week[];

  /// <summary> 現在時間をstd::string型で返す </summary>
  static std::string nowTimeString (const int timetype = TIME_DEFAULT,
                                    const int joint = JOINT_DEFAULT,
                                    const bool twodigits = true);
  
  /// <summary> joint_type から間に挟む記号を返す </summary>
  static std::string decideJoint (const int joint_type);
};

#endif // _TIME_STRING_H_
