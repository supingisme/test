#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data/*    <rt 2019.12.17>*/
{
	std::string bookNo;
	unsigned int units_sold = {0};
	double revenue = {0.0};
};

#endif
