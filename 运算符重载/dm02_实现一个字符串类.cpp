#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace dm_02
{
	class MyString
	{
		friend ostream& operator<<(ostream &out, const MyString &s);
	public: //构造和析构
		MyString(int len = 0);
		MyString(const char *p);
		MyString(const MyString& obj);
		~MyString();

	public: //操作符重载
		MyString& operator=(const char *p);
		MyString& operator=(const MyString& obj);
		char& operator[](int index) const;

	public:
		bool operator==(const char* p) const;
		bool operator!=(const char* p) const;
		bool operator==(const MyString& s) const;
		bool operator!=(const MyString& s) const;

	public: //string to c
		char *c_str();
		const char* c_str() const;
		int length()
		{
			return m_len;
		}

	public:
		int operator<(const char *p);
		int operator>(const char *p);

		int operator<(const MyString &s);
		int operator>(const MyString &s);


	private:
		int		m_len;
		char	*m_p;
	};

	// 构造和析构函数
	MyString::MyString(int len)
	{
		this->m_len = len;
		if (m_p != nullptr)
			m_p = nullptr;
	}
	MyString::MyString(const char *p)
	{
		if (p == nullptr)
			return;
		this->m_len = strlen(p);
		m_p = (char *)malloc(sizeof(char)*(m_len + 1));
		if (m_p == nullptr)
		{
			m_len = 0;
			return;
		}
		strcpy(m_p, p);
		m_p[m_len] = '\0';
	}
	MyString::MyString(const MyString& obj)
	{
		if (obj.m_p == nullptr || obj.m_len == 0)
			return;
		this->m_len = obj.m_len;
		this->m_p = (char *)malloc((this->m_len + 1) * sizeof(char));
		strcpy(this->m_p, obj.m_p);
		this->m_p[m_len] = '\0';
	}
	MyString::~MyString()
	{
		if (this->m_len == 0 && this->m_p == nullptr)
		{
			return;
		}
		this->m_len = 0;
		free(this->m_p);
			
	}

	// 操作符重载
	MyString& MyString::operator=(const char *p)
	{
		if (p == nullptr)
		{
			return *this;
		}
		if (this->m_p != nullptr)
			free(m_p);
		this->m_len = strlen(p);
		this->m_p = (char *)malloc(sizeof(char)*(this->m_len + 1));
		if (this->m_p == nullptr)
		{
			m_len = 0;
			return *this;
		}
		strcpy(this->m_p, p);
		this->m_p[this->m_len] = '\0';
		return *this;

	}
	MyString& MyString::operator=(const MyString& obj)
	{
		if (obj.m_p == nullptr || obj.m_len == 0)
			return *this;
		if (this->m_p != nullptr)
			free(m_p);
		this->m_len = obj.m_len;
		this->m_p = (char *)malloc((this->m_len + 1) * sizeof(char));
		strcpy(this->m_p, obj.m_p);
		this->m_p[m_len] = '\0';
		return *this;
	}
	char& MyString::operator[](int index) const
	{
		return this->m_p[index];
	}

	char *MyString::c_str()
	{
		return this->m_p;
	}
	const char* MyString::c_str() const
	{
		return this->m_p;
	}

	int MyString::operator<(const char *p)
	{
		return strcmp(this->m_p, p);
	}
	int MyString::operator>(const char *p)
	{
		return strcmp(this->m_p, p);
	}

	int MyString::operator<(const MyString &s)
	{
		return this->m_p < s.m_p;
	}
	int MyString::operator>(const MyString &s)
	{
		return this->m_p > s.m_p;
	}

	bool MyString::operator==(const char* p) const
	{
		return strcmp(this->m_p, p) == 0;
	}
	bool MyString::operator!=(const char* p) const
	{
		return strcmp(this->m_p, p) == 0;
	}
	bool MyString::operator==(const MyString& s) const
	{
		return strcmp(this->m_p, s.m_p) == 0;
	}
	bool MyString::operator!=(const MyString& s) const
	{
		return !operator==(s);
	}

	// 友元函数
	ostream& operator<<(ostream &out, const MyString &s)
	{
		out << s.m_p;
		return out;
	}

}
int main()
{
	using namespace dm_02;
	MyString str("hello world");
	MyString str2 = str;
	str2 = str;
	str2 = "welcom";
	return 0;
}