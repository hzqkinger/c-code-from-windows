#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

void test_love1()
{
	float y, x, z, f;
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			z = x*x + y*y - 1;
			f = z*z*z - x*x*y*y*y;
			putchar(f <= 0.0f ? "*:-=+.#%@"[(int)(f*-0.8f)] : ' ');
		}
		putchar('\n');
	}
	getchar();

}

float f(float x, float y, float z)
{
	float a;
	a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}
float h(float x, float z)
{
	float y;
	for(y = 1.0f; y >= 0.0f; y -= 0.001f)
		if(f(x, y, z) <= 0.0f)
		return y;
	return 0.0f;
}
void test_love2()
{
	float z, x, v, y0, ny, nx, nz, nd, d;
	for(z = 1.5f; z > -1.5f; z -= 0.05f) {
		for(x = -1.5f; x < 1.5f; x += 0.025f) {
			v = f(x, 0.0f, z);
			if(v <= 0.0f) {
				y0 = h(x, z);
				ny = 0.01f;
				nx = h(x + ny, z) - y0;
				nz = h(x, z + ny) - y0;
				nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
				d = (nx + ny - nz) * nd * 0.5f + 0.5f;
				putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
			}
	 else
		 putchar(' ');
		}
		putchar('\n');
	}
	getchar();
}

void test_love3()
{
	double y, x, z;
	for(y = 2.5; y >= -1.6; y = y - 0.2)
	{
		for(x = -3; x <= 4.8; x = x + 0.1)
			((x*x + y*y - 1)*(x*x + y*y - 1)*(x*x + y*y - 1) <= 3.6*x*x*y*y*y
			|| (x>-2.4 && x<-2.1 && y<1.5 && y>-1)
			|| (((x<2.5 && x>2.2) || (x>3.4 && x<3.7)) && y>-1 && y<1.5)
			|| (y>-1 && y<-0.6 && x<3.7 && x>2.2)) ? printf("*") : printf(" ");
		printf("\n");
	}
	getchar();
}

void test_love4()
{
	double y, x;

	for (y = 1.5; y >= -1.0; y -= 0.1f)
	{
		for (x = -1.0; x <= 1.0; x += 0.05f)
		{
			if (x*x + pow((y - pow(x, 1.5)), 2) <= 1)
				printf("*");
		}
		printf("\n");
	}
}
int main()
{
	test_love1();//平面式单个心形
	//test_love2();//立体式单个心形，，太大了，不好展示
	//test_love3();//I ❤ U
	//test_love4();
	system("pause");
	return 0;
}