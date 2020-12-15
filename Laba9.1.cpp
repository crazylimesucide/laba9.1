#include<iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;
enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { IT, ME, MF, FI, KN };
string kursStr[]{ "I", "II", "III", "IV", "V", "VI" };
string specStr[]{ "IT", "ME", "MF", "FI", "KN" };
struct Student {
	unsigned NumGr;
	string prizv;
	Kurs kurs;
	Spec spec;
	unsigned Fiz;
	unsigned Mat;
	unsigned Inf;
};
void Create(Student* s, const int N)
{
	int kurs;
	int spec;
	for (int i = 0; i < N; i++)
	{

		cout << "Ñòóäåíò ¹ " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " ïð³çâèùå: ";  getline(cin, s[i].prizv);
		cout << " ïîðÿäêîâèé íîìåð ñòóäåíòà ó ãðóï³: "; cin >> s[i].NumGr;
		cout << " êóðñ: "; cin >> kurs;
		cout << " ñïåö³àëüí³ñòü (0 - IT, 1 - ME, 2 - MF, 3 - FI, 4 - KN): "; cin >> spec;
		cout << " îö³íêè ç ô³çèêè: "; cin >> s[i].Fiz;
		cout << " îö³íêè ç ìàòåìàòèêè: "; cin >> s[i].Mat;
		cout << " îö³íêè ç ³íôîðìàòèêè: "; cin >> s[i].Inf;
		s[i].kurs = (Kurs)kurs;
		s[i].spec = (Spec)spec;
		cout << endl;
	}
};
void Print(Student* s, const int N)
{
	cout << "================================================================="
		<< endl;
	cout << "|  ¹  |   Ïð³çâèùå   | Íîìåð | Êóðñ | Ñïåö | Ô³ç. | Ìàò. | ²íô. |"
		<< endl;
	cout << "-----------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(5) << right << s[i].NumGr << " "
			<< "| " << setw(4) << right << kursStr[s[i].kurs - 1] << " "
			<< "| " << setw(4) << right << specStr[s[i].spec] << " "
			<< "| " << setw(4) << right << s[i].Fiz << " "
			<< "| " << setw(4) << right << s[i].Mat << " "
			<< "| " << setw(5) << right << s[i].Inf << "|" << endl;
	}
	cout << "================================================================="
		<< endl;
	cout << endl;
};
void Ser(Student* s, const int O, const int N, int& K)
{
	for (int i = 0; i < N; i++)
		cout << s[i].prizv << s[i].Fiz / s[i].Mat / s[i].Inf << endl;
}
void Fiz54(Student* s, const int N)
{
	cout << " ïð³çâèùà ñòóäåíò³â, ÿê³ îòðèìàëè ç ô³çèêè îö³íêó “5” : " << endl;
	for (int i = 0; i < N; i++)
		if (s[i].Fiz == 5 || s[i].Fiz == 4)
			cout << s[i].prizv << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, O, K = 0;
	cout << "Ââåä³òü N : "; cin >> N;
	cout << "Ìàêñèìàëüíà îö³íêà: "; cin >> O;

	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);

	Ser(s, O, N, K);
	cout << " ïðîöåíò ñòóäåíò³â, ÿê³ â÷àòüñÿ íà “â³äì³ííî” : " << setw(5) << 100. * K / N << "%" << endl;

	Fiz54(s, N);
	return 0;
}