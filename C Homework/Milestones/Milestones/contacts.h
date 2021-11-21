/*
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 10/25/2018
*/


struct Name
{
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address 
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers 
{
	char cell[11];
	char home[11];
	char business[11];
};