#pragma once
#include <string>
#include <iostream>
using namespace std;

struct DNSRecord {
	string domainName;
	string ipAddress;
	DNSRecord() {
		this->domainName = "";
		this->ipAddress = "";
	}
	DNSRecord(string domain, string ip) {
		this->domainName = domain;
		this->ipAddress = ip;
	}
};

class DNSCache {
public:
	DNSRecord* records;
	int count;
	int capacity = 1;
	DNSCache();
	~DNSCache();
	DNSCache& operator=(DNSCache&);
	bool full();
	void resize();
	void add(const DNSRecord&);
	void add();
	string lookup(string domainName);
	void flush();
	void print();
};