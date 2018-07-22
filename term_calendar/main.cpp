#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct MonthData
{
  time_t CurrentTime { time(0) };
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
  int CurrentMonth { now->tm_mon };

  for (int d = 0; d < TODM.size(); d++)
  {
    if()
  }

  return to_string(CurrentMonth);
}


int main(int argc, char *argv[])
{
  MonthData NewMonth;
  system("clear");
  cout << "current time: " << GetTime(NewMonth.CurrentTime) << endl;

  cout << "----------------------" << endl;

  cout << GetCalendar(NewMonth) << endl;

  return 0;
}
