int func(int a)
{
	return a;
}
int func(int a, int b = 1)
{
	return a;
}
int main11()
{
	//func(10); // error
	return 0;
}