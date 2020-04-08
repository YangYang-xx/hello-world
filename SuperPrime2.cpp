//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class SuperPrime {
  public:
  	int number;
  	SuperPrime():number(0) {
	}
  	~SuperPrime() {	
	}
  	bool isSuperPrime() {
  	  split();
  	  int a = sum();
	  int b = multi();
	  int c = squareSum();
	  if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c)){
	  	return true;
	  }
	  else{
	  	return false;
	  }
	}
  private:
  	int N[4], size;        
  	//const int number; 
  	bool isPrime(int n) {
	  int result=0; 
  	  for(int c=2;c<n;c++)
  	  {
  	  	if(n%c == 0)
  	  	{
  	  		result++;
		}
	  }
	  if(result==0)
	  {
	  	return true;
	  }
	  else
	  {
	  	return false;
	  }
	}
	void split() {  
	  N[0]=number/100;
	  N[1]=(number-N[0]*100)/10;
	  N[2]=number%10;
	  // number split into N
	}
	int sum() {
	  int sum=0;
	  for(int i=0;i<3;i++)
	  {
	  	sum += N[i];
	  }
	  return sum;
	}
	int multi() {
	  int multi=1;
	  for(int i=0;i<3;i++)
	  {
	  	multi *= N[i];
	  }
	  return multi;
	}
	int squareSum() {
	  int squareSum=0;
	  for(int i=0;i<3;i++)
	  {
	  	squareSum += N[i]*N[i];
	  }
	  return squareSum;
	}
};
class Set {
  public:
  	Set(int from, int to) {
  	  size = to - from +1 ;
  	  for(int i=1;i<size;i++)
  	  {
  	  	set[0].number=from;
  	  	set[i].number=set[i-1].number+1;
	  }    //初始化set[]，注意.number与from的类型一致 
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (int i = 0; i < size; i++)
  	  { 
  	    if(set[i].isSuperPrime())
  	    { 
  	      sum += set[i].number;
  	    } 
  	  } 
	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
