#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<assert.h>



enum State
{
	NULL_STATE,	/*��״̬*/
	C_STATE,	//C״̬
	CPP_STATE,	//CPP״̬
	END_STATE,
};

State state = NULL_STATE;

void OnNullState(FILE* fin, FILE* fout)
{
	char first = fgetc(fin);
	if (first == '/')
	{
		char second = fgetc(fin);
		if (second == '*')
		{
			state = C_STATE;
		}
		else if (second == '/')
		{
			state = CPP_STATE;
		}

		fputs("//", fout);
	}
	else
	{
		fputc(first, fout);
	}
}

void OnCState(FILE* fin, FILE* fout);
void OnCPPState(FILE* fin, FILE* fout);


void _StartConvert(FILE* fin, FILE* fout)
{
	while (state != END_STATE)
	{
		switch (state)
		{
		case NULL_STATE:	// ��/* // ->
			OnNullState(fin, fout);
			break;
		case C_STATE:		// ��*/ -> NULL_STATE
			OnCState(fin, fout);
			break;
		case CPP_STATE:		// �һ��� -> NULL_STATE
			OnCPPState(fin, fout);
			break;
		case END_STATE:		// ����
			break;
		default:
			assert(false);
		}
	}
}

void StartConvert(const char* inFile, const char* outFile)
{
	FILE* fin = fopen(inFile, "r");
	assert(fin);

	FILE* fout = fopen(outFile, "w");
	assert(fout);

	_StartConvert(fin, fout);
}



int main()
{


	system("pause");
	return 0;
}