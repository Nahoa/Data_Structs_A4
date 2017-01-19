/*Rusty Raymond

Assignment #3

to test complex funtions comment out simple functions and uncomment complex functions

*/
#define _CRTDBG_MAP_ALLOC

typedef bool(*FunctionPointer)();  // Define a funtion pointer type

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Array2D.h"
#include "Exception.h"

bool test_default_ctor();
bool test_2arg_ctor();
bool test_copy_ctor();
bool test_resize_row_0();
bool test_resize_row();
bool test_resize_row_large();
bool test_resize_col_0();
bool test_resize_col();
bool test_resize_col_large();
bool test_outofbounds_row_before();
bool test_outofbounds_row_after();
bool test_outofbounds_col_before();
bool test_outofbounds_col_after();


// Array of test functions
FunctionPointer test_functions[] = { test_default_ctor, test_2arg_ctor, test_copy_ctor,
test_resize_row_0, test_resize_row, test_resize_row_large, 
test_resize_col_0, test_resize_col, test_resize_col_large, test_outofbounds_row_before, 
test_outofbounds_row_after,  test_outofbounds_col_before, test_outofbounds_col_after };

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool tests_passed;

	// Run the test functions
	for each (FunctionPointer func in test_functions)
	{
		if (func())
		{
			cout << " passed\n" << endl;
		}
		else
		{
			cout << "***** failed *****\n";
		}
	}

	cout << "\nPress Any Key to Exit";
	cin.get();

}
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//		SIMPLE FUNCTIONS
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool test_default_ctor()
{
	bool pass = true;
	int default_length = 0;

	Array2D<int> my2Darray;
	 
	int length = my2Darray.getColumn() * my2Darray.getRow();

	if (length != default_length) // if the length of the array doesn't = 0
		pass = false;//pass = false

	cout << "Default ctor test ";
	return pass;
}

bool test_2arg_ctor()
{
	bool pass = false;
	
	Array2D<int> my2Darray(2,2); // creates the 2Darray
	
	//create data in the space
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3; 
	my2Darray[1][1] = 4;

	int length = my2Darray.getColumn() * my2Darray.getRow();


	if (length == 4) //if the array length is 4 then it made a 2X2 array
		pass = true;

	 my2Darray.Display();

	cout << "2arg ctor test ";
	return pass;
}

bool test_copy_ctor()
{
	bool pass = true;
	int num_data = 4;

	Array2D<int> my2Darray(2, 2); // creates a 2D array

	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;

	Array2D<int> my2Darray2(my2Darray); // creates a 2D array out of the old array
	
	cout << "Orginal array: ";
	my2Darray.Display();
	cout << "Copy ctor array: ";
	my2Darray2.Display();

	cout << "Copy ctor: ";

	return pass;
}

bool test_resize_row_0()
{
	bool pass = false;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();
	
	cout << "resizing rows to 0" << endl;

	try
	{
		my2Darray.setRow(-1);
	}
	catch (Exception & exception)
	{
		pass = true;
	}

	cout << "Resize row test below zero: ";

	return pass;
}

bool test_resize_row()
{
	bool pass = true;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "resizing rows to 1" << endl;

	try
	{
		my2Darray.setRow(1);
	}
	catch (Exception & exception)
	{
		pass = false;
	}

	cout << "New sized array: ";
	my2Darray.Display();


	cout << "Resize row test in range: ";

	return pass;
}

bool test_resize_row_large()
{
	bool pass = true;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "resizing rows to 1" << endl;

	try
	{
		my2Darray.setRow(10);
	}
	catch (Exception & exception)
	{
		pass = false;
	}

	cout << "New sized array: ";
	my2Darray.Display();


	cout << "Resize row test larger than current row: ";

	return pass;
}

bool test_resize_col_0()
{
	bool pass = false;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "resizing rows to -1" << endl;

	try
	{
		my2Darray.setColumn(-1);
	}
	catch (Exception & exception)
	{
		pass = true;
	}

	cout << "Resize column test below zero: ";

	return pass;
}

bool test_resize_col()
{
	bool pass = true;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "resizing columns to 1" << endl;

	try
	{
		my2Darray.setColumn(1);
	}
	catch (Exception & exception)
	{
		pass = false;
	}

	cout << "New sized array: ";
	my2Darray.Display();


	cout << "Resize column test in range: ";

	return pass;
}

bool test_resize_col_large()
{
	bool pass = true;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "resizing columns to 10" << endl;

	try
	{
		my2Darray.setColumn(10);
	}
	catch (Exception & exception)
	{
		pass = false;
	}

	cout << "New sized array: ";
	my2Darray.Display();


	cout << "Resize column test larger: ";

	return pass;
}

bool test_outofbounds_row_before()
{
	bool pass = false;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "Accessing row out of bounds (-1, 0)" << endl;
	try
	{
		my2Darray.Select(-1,0);
	}
	catch (Exception & exception)
	{
		pass = true;
	}

	cout << "Test row out of bounds before beginning of Array: ";

	return pass;
}

bool test_outofbounds_row_after()
{
	bool pass = false;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "Accessing row out of bounds (2, 0)" << endl;
	try
	{
		my2Darray.Select(2, 0);
	}
	catch (Exception & exception)
	{
		pass = true;
	}

	cout << "Test row out of bounds after ending of Array: ";

	return pass;
}

bool test_outofbounds_col_before()
{
	bool pass = false;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "Accessing col out of bounds (0, -1)" << endl;
	try
	{
		my2Darray.Select(0, -1);
	}
	catch (Exception & exception)
	{
		pass = true;
	}

	cout << "Test col out of bounds before beginning of Array: ";

	return pass;
}

bool test_outofbounds_col_after()
{
	bool pass = false;

	Array2D<int> my2Darray(2, 2); // creates a 2D array
	my2Darray[0][0] = 1;
	my2Darray[0][1] = 2;
	my2Darray[1][0] = 3;
	my2Darray[1][1] = 4;
	cout << "Orginal array: ";
	my2Darray.Display();


	cout << "Accessing column out of bounds (0, 2)" << endl;
	try
	{
		my2Darray.Select(0, 3);
	}
	catch (Exception & exception)
	{
		pass = true;
	}

	cout << "Test col out of bounds after ending of Array: ";

	return pass;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//		COMPLEX FUNCTIONS
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////

//bool test_default_ctor()
//{
//	bool pass = true;
//	int default_length = 0;
//
//	Array2D<string> my2Darray;
//
//
//	if (my2Darray.getArray().GetLength() != default_length) // if the length of the array doesn't = 0
//		pass = false;//pass = false
//
//	cout << "Default ctor test ";
//	return pass;
//}
//
//bool test_2arg_ctor()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//								  //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//
//	if (my2Darray.getArray().GetLength() == 4) //if the array length is 4 then it made a 2X2 array
//		pass = true;
//
//		my2Darray.Display();
//
//	cout << "2arg ctor test ";
//	return pass;
//}
//
//bool test_copy_ctor()
//{
//	bool pass = true;
//	int num_data = 4;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//
//	Array2D<string> my2Darray2(my2Darray); // creates a 2D array out of the old array
//
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//	cout << "Copy ctor array: ";
//	my2Darray.Display();
//
//
//	cout << "Copy ctor: ";
//
//	return pass;
//}
//
//bool test_resize_row_0()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "resizing rows to 0" << endl;
//
//	try
//	{
//		my2Darray.setRow(-1);
//	}
//	catch (Exception & exception)
//	{
//		pass = true;
//	}
//
//	cout << "Resize row test below zero: ";
//
//	return pass;
//}
//
//bool test_resize_row()
//{
//	bool pass = true;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "resizing rows to 1" << endl;
//
//	try
//	{
//		my2Darray.setRow(1);
//	}
//	catch (Exception & exception)
//	{
//		pass = false;
//	}
//
//	cout << "New sized array: ";
//	my2Darray.Display();
//
//
//	cout << "Resize row test in range: ";
//
//	return pass;
//}
//
//bool test_resize_row_large()
//{
//	bool pass = true;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "resizing rows to 1" << endl;
//
//	try
//	{
//		my2Darray.setRow(10);
//	}
//	catch (Exception & exception)
//	{
//		pass = false;
//	}
//
//	cout << "New sized array: ";
//	my2Darray.Display();
//
//
//	cout << "Resize row test larger than current row: ";
//
//	return pass;
//}
//
//bool test_resize_col_0()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "resizing rows to -1" << endl;
//
//	try
//	{
//		my2Darray.setColumn(-1);
//	}
//	catch (Exception & exception)
//	{
//		pass = true;
//	}
//
//	cout << "Resize column test below zero: ";
//
//	return pass;
//}
//
//bool test_resize_col()
//{
//	bool pass = true;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "resizing columns to 1" << endl;
//
//	try
//	{
//		my2Darray.setColumn(1);
//	}
//	catch (Exception & exception)
//	{
//		pass = false;
//	}
//
//	cout << "New sized array: ";
//	my2Darray.Display();
//
//
//	cout << "Resize column test in range: ";
//
//	return pass;
//}
//
//bool test_resize_col_large()
//{
//	bool pass = true;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "resizing columns to 10" << endl;
//
//	try
//	{
//		my2Darray.setColumn(10);
//	}
//	catch (Exception & exception)
//	{
//		pass = false;
//	}
//
//	cout << "New sized array: ";
//	my2Darray.Display();
//
//
//	cout << "Resize column test larger: ";
//
//	return pass;
//}
//
//bool test_outofbounds_row_before()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "Accessing row out of bounds (-1, 0)" << endl;
//	try
//	{
//		my2Darray.Select(-1, 0);
//	}
//	catch (Exception & exception)
//	{
//		pass = true;
//	}
//
//	cout << "Test row out of bounds before beginning of Array: ";
//
//	return pass;
//}
//
//bool test_outofbounds_row_after()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "Accessing row out of bounds (2, 0)" << endl;
//	try
//	{
//		my2Darray.Select(2, 0);
//	}
//	catch (Exception & exception)
//	{
//		pass = true;
//	}
//
//	cout << "Test row out of bounds after ending of Array: ";
//
//	return pass;
//}
//
//bool test_outofbounds_col_before()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "Accessing col out of bounds (0, -1)" << endl;
//	try
//	{
//		my2Darray.Select(0, -1);
//	}
//	catch (Exception & exception)
//	{
//		pass = true;
//	}
//
//	cout << "Test col out of bounds before beginning of Array: ";
//
//	return pass;
//}
//
//bool test_outofbounds_col_after()
//{
//	bool pass = false;
//
//	Array2D<string> my2Darray(2, 2); // creates the 2Darray
//
//									 //create data in the space
//	my2Darray[0][0] = "Hey ";
//	my2Darray[0][1] = "whats ";
//	my2Darray[1][0] = "happening ";
//	my2Darray[1][1] = "now?";
//	cout << "Orginal array: ";
//	my2Darray.Display();
//
//
//	cout << "Accessing column out of bounds (0, 2)" << endl;
//	try
//	{
//		my2Darray.Select(0, 3);
//	}
//	catch (Exception & exception)
//	{
//		pass = true;
//	}
//
//	cout << "Test col out of bounds after ending of Array: ";
//
//	return pass;
//}