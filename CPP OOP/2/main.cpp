#include "DNS.h"
using namespace std;

int main() {
	DNSCache dns1;
	dns1.add();
	string domain;
	string domainName1 = ".com";
	string ipAddress1 = "207.142.131.236";
	string domainName2 = ".bg";
	string ipAddress2 = "64.78.205.15";
	DNSRecord rec1(domainName1, ipAddress1);
	DNSRecord rec2(domainName2, ipAddress2);
	dns1.add(rec1);
	dns1.add(rec2);
	DNSCache dns2 = dns1;
	cout << "DNS1: " << endl;
	dns1.print();
	cout << "DNS2: " << endl;
	dns2.print();
	dns1.add();
	cout << "DNS1: " << endl;
	dns1.print();
	cout << "Enter domain name to look for it's ip address: ";
	cin >> domain;
	cout << "\nThis domain's ip is: " << dns1.lookup(domain) << endl;
	dns1.flush();
	dns1.print();
	return 0;
}