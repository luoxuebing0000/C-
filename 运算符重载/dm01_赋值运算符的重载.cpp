namespace dm_01 
{
	// �����༰�����ຯ��
	class Test
	{
	public:
		Test();  // Ĭ�Ϲ��캯��
		Test(const Test &t); // ���ƹ��캯��
		Test& operator=(const Test &t); // ���ظ�ֵ�����
		~Test(); // ��������
	};

	// Test�ຯ����ʵ��
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