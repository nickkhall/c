#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct MonthData
{
  time_t CurrentTime { time(0) };
  vector<string> MonthsArray { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  vector<string> WeekdayArray { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
  string Calendar { "" };
  // 20
};

string GetTime(time_t &CurrentTime)
{
  tm* now = localtime(&CurrentTime);
  string TimeString { "" };

  TimeString += to_string(now->tm_hour);
  TimeString += ":";
  TimeString += to_string(now->tm_min);
  TimeString += ":";
  TimeString += to_string(now->tm_sec);

  return TimeString;
}

string PrintWeekdays(MonthData &NewMonth)
{
  string Weekdays { "" };

  for (int i = 0; i < 7; i++)
  {
    Weekdays += NewMonth.WeekdayArray.at(i);
    if (i != 7)
    {
      Weekdays += " ";
    }
  }

  return Weekdays;
}

string FormatString(string &calendar, int num_days, int CurrentDay)
{
  string formatted_string { "" };

  cout << *calendar << endl;

  // for (int d = 1; d <= num_days; d++)
  // {
  //   // if it's today, turn day red
  //   if (d == CurrentDay) {
  //     *calendar += "\033[1;31m";
  //     *calendar += to_string(d);
  //     *calendar += " \033[0m";
  //   } else {
  //     if (d <= 7)
  //     {
  //       *calendar += " ";
  //     }
  //     *calendar += to_string(d);
  //     *calendar += " ";
  //   }
  //
  //   // After 7 days, add a new line
  //   if (d % 7 == 0)
  //     *calendar += "\n";
  // }

  return formatted_string;
}

string GetCalendar(MonthData &NewMonth)
{
  string *temp_calendar = &NewMonth.Calendar;
  vector<int> TEM { 2 };
  vector<int> TDM { 4, 6, 9, 11 };
  vector<int> TODM { 1, 3, 5, 7, 8, 10, 12 };
  tm* now = localtime(&NewMonth.CurrentTime);
  int CurrentMonth { now->tm_mon + 1 };
  int CurrentDay { now->tm_mday};

  // Print Month and Year
  calendar += NewMonth.MonthsArray[CurrentMonth - 1];
  calendar += " ";
  calendar += to_string(now->tm_year + 1900);
  calendar += "\n";
  calendar += "----------------------\n";

  calendar += PrintWeekdays(NewMonth);
  calendar += "\n";

  // Determine how many days is in current month
  if (find(TODM.begin(), TODM.end(), CurrentMonth) != TODM.end())
  {
    // 31 Day Month
    FormatString(calendar, 31, CurrentDay);
    // 30 Day Month
  } else if (find(TDM.begin(), TDM.end(), CurrentMonth) != TDM.end()) {
    FormatString(calendar, 30, CurrentDay)
    // 28 Day Month
  } else {
    FormatString(calendar, 28, CurrentDay);
  }

  return calendar;
}


int main(int argc, char *argv[])
{
  MonthData NewMonth;
  system("clear");
  cout << "current time: " << GetTime(NewMonth.CurrentTime) << endl;

  cout << "----------------------" << endl;

  cout << GetCalendar(NewMonth) << endl;

  cout << "----------------------" << endl;

  return 0;
}
