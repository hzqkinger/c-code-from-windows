#pragma once



class Fclose
{
public:
	void operator()(FILE *f)
	{
		cout << "Fclose" << endl;
		fclose((FILE*)f);
	}
};