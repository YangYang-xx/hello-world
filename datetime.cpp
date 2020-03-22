#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};
int main() {
  DateTime dt, dt1;
  std::cout << &dt << std::endl;
  std::cout << &dt1 << std::endl;
  dt.showTime();
  dt1.showTime();
  dt.showMoon();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  std::cout << this << " Go die, Ha~Ha~" << std::endl;
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
		printf("腊月%s\n",lunarday[sub_day]);
	}
	else if(month==1 && day>=25)
	{
		total=day;
		sub_day=day-24;
		printf("正月%s\n",lunarday[sub_day]);
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
		printf("%s月%s\n",lunarmonth[sub_month],lunarday[sub_day]);
	}
}
 
