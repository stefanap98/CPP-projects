#include <iostream>
#include "Guest.h"
#include "User.h"
#include "PowerUser.h"
#include "Vip.h"
#include "Admin.h"

int main()
{
	std::cout << "A" << std::endl;
	Guest A("1337");
	A.print();
	
	std::cout << "B" << std::endl;
	Guest B = A;
	B.print();

	std::cout << "C" << std::endl;
	Guest C;
	C = B;
	C.print();

	std::cout << "D" << std::endl;
	User D("1337", "Mecho", "pass", "SomeTitle");
	D.print();

	D.setNewPassword("pask", "nopass");

	std::cout << "E" << std::endl;
	User E = D;
	E.print();

	std::cout << "F" << std::endl;
	User F;
	F = E;
	D.setNewPassword("pass", "nopass");
	F.print();

	std::cout << "G" << std::endl;
	PowerUser G("1337", "Mecho", "pass", "SomeTitle",16);
	G.print();

	std::cout << "H" << std::endl;
	PowerUser H = G;
	H.GiveReputation(H);
	H.print();

	std::cout << "I" << std::endl;
	PowerUser I;
	I = H;
	I.GiveReputation(H);
	I.print();

	std::cout << "J" << std::endl;
	Vip J("1337", "Mecho", "pass", "SomeTitle");
	J.changeTitle("NewTitle");
	J.print();

	std::cout << "K" << std::endl;
	Vip K = J;
	K.print();

	std::cout << "L" << std::endl;
	Vip L;
	L = K;
	L.print();

	std::cout << "M" << std::endl;
	Admin M("1337", "Mecho", "pass", "SomeTitle", 16);
	M.ChangeOwnUsername("NotMechoAnymore");
	M.print();

	std::cout << "P" << std::endl;
	User P("1234", "Zaio", "parola", "TejkaKategoriq");
	M.ChangeUsername(P, "ZaioBaioOtGorata");
	P.print();

	std::cout << "N" << std::endl;
	Admin N=M;
	N.print();

	std::cout << "O" << std::endl;
	Admin O;
	O = N;
	O.print();

	return 0;
}