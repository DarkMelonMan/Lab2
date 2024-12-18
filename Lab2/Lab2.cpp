#include "Structures.cpp"
#include "Classes.h"

int main()
{
	do {
		cout << endl << "Choose test type:" << endl << "1)Structures" << endl <<
			"2)Classes" << endl << "3)Exit" << endl;
		try {
			do {
				cin >> DamageTest::testChoice;
				if (DamageTest::testChoice < 1 || DamageTest::testChoice > 3)
					cout << "Wrong choice. Try again: " << endl;
			} while (DamageTest::testChoice < 1 || DamageTest::testChoice > 3);
			if (DamageTest::testChoice == 3)
				exit(0);
			switch (DamageTest::testChoice) {
			case 1:
				DamageTest::ChooseStruct();
				break;
			case 2:
				DamageTest::ChooseClass();
				break;
			default:
				break;
			}
		}
		catch (const TestError& e) {
			cout << endl << "Test was unsuccessful" << endl;
		}
	} while (DamageTest::testChoice != 3);
}
