// FlagMaker.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//this is a starting point.
//function to display coordinates that I can use to set colors to.
int createCoordinateMap(int a, int b)
{
	//use this to diplay decimal coordinates
	float horizontalDec = 0;
	float verticalDec = 0;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / b;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / a;
			cout << horizontalDec << " ";

		}
		horizontalDec = 0;
		cout << endl;
	}
	return 1;
}

//This should return true if in box or false if out of box
//makes a box using tl(top left) coordinates and br (bottom right) coordinates
//all values are between 0 and 1.
//y coordinate is inverse (goes from top to bottom)
bool createRectangle(float tlCornerX, float tlCornerY, float brCornerX, float brCornerY, float currentX, float currentY)
{
	//see if current x is in between 
	if (currentX >= tlCornerX && currentX <= brCornerX)
	{
		//check if between y corners
		if (currentY >= tlCornerY && currentY <= brCornerY)
		{
			return true;
		}
		else
		{
			return false;   //return false if not in y
		}
	}
	else
	{
		return false; //return false if not in x 
	}
}

//draw a circle
bool createCircle(float centerX, float centerY, float radiusSquared, float currentX, float currentY)
{
	float distanceSquared;
	//pythagorean theorem without square root
	distanceSquared = ((centerX - currentX) * (centerX - currentX)) + ((centerY - currentY) * (centerY - currentY));
	//check if it is in the circle
	if (distanceSquared <= radiusSquared)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//testing only
void testCreateRectangle()
{
	bool test;
	cout << "enter in a float between 0 and 1" << endl;
	float tester1;
	cin >> tester1;
	cout << "another float please" << endl;
	float tester2;
	cin >> tester2;

	test = createRectangle(0.25, 0.25, 0.75, 0.5, tester1, tester2);
	cout << "the thing tests " << (test == 1);
}
//testing only
void looptestCreateCircle(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;
			//in middle with .5 as the radius length
			cout << createCircle(0.5, 0.5, 0.25, horizontalDec, verticalDec);

		}
		horizontalDec = 0;
		cout << endl;
	}
}
//for testing only
void looptestCreateRectangle(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;
			cout << createRectangle(0.25, 0.25, 0.75, 0.75, horizontalDec, verticalDec);

		}
		horizontalDec = 0;
		cout << endl;
	}
}

//draw German flag
void germanFlag(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	ofstream dout;
	dout.open("German_Flag.ppm");

	dout << "P3" << endl; /////added a +1 because I kept getting size
	dout << (horSize + 1) << " " << (verSize + 1) << endl;
	dout << 255 << endl;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;
			//actual code goes here
			//black
			if ((createRectangle(0.0, 0.0, 1.0, 0.3333333, horizontalDec, verticalDec) == 1))
			{
				dout << "000 000 000  ";
			}//red
			else if ((createRectangle(0.0, 0.333333333, 1.0, 0.666666666, horizontalDec, verticalDec) == 1))
			{
				dout << "255 000 000  ";
			}
			//yellow
			else
			{
				dout << "230 230 000  ";
			}







		}
		horizontalDec = 0;
		dout << endl;
	}
}

//draw Flag of poland
void polandFlag(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	ofstream dout;
	dout.open("Poland_Flag.ppm");

	dout << "P3" << endl; /////added a +1 because I kept getting size issues
	dout << (horSize + 1) << " " << (verSize + 1) << endl;
	dout << 255 << endl;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;

			//white rectangle on top half
			if ((createRectangle(0.0, 0.0, 1.0, 0.5, horizontalDec, verticalDec) == 1))
			{
				dout << "255 255 255  ";
			}
			//red rectangle bottom half
			else
			{
				dout << "255 000 000  ";
			}







		}
		horizontalDec = 0;
		dout << endl;
	}
}

//make a denmark flag
void denmarkFlag(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	ofstream dout;
	dout.open("Denmark_Flag.ppm");

	dout << "P3" << endl; /////added a +1 because I kept getting size issues
	dout << (horSize + 1) << " " << (verSize + 1) << endl;
	dout << 255 << endl;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;

			//white rectangle going down
			if ((createRectangle(0.3, 0.0, 0.4, 1.0, horizontalDec, verticalDec) == 1))
			{
				dout << "255 255 255  ";
			}
			//white rectangle going across
			else if ((createRectangle(0.0, 0.45, 1.0, 0.55, horizontalDec, verticalDec) == 1))
			{
				dout << "255 255 255  ";
			}
			//red for rest of flag
			else
			{
				dout << "255 000 000  ";
			}







		}
		horizontalDec = 0;
		dout << endl;
	}
}

//japanese flag function
//make use of the circle function
void japanFlag(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	//output to a file
	ofstream dout;
	dout.open("Japan_Flag.ppm");

	dout << "P3" << endl; /////added a +1 because I kept getting size issues
	dout << (horSize + 1) << " " << (verSize + 1) << endl;
	dout << 255 << endl;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;

			//edit to full coordinate input rather than percent decimals, that way I can keep the circle size the same.
			if (createCircle(0.5 * horSize, 0.5 * verSize, 0.05 * verSize * verSize, x, y))
			{
				dout << "255 000 000  ";
			}
			//white rectangle going across
			else
			{
				dout << "255 255 255  ";
			}
		}
		horizontalDec = 0;
		dout << endl;
	}
}

//Loas flag function 
//see if rectangles and circles can work together
void laosFlag(int horSize, int verSize)
{
	float horizontalDec = 0.0;
	float verticalDec = 0.0;

	//output to a file
	ofstream dout;
	dout.open("Laos_Flag.ppm");

	dout << "P3" << endl; /////added a +1 because I kept getting size issues
	dout << (horSize + 1) << " " << (verSize + 1) << endl;
	dout << 255 << endl;

	for (int y = 0; verticalDec < 1.0; y += 1)
	{
		verticalDec = (1.0 * y) / verSize;
		//cout << verticalDec << ":  "; //to test the row
		for (int x = 0; horizontalDec < 1.0; x += 1)
		{
			horizontalDec = (1.0 * x) / horSize;

			//white circle in middle.
			//removed the ==1 or ==true because a bool value is returned
			if (createCircle(0.5 * horSize, 0.5 * verSize, 0.04 * verSize * verSize, x, y))
			{
				dout << "255 255 255  ";
			}
			//blue line on the outside
			else if (createRectangle(0.0, 0.25, 1.0, 0.75, horizontalDec, verticalDec))
			{
				dout << "000 060 235  ";
			}
			//red outside
			else
			{
				dout << "220 050 050  ";
			}
		}
		horizontalDec = 0;
		dout << endl;
	}
}

//function that asks which flag to draw
int chooseFlag()
{
	bool repeat = false;
	string inputtedStuff;
	cout << "Enter country of what flag you want:" << endl;
	do
	{
		cout << "Laos, Germany, Denmark, Japan, Poland, or nothing" << endl;
		//technically it reads the name input into a string variable
		cin >> inputtedStuff;
		if (inputtedStuff == "Laos" || inputtedStuff == "laos")
		{
			//add this just to make sure the loop doesn't repeat on accident
			repeat = false;
			return 1;
		}
		else if (inputtedStuff == "Germany" || inputtedStuff == "germany")
		{
			repeat = false;
			return 2;
		}
		else if (inputtedStuff == "Denmark" || inputtedStuff == "denmark")
		{
			repeat = false;
			return 3;
		}
		else if (inputtedStuff == "Japan" || inputtedStuff == "japan")
		{
			repeat = false;
			return 4;
		}
		else if (inputtedStuff == "Poland" || inputtedStuff == "poland")
		{
			repeat = false;
			return 5;
		}
		else if (inputtedStuff == "Nothing" || inputtedStuff == "nothing") 
		{
			repeat = false;
			//does not want a flag
			return 0;
		}
		else
		{
			repeat = true;
			cout << "try entering something again:" << endl;
		}
	} while (repeat == true);
}

int chooseAnotherFlag()
{
	bool repeat = false;
	string inputtedStuff;
	cout << "Enter country of another flag you want:" << endl;
	do
	{
		cout << "Laos, Germany, Denmark, Japan, Poland, or done" << endl;
		cin >> inputtedStuff;
		if (inputtedStuff == "Laos" || inputtedStuff == "laos")
		{
			//add this just to make sure the loop doesn't repeat on accident
			repeat = false;
			return 1;
		}
		else if (inputtedStuff == "Germany" || inputtedStuff == "germany")
		{
			repeat = false;
			return 2;
		}
		else if (inputtedStuff == "Denmark" || inputtedStuff == "denmark")
		{
			repeat = false;
			return 3;
		}
		else if (inputtedStuff == "Japan" || inputtedStuff == "japan")
		{
			repeat = false;
			return 4;
		}
		else if (inputtedStuff == "Poland" || inputtedStuff == "poland")
		{
			repeat = false;
			return 5;
		}
		else if (inputtedStuff == "Nothing" || inputtedStuff == "nothing" || inputtedStuff == "done" || inputtedStuff == "Done")
		{
			repeat = false;
			//does not want a flag
			return 0;
		}
		else
		{
			repeat = true;
			cout << "try entering something again:" << endl;
		}
	} while (repeat == true);
}

int getCorrectSizeHorizontal() 
{
	bool repeat = false;
	int size;
	//infinite until correct input
	do
	{

		cout << "enter horizontal size (100 to 1000):" << endl;
		cin >> size;

		if (size >= 100 && size <= 1000) 
		{
			
			return size; 
			break; //incase return doesn't work
		}
		else
		{
			cout << "try again" << endl;
			repeat = true;
		}
	} while (repeat == true);
}
//vertical size input
int getCorrectSizeVertical()
{
	bool repeat = false;
	int size;
	do
	{

		cout << "enter vertical size (100 to 1000):" << endl;
		cin >> size;

		if (size >= 100 && size <= 1000)
		{
			repeat = false;
			return size;
		}
		else
		{
			cout << "try again" << endl;
			repeat = true;
		}
	} while (repeat == true);
}





/////////////////////////////////////////////
/////////////////////////////////////////////
int main()
{
	//values for the size
	int horizontalSize = 0;
	int verticalSize = 0;
	int desiredFlag = 0;
	
	
	//key for integer returned 1=laos | 2 = germany | 3 = Denmark | 4 = japan | 5 = poland | 0 = no flag
	desiredFlag = chooseFlag();
	

	//need to check this since I don't want to move all of the previously written code around
	//therefore, numbers will be out of order here
	while (desiredFlag != 0)
	{
		horizontalSize = getCorrectSizeHorizontal();
		verticalSize = getCorrectSizeVertical();
		
		
		//createCoordinateMap(horizontalSize-1, verticalSize-1); //test function as basis for other functions

		//test if coordinate is in box 
		//testCreateRectangle();


		//looptestCreateRectangle(horizontalSize-1, verticalSize-1); // should make a square in the middle

		//german flag output

		if (desiredFlag == 2) 
		{
			germanFlag(horizontalSize - 1, verticalSize - 1);
			cout << "German Flag output as German_Flag.ppm" << endl;
		}

		//poland flag output
		if (desiredFlag == 5)
		{
			polandFlag(horizontalSize - 1, verticalSize - 1);
			cout << "Poland Flag output as Poland_Flag.ppm" << endl;
		}

		//denmark flag output
		if (desiredFlag == 3) 
		{ 
			denmarkFlag(horizontalSize - 1, verticalSize - 1);
			cout << "Denmark Flag output as Denmark_Flag.ppm" << endl;
		}

		//test the create circle function
		//looptestCreateCircle(horizontalSize - 1, verticalSize - 1);

		//run the japan flag function
		if (desiredFlag == 4) 
		{
			japanFlag(horizontalSize - 1, verticalSize - 1); 
			cout << "Japan Flag output as Japan_Flag.ppm" << endl;
		}

		//run the laos flag function
		if (desiredFlag == 1) 
		{ 
			laosFlag(horizontalSize - 1, verticalSize - 1);
			cout << "Laos FLag output as Laos_Flag.ppm" << endl;
		}

		//see if user wants another flag outputted
		desiredFlag = chooseAnotherFlag();

	}
}