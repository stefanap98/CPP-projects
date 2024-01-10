#include "DNS.h"
using namespace std;

DNSCache::DNSCache() {
	count = 0;
	capacity = 1;
	records = new DNSRecord[capacity];
}

DNSCache::~DNSCache() {
	delete[] records;
}
DNSCache& DNSCache::operator=(DNSCache& cache) {
	if (this != &cache) {
		cache.capacity = this->capacity;
		cache.count = this->count;
		for (int i = 0; i < this->count; i++) {
			cache.records[i] = this->records[i];
		}
	}
	return *this;

}
void DNSCache::add(const DNSRecord& rec) {
	if (full()) resize();
	records[count++] = rec;
}
bool DNSCache::full() {
	return count == capacity - 1;
}
void DNSCache::resize() {
	int cap = capacity;
	capacity += 1;
	DNSRecord* newRecords = new DNSRecord[capacity];
	for (int i = 0; i < cap; i++)
		newRecords[i] = records[i];
	delete[] records;
	records = newRecords;
}
void DNSCache::add() {
	if (full()) resize();
	string domainName, ipAddress;
	cout << "Enter domain: ";
	cin >> domainName;
	cout << "Enter IP Address: ";
	cin >> ipAddress;
	DNSRecord rec(domainName, ipAddress);
	add(rec);
}
string DNSCache::lookup(string domain) {
	for (int i = 1; i < count; i++) {
		if (domain == records[i].domainName) return records[i].ipAddress;
	}
	return "NULL";
}
void DNSCache::flush() {
	DNSCache::~DNSCache();
	count = 0;
	cout << "Flushed!" << endl;
}
void DNSCache::print() {
	if (count != 0) {
		cout << "Domain:  IP Address:" << endl;
		for (int i = 0; i < count; i++) {
			cout << records[i].domainName << "    " << records[i].ipAddress << endl;
		}
	}
	else cout << "DNSCache is empty!";
}