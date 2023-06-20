#pragma once
struct Point
{
	Point()
	{

	}
	Point(int x, int y)
		:x(x), y(y)
	{

	}

	Point operator+(const Point& other) const//앞에 오는 피연산자의 타입이 리턴을 결정하고 뒤에오는 피연산자의 타입으로 매개변수를 결정한다.
	{//매개변수로인한 메모리 재할당을 피하기 call by reference를 쓴다. 그리고 호출되는 other의 원본을 보존하기 위해 const를 붙인다.
		//그리고 this를 보존하기 위해 함수 끝에 const를 붙인다.
		Point result;

		result.x = this->x + other.x;
		result.y = this->y + other.y;
		/*other.x += this->x;
		this->x += this->x;*/

		return result;

	}

	void operator+=(const Point& other)//대입 연산자는 반환형이없어서 void로 작성한다.
	{
		this->x += other.x;
		this->y += other.y;

	}

	/*
	곱하기 연산

	어떤 상수갑(float value)를 x,y에 모두 곱하는 연산
	
	this->x * value;

	this->y * value;

	*/

	Point operator*(const float& value)const
	{
		Point result;

		result.x = this->x * value;
		result.y = this->y * value;

		return result;
	}
	void operator*=(const float value)
	{
		this->x *= value;
		this->y *= value;
	}

	void operator++(void)//후위
	{
		this->x += 1;
		this->y += 1;

	}
	void operator++(int) //전위 수정되어야하니 const를 사용하지않는다.
	{
		this->x += 1;
		this->y += 1;
	}

	void operator<<(const int& value)
	{
		this->x *= value;
		this->y = powf(y, value);
	}


	int x;
	int y;
};