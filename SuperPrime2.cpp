//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
  		count=0;
	}
	~Prime() {
	}
  	bool isPrime() {
	  for(int i=2;i<number;i++){     //2��number-1������ 
	  	if(number%i==0)
	  	count++;
	  } 
	  if(count==0)
	    return true;
  	  else
		return false;
	}
  private:
  	const int number;
  	int count;
}; 
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  int temp = n;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	pset.add(t);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  } 
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
	  if (Prime::isPrime() && pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
	int sum() {
	  return 0;
	}
	int multi() {
	  return 0;
	}
	int squareSum() {
	  return 0;
	}
};
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  N = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //���ٶ��� 
		delete N[i]; 
	  delete[] N;
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}

	bool add(int n) {
	  if(index == size)   return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **set;
	int size, index;
};
class SuperPrime {
  public:
  	SuperPrime():number(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):number(n), pset(3) {
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  //��ôʹ��pset�� 
  	  Prime p(number);
	  if (p.isPrime() && pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	PrimeSet pset;
  	int Num[3],sum=0,multi=1,squareSum=0;
	void split() {   //�����������ģʽ 
	  // number split into N
	  int temp = number;
	  int k=0;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	Num[k]=n;
	  	k++;
	  }
	  for(int i=0;i<3;i++){
	  	sum+=Num[i];
	  	multi*=Num[i];
	  	squareSum+=Num[i]*Num[i];
	  } 
	  pset.add(sum);
	  pset.add(multi);
	  pset.add(squareSum);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	}
	/*int sum() {
	  return 0;
	}
	int multi() {
	  return 0;
	}
	int squareSum() {
	  return 0;
	}*/
};
class SuperPrimeSet {
  public:
  	SuperPrimeSet(int from, int to) {
  	  size = to - from;
  	  for (int i = from; i < to; i++)
  	    set[i-from] = new SuperPrime(i);
	}
  	~SuperPrimeSet() {
  	  for(int i = 0; i < size; i++)
  	    delete set[i];
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  /*
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i];
  	      */ 
	  return sum; 
	}
  private:
  	SuperPrime **set;
  	int size, index;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
