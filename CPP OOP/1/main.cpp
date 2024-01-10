#include <iostream>

#include "IntStack.h"

using namespace std;

int main() {
	//syzdavane na stek 
	IntStack st;
	st.push(5);
	st.push(7);
	st.push(3);
	st.push(6);
	st.push(1);
	st.push(3);
	st.pop();
	st.print();

	SortStack(st);
	//syzdavane na stek chrez copy constructor
	IntStack t=st;
	t.print();
	t.print();
	

	IntStack p;
	//inicializirane na stek sys sydyrjanieto na drug stek chrez operator =
	p = t;
	p.print();

	
	IntStack x;
	//inicializirane na stek chrez chetene ot klaviaturata/konzolata
	x.read();
	SortStack(x);
	x.print();

	cout << "Stack X top number:";
	x.peek();
	
	return 0;
}
