#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;   //˽�в��ɷ��� 
public:
  DateTime();        //���캯�� 
  DateTime(int y, int m, int day, int hour, int minute, int second);//���غ��� 
  DateTime(const DateTime &dt);//�������� 
  ~DateTime();       //�������� 
  void showTime();   //����ֻ�ܷ��ʹ��г�Ա 
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};
int main() {
  DateTime dt, dt1(2020,3,27,10,40,55);   //dt�޲�   dt1�вι��� 
  DateTime dt2(dt), &dt3=dt;  //���� 
  DateTime *dt4=&dt; 
  dt.showTime();
  dt1.showTime();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  dt.showMoon();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
}
DateTime::DateTime(int y, int m, int day, int hour, int minute, int second)  //��������  thisָ��ֱ�����뺯���β� 
{
	year=y; month=m; this->day = day;
	this->hour=hour; this->minute=minute;this->second=second;
}
DateTime::DateTime(const DateTime &dt)
{
	year=dt.year; month=dt.month; day=dt.day;
	hour=dt.hour; minute=dt.minute; second=dt.second;
}
DateTime::~DateTime() 
{
  std::cout << this << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
	int i,j,k;
	char lunarmonth[][5]={"0","��","��","��","��","��","����","��","��","��","��","��","ʮ","ʮһ"};
	char lunarday[][5]={"0","��һ","����","����","����","����","����","����","����","����","��ʮ",
	            "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
				"إһ","إ��","إ��","إ��","إ��","إ��","إ��","إ��","إ��","��ʮ"};
	int mon[13] ={ 0,31,29,31,30,31,30,31,31,30,31,30,31};//����1�µ�12�� 
	int lunarmon[14]={ 0,30,29,30,30,30,29,30,29,29,30,29,30,29};//ũ�����µ�11�� 
	int total=0,sub=0,sub_day=0,sub_month=1; 
	for(i=1;i<month;i++)
	{
		total=total+mon[i];
	}
	total=total+day;   //��1.1��������   1.1���³���   ��ʵ�ʶ�1�� 
	if(month==1 && day<25)
	{
		total=day-1;
        sub_day=total+7;
		printf("����%s\n",lunarday[sub_day]);
	}
	else if(month==1 && day>=25)
	{
		total=day;
		sub_day=day-24;
		printf("����%s\n",lunarday[sub_day]);
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
		printf("%s��%s\n",lunarmonth[sub_month],lunarday[sub_day]);
	}
}

//����  ����  ʹ�� 
//���� ָ�� ���� 
 
