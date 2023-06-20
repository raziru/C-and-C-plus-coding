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

	Point operator+(const Point& other) const//�տ� ���� �ǿ������� Ÿ���� ������ �����ϰ� �ڿ����� �ǿ������� Ÿ������ �Ű������� �����Ѵ�.
	{//�Ű����������� �޸� ���Ҵ��� ���ϱ� call by reference�� ����. �׸��� ȣ��Ǵ� other�� ������ �����ϱ� ���� const�� ���δ�.
		//�׸��� this�� �����ϱ� ���� �Լ� ���� const�� ���δ�.
		Point result;

		result.x = this->x + other.x;
		result.y = this->y + other.y;
		/*other.x += this->x;
		this->x += this->x;*/

		return result;

	}

	void operator+=(const Point& other)//���� �����ڴ� ��ȯ���̾�� void�� �ۼ��Ѵ�.
	{
		this->x += other.x;
		this->y += other.y;

	}

	/*
	���ϱ� ����

	� �����(float value)�� x,y�� ��� ���ϴ� ����
	
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

	void operator++(void)//����
	{
		this->x += 1;
		this->y += 1;

	}
	void operator++(int) //���� �����Ǿ���ϴ� const�� ��������ʴ´�.
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