#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm> 
#include <ctime>
#include "AttributeProbabilityWrapper.h"

using namespace std;

int myrandom(int i) { return rand() % i; }

int main()
{
	ifstream file("house-votes-84.data");
	if (!file) {
		cout << "Can't open the input file." << endl;
		return 1;
	}

	string str, line;
	vector<vector<string>> rows;
	while (getline(file, line)) {
		vector<string> cols;
		stringstream X(line);
		while (getline(X, str, ',')) {
			cols.push_back(str);
		}
		rows.push_back(cols);
		cols.clear();
	}
	file.close();

	
	int testRowsCount = rows.size() / 10;
	int summary = 0;

	vector<vector<string>> matrix = rows;
	srand(unsigned(std::time(0)));
	//random_shuffle(matrix.begin(), matrix.end());
	random_shuffle(matrix.begin(), matrix.end(), myrandom);
	for (int turn = 0; turn < 10; turn++) {
		map<int, AttributeProbabilityWrapper> attributesProbabilities;
		vector<vector<string>> testRecords, trainingRecords;
		for (int i = turn * testRowsCount; i < (turn + 1) * testRowsCount; i++) {
			testRecords.push_back(matrix[i]);
		}
		for (int i = 0; i < matrix.size(); i++) {
			if (i < turn * testRowsCount || i >= (turn + 1) * testRowsCount)
				trainingRecords.push_back(matrix[i]);
		}

		int republicansCount = 0, democratsCount = 0;
		for (int i = 0; i < trainingRecords.size(); i++) {
			if (trainingRecords[i][0] == "republican") {
				republicansCount++;
			}
			else {
				democratsCount++;
			}
		}
		double pRepublican = ((double)republicansCount) / trainingRecords.size();
		double pDemocrat = ((double)democratsCount) / trainingRecords.size();

		for (int k = 1; k < trainingRecords[0].size(); k++) {
			vector<vector<string>> eligibleRowsForAttribute;
			for (int i = 0; i < trainingRecords.size(); i++) {
				if (trainingRecords[i][k] != "?") {
					eligibleRowsForAttribute.push_back(trainingRecords[i]);
				}
			}

			vector<vector<string>> democratEligibleRowsForAttribute;
			for (int i = 0; i < eligibleRowsForAttribute.size(); i++) {
				if (eligibleRowsForAttribute[i][0] == "democrat") {
					democratEligibleRowsForAttribute.push_back(eligibleRowsForAttribute[i]);
				}
			}

			int democratForAttributePositiveValueCounter = 0, democratForAttributeNegativeValueCounter = 0;
			for (int i = 0; i < democratEligibleRowsForAttribute.size(); i++) {
				if (democratEligibleRowsForAttribute[i][k] == "y") {
					democratForAttributePositiveValueCounter++;
				}
				else if (democratEligibleRowsForAttribute[i][k] == "n") {
					democratForAttributeNegativeValueCounter++;
				}
			}

			vector<vector<string>> republicanEligibleRowsForAttribute;
			for (int i = 0; i < eligibleRowsForAttribute.size(); i++) {
				if (eligibleRowsForAttribute[i][0] == "republican") {
					republicanEligibleRowsForAttribute.push_back(eligibleRowsForAttribute[i]);
				}
			}

			int republicanForAttributePositiveValueCounter = 0, republicanForAttributeNegativeValueCounter = 0;
			for (int i = 0; i < republicanEligibleRowsForAttribute.size(); i++) {
				if (republicanEligibleRowsForAttribute[i][k] == "y") {
					republicanForAttributePositiveValueCounter++;
				}
				else if (republicanEligibleRowsForAttribute[i][k] == "n") {
					republicanForAttributeNegativeValueCounter++;
				}
			}

			int numFeatures = trainingRecords[0].size() - 1;
			double pDemocratForAttributePositive = 0, pDemocratForAttributeNegative = 0,
				pRepublicanForAttributePositive = 0, pRepublicanForAttributeNegative = 0;
			pDemocratForAttributePositive = ((double)democratForAttributePositiveValueCounter + 1 ) / (democratEligibleRowsForAttribute.size() + numFeatures); // + 1 because of Laplace smoothing
			pDemocratForAttributeNegative = ((double)democratForAttributeNegativeValueCounter + 1 ) / (democratEligibleRowsForAttribute.size() + numFeatures);
			pRepublicanForAttributePositive = ((double)republicanForAttributePositiveValueCounter + 1 ) / (republicanEligibleRowsForAttribute.size() + numFeatures);
			pRepublicanForAttributeNegative = ((double)republicanForAttributeNegativeValueCounter + 1 ) / (republicanEligibleRowsForAttribute.size() + numFeatures);
			/*cout << pRepublicanForAttributePositive << ", " << pRepublicanForAttributeNegative << ", "
				<< pDemocratForAttributePositive << ", " << pDemocratForAttributeNegative << endl;*/
			AttributeProbabilityWrapper wrapper = AttributeProbabilityWrapper(pDemocratForAttributePositive, pDemocratForAttributeNegative,
				pRepublicanForAttributePositive, pRepublicanForAttributeNegative);

			attributesProbabilities.insert(make_pair(k, wrapper));
		}


		int identities = 0;
		for (int j = 0; j < testRecords.size(); j++) {
			vector<string> example = testRecords[j];
			double examplePDemocrat = 0, examplePRepublican = 0;
			for (int k = 1; k < example.size(); k++) {
				if (example[k] == "y") {
					examplePDemocrat += log2(attributesProbabilities[k].pDemocratForAttributePositive);
					examplePRepublican += log2(attributesProbabilities[k].pRepublicanForAttributePositive);
				}
				else if (example[k] == "n") {
					examplePDemocrat += log2(attributesProbabilities[k].pDemocratForAttributeNegative);
					examplePRepublican += log2(attributesProbabilities[k].pRepublicanForAttributeNegative);
				}
			}
			examplePDemocrat += log2(pDemocrat);
			examplePRepublican += log2(pRepublican);
			//cout << j + 1 << ":";
			if (examplePDemocrat > examplePRepublican) {
				if (testRecords[j][0] == "democrat") {
					identities++;
				}
				//cout << "This person is a democrat." << endl;
			}
			else {
				if (testRecords[j][0] == "republican") {
					identities++;
				}
				//cout << "This person is a republican." << endl;
			}
		}
		summary += identities;
		cout << "Accuracy[" << turn + 1 << "] = " << (double)identities / (double)testRecords.size() << endl;
		attributesProbabilities.clear();
	}

	cout << endl;
	cout << "Summary: " << (double)summary / ((double)testRowsCount * 10) << endl;

	return 0;
}