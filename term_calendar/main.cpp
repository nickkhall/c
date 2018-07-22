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

string GetCalendar(MonthData &NewMonth)
{
  string calendar { "" };
  vector<int> TEM { 2 };
  vector<int> TDM { 4, 6, 9, 11 };
  vector<int> TODM { 1, 3, 5, 7, 8, 10, 12 };
  tm* now = localtime(&NewMonth.CurrentTime);
  int CurrentMonth { now->tm_mon + 1 };
  int CurrentDay { now->tm_mday};

  if (find(TODM.begin(), TODM.end(), CurrentMonth) != TODM.end())
  {
    // Print Month and Year
    calendar += NewMonth.MonthsArray[CurrentMonth - 1];
    calendar += " ";
    calendar += to_string(now->tm_year + 1900);
    calendar += "\n";
    calendar += "----------------------\n";

    // Determine how many days is in current month
    // 31 Day Month
    for (int d = 1; d <= 31; d++)
    {
      // if it's today, turn day red
      if (d == CurrentDay) {
        calendar += "\033[1;31m ";
        calendar += to_string(d);
        calendar += " \033[0m";
      } else {
        calendar += to_string(d);
        calendar += " ";
      }

      // After 7 days, add a new line
      if (d % 7 == 0)
        calendar += "\n";
    }
    // 30 Day Month
  } else if (find(TDM.begin(), TDM.end(), CurrentMonth) != TDM.end()) {
    for (int d = 1; d <= 30; d++)
    {
      calendar += to_string(d) += " ";
      if (d % 7 == 0) {
        calendar += "\n";
      }
    }
    // 28 Day Month
  } else {
    for (int d = 1; d <= 28; d++)
    {
      calendar += to_string(d) += " ";
      if (d % 7 == 0) {
        calendar += "\n";
      }
    }
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
