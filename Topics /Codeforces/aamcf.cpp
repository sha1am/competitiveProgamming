01.	#include <iostream>
02.	using namespace std;
03.	string getDivision(float avgM) {
	04.	if (avgM >= 75) return "First Division with distinction";
	05.	if (avgM >= 60) return "First division";
	06.	if (avgM >= 50) return "Second division";
	07.	if (avgM >= 40) return "Third division";
	08.	if (avgM >= 0) return "Fail";
	09.	return "ERROR";
	10.
}
11.	bool chkVal(int mark) {
	12.	if(mark <= 100) if(mark >= 0) return true;
	13.	return false;
	14.
}
15.	int main() {
	16.	int marks[3];
	17.	cin >> marks[0] >> marks[1] >> marks[2];
	18.	if(chkVal(marks[0]) && chkVal(marks[1]) && chkVal(marks[2]))
		19.	{
		20.	float avrg = (marks[0] + marks[1] + marks[2]) / 3;
		21.	cout << getDivision(avrg) << endl;
		22.	} else {
		23.	cout << "ERROR" << endl;
		24.
	}
	25.
}
