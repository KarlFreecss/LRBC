#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int table[120][13][32];

int is_leap(int year){
  return year%400==0||(year%100!=0&&year%4==0);
}

void init(int x){
  int year = 2007, month = 1, day = 1, weekday = x;
  int mday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (year < 2101) {
    int cur_mday = mday[month-1];
    if (month == 2 && is_leap(year)) cur_mday++;
    if (day > cur_mday) {
      day = 1;
      ++month;
    }
    if (month > 12) {
      month = 1;
      ++year;
    }
    table[year % 2000][month][day] = weekday;
    ++day;
    weekday = (weekday+1)%7;
  }
}

struct myDate{
  int year, month, day, hour, minu, sec;
  myDate(int _y, int _m, int _d, int _h, int _mi, int _sec):
    year(_y), month(_m), day(_d), hour(_h), minu(_mi), sec(_sec){}

  bool operator < (const myDate & T) const {
    if (T.month != month) return month < T.month; 
    if (T.day != day) return day < T.day; 
    if (T.hour != hour) return hour < T.hour; 
    if (T.minu != minu) return minu < T.minu;
    return sec < T.sec;
  }

};

void work(){
  int year, month, day, hour, minu, sec;
  scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minu, &sec);
 // printf("%d %d %d %d %d %d\n", year, month, day, hour, minu, sec);
  int sunday_sum = 0;
  year %= 2000;
  int the_begin_day = 0;
  for (int i = 1; i <= 31; ++i) {
    if (table[year][3][i] == 0) sunday_sum++;
    if (sunday_sum == 2) {
      the_begin_day = i;
      break;
    }
  }
   
  myDate inputTime(year, month, day, hour, minu, sec);
  myDate firstTheBegin(year, 3, the_begin_day, 2, 0, 0);
  myDate firstTheEnd(year, 3, the_begin_day, 3, 0, 0);

  if (inputTime < firstTheBegin) {
    puts("PST");
    return ;
  }
  if (inputTime < firstTheEnd) {
    puts("Neither");
    return ;
  }

  sunday_sum = 0;
  year %= 2000;
  the_begin_day = 0;
  for (int i = 1; i <= 31; ++i) {
    if (table[year][3][i] == 0) sunday_sum++;
    if (sunday_sum == 1) {
      the_begin_day = i;
      break;
    }
  }

  myDate secondTheBegin(year, 11, the_begin_day, 1, 0, 0);
  myDate secondTheEnd(year, 11, the_begin_day, 2, 0, 0);

  if (inputTime < secondTheBegin) {
    puts("PDT");
    return ;
  }
  if (inputTime < secondTheEnd) {
    puts("Both");
    return ;
  }
  puts("PST");
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("l.in","r",stdin);
  //freopen("l.out","w",stdout);
#endif
  init(1);
 /* for (int i = 0; i < 7; i++) {
    init(i);
    cout << i << "  Today is : " << table[17][3][5] << endl;
  }*/

  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    printf("Case #%d: ", cas);
   work(); 
  }

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

