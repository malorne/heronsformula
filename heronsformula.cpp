#include <iostream>
#include <array>
#include <cmath>

double getValue(const std::string &prompt)
{
	double value;
	std::cout << prompt;
	std::cin >> value;
	return value;
}

double heronsFormula(double semiPeri, double a, double b, double c)
{
	double totalArea;
	totalArea = sqrt(semiPeri * (semiPeri - a) * (semiPeri - b) * (semiPeri - c));
	return totalArea;
}

// Distance formula = sqrt(x2 - x1)^2 + (y2 - y1)^2;
double calcDist(double x2, double x1, double y2, double y1)
{
	double totalDist;
	totalDist = sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
	return totalDist;
}

void calcSides()
{
	double a, b, c, s, totalBySides;

	std::cout << "Enter sides for a triangle" << "\n";

	a = getValue("Enter value for A: ");
	b = getValue("Enter value for B: ");
	c = getValue("Enter value for C: ");

	s = (a + b + c) / 2; // Semi-Perimeter formula

	if (a + b > c)
	{
		totalBySides = heronsFormula(s, a, b, c); // Heron's formula
		std::cout << "\n";
		std::cout << "Total area is: " << totalBySides << std::endl;
	}
	else // Contradiction to the Pythagorean theorem
	{
		std::cout << "Error! The hypotenuse is smaller than the cathets" << "\n";
	}
}

void calcPoints()
{
	// Points & Distance & Semi-Perimeter
	double x1, x2, x3,
		   y1, y2, y3,
		   distA, distB, distC,
		   semiPeri, totalByPoints;

	// Coordinates [x; y]
	std::array<double, 2> sideA;
	std::array<double, 2> sideB;
	std::array<double, 2> sideC;

	std::cout << "\n" << "Enter coordinates for a triangle" << "\n";

	std::cout << "\n" << "SIDE A: " << "\n";
	x1 = getValue("Enter value for x1: ");
	y1 = getValue("Enter value for y1: ");

	std::cout << "\n" << "SIDE B: " << "\n";
	x2 = getValue("Enter value for x2: ");
	y2 = getValue("Enter value for y2: ");

	std::cout << "\n" << "SIDE C: " << "\n";
	x3 = getValue("Enter value for x3: ");
	y3 = getValue("Enter value for y3: ");

	sideA[0] = x1;
	sideA[1] = y1;

	sideB[0] = x2;
	sideB[1] = y2;

	sideC[0] = x3;
	sideC[1] = y3;

	std::cout << "\n";

	// Show coordinates
	std::cout << "SIDE A: " << "[" << sideA[0] << "; " << sideA[1] << "]" << "\n";
	std::cout << "SIDE B: " << "[" << sideB[0] << "; " << sideB[1] << "]" << "\n";
	std::cout << "SIDE C: " << "[" << sideC[0] << "; " << sideC[1] << "]" << "\n";

	std::cout << "\n";
	// Calculate the lengths of the sides
	distA = calcDist(sideB[0], sideA[0], sideB[1], sideA[1]);
	distB = calcDist(sideB[0], sideC[0], sideB[1], sideC[1]);
	distC = calcDist(sideA[0], sideC[0], sideA[1], sideC[1]);

	std::cout << "Side A is: " << distA << std::endl;
	std::cout << "Side B is: " << distB << std::endl;
	std::cout << "Side C is: " << distC << std::endl;

	std::cout << "\n";

	if (distA + distB > distC) // Checking for a contradiction with the Pythagorean theorem
	{
		semiPeri = (distA + distB + distC) / 2; // Semi-Perimeter formula
		totalByPoints = heronsFormula(semiPeri, distA, distB, distC); // Heron's formula

		std::cout << "Semi-Perimeter is: " << semiPeri << "\n";
		std::cout << "Total area is: " << totalByPoints << "\n";
	}
	else // Contradiction to the Pythagorean theorem
	{
		std::cout << "Error! The hypotenuse is smaller than the cathets" << "\n";
	}
}

int main()
{
	int input;

	std::cout << "Enter points or sides? [1 or 2]: ";
	std::cin >> input;

	switch (input)
	{
	case 1:
		calcPoints();
		break;
	case 2:
		calcSides();
		break;
	default:
		std::cout << "Error! Choose points or sides";
		std::cout << "\n\n";
		main();
		break;
	}
}