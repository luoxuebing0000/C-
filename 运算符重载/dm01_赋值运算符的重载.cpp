namespace dm_01 
{
	// 定义类及声明类函数
	class Test
	{
	public:
		Test();  // 默认构造函数
		Test(const Test &t); // 复制构造函数
		Test& operator=(const Test &t); // 重载赋值运算符
		~Test(); // 析构函数
	};

	// Test类函数的实现
	Test::Test() { ; }
	Test::Test(const Test &t) { ; }
	Test& Test::operator=(const Test &t) 
	{
		return *this;
	}
	Test::~Test() { ; }
}
int main11()
{
	using namespace dm_01;
	Test t1,t2;
	Test t3 = t1;
	t3 = t2;
	return 0;
}