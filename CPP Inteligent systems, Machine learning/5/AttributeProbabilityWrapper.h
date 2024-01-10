#pragma once
#ifndef ATTRIBUTEPROBABILITYWRAPPER_H
#define ATTRIBUTEPROBABILITYWRAPPER_H

class AttributeProbabilityWrapper {
public:
	double pDemocratForAttributePositive;
	double pDemocratForAttributeNegative;
	double pRepublicanForAttributePositive;
	double pRepublicanForAttributeNegative;

	AttributeProbabilityWrapper();
	AttributeProbabilityWrapper(double pDemocratForAttributePositive, double pDemocratForAttributeNegative,
		double pRepublicanForAttributePositive, double pRepublicanForAttributeNegative);

};

#endif