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
  string *temp_cal = &calendar;

  for (int d = 1; d <= num_days; d++)
  {
    // if it's today, turn day red
    if (d == CurrentDay) {
      *temp_cal += "\033[1;31m";
      *temp_cal += to_string(d);
      *temp_cal += " \033[0m";
    } else {
      if (d <= 7)
      {
        *temp_cal += " ";
      }
      *temp_cal += to_string(d);
      *temp_cal += " ";
    }

    // After 7 days, add a new line
    if (d % 7 == 0)
      *temp_cal += "\n";
  }

  calendar = *temp_cal;

  return calendar;
}

void GetCalendar(MonthData &NewMonth)
{
  string *temp_calendar = &NewMonth.Calendar;
  vector<int> TEM { 2 };
  vector<int> TDM { 4, 6, 9, 11 };
  vector<int> TODM { 1, 3, 5, 7, 8, 10, 12 };
  tm* now = localtime(&NewMonth.CurrentTime);
  int CurrentMonth { now->tm_mon + 1 };
  int CurrentDay { now->tm_mday};

  // Print Month and Year
  *temp_calendar += NewMonth.MonthsArray[CurrentMonth - 1];
  *temp_calendar += " ";
  *temp_calendar += to_string(now->tm_year + 1900);
  *temp_calendar += "\n";
  *temp_calendar += "----------------------\n";

  *temp_calendar += PrintWeekdays(NewMonth);
  *temp_calendar += "\n";

  // Determine how many days is in current month
  if (find(TODM.begin(), TODM.end(), CurrentMonth) != TODM.end())
  {
    // 31 Day Month
    FormatString(*temp_calendar, 31, CurrentDay);
    // 30 Day Month
  } else if (find(TDM.begin(), TDM.end(), CurrentMonth) != TDM.end()) {
    FormatString(*temp_calendar, 30, CurrentDay);
    // 28 Day Month
  } else {
    FormatString(*temp_calendar, 28, CurrentDay);
  }
}


int main(int argc, char *argv[])
{
  MonthData NewMonth;
  system("clear");
  cout << "current time: " << GetTime(NewMonth.CurrentTime) << endl;

  cout << "----------------------" << endl;

  GetCalendar(NewMonth);

  cout << NewMonth.Calendar << endl;

  cout << "----------------------" << endl;

  return 0;
}
