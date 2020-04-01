#include <iostream>
#include <time.h>
class DateTime {
private:
  int seconds;     //从1970年1月1日0时开始计算的秒数 
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};

int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt.showMoon(); 
  dt1.showTime();
  dt1.showMoon();
  dt2.showTime();
  dt2.showMoon();
  dt3.showTime();
  dt3.showMoon();
  dt4->showTime();
  dt4->showMoon();
  return 0;
}
DateTime::DateTime()
{
	time_t seconds=time(NULL);
	time_t timep;
    struct tm *p;
    p = localtime(&seconds); //取得系统时间
    year=1900+p->tm_year; month=1+p->tm_mon; day=p->tm_mday;
    hour=p->tm_hour; minute=p->tm_min; second=p->tm_sec;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
	year=y; month=m; day = d;
	this->hour=hour; this->minute=minute;this->second=second;
}
DateTime::DateTime(const DateTime &dt)
{
	year=dt.year; month=dt.month; day=dt.day;
	hour=dt.hour; minute=dt.minute; second=dt.second;
}
DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
	int i,j,k;
	char lunarmonth[][5]={"0","腊","正","二","三","四","闰四","五","六","七","八","九","十","十一"};
	char lunarday[][5]={"0","初一","初二","初三","初四","初五","初六","初七","初八","初九","初十",
	            "十一","十二","十三","十四","十五","十六","十七","十八","十九","二十",
				"廿一","廿二","廿三","廿四","廿五","廿六","廿七","廿八","廿九","三十"};
	int mon[13] ={ 0,31,29,31,30,31,30,31,31,30,31,30,31};//阳历1月到12月 
	int lunarmon[14]={ 0,30,29,30,30,30,29,30,29,29,30,29,30,29};//农历腊月到11月 
	int total=0,sub=0,sub_day=0,sub_month=1; 
	for(i=1;i<month;i++)
	{
		total=total+mon[i];
	}
	total=total+day;   //和1.1相差的天数   1.1腊月初七   比实际多1天 
	if(month==1 && day<25)
	{
		total=day-1;
        sub_day=total+7;
		printf("己亥年 腊月%s\n",lunarday[sub_day]);
	}
	else if(month==1 && day>=25)
	{
		total=day;
		sub_day=day-24;
		printf("庚子年 正月%s\n",lunarday[sub_day]);
	} 
	else if(month>1)
	{
		for(i=1;total>=lunarmon[i+1];i++)
		{
			total=total-lunarmon[i];
			sub_month++;
		}
		sub_day=total+7-1;
		if(sub_day>lunarmon[sub_month])
		{
			sub_day=sub_day-lunarmon[sub_month];
			sub_month=sub_month+1;
		}
		printf("庚子年 %s月%s\n",lunarmonth[sub_month],lunarday[sub_day]);
	}
} 

