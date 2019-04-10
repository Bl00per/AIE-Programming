#include <iostream>
#include <Windows.h>
#include <conio.h>

// IN APPLICATION 1 - The host of the named shared memory

struct MyData {
	int i; 
	float f; 
	char c[13];
	bool b; 
	double d;
};

int main()
{
	MyData myData = { 99, 7.56f, "Hello world!", false, 69.42 };

	// open a named shared memory block
	HANDLE fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/wrte access control
		0, sizeof(MyData), // size of the memory block,
		(LPCSTR)L"MySharedMemory"
	);
	if (fileHandle == nullptr)
	{
		std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
		return 1;
	}
	else
	{
		std::cout << "You're looking at the wrong program bruv" << std::endl;
	}

	// Map the memory from the shared block to a pointer we can manipulate
	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));

	if (data == nullptr)
	{
		std::cout << "Could not map view of file: " << GetLastError() << std::endl;
		CloseHandle(fileHandle);
		return 1;
	}

	// Write to the memory block
	*data = myData;

	// Wait for a keypress to close
	_getch();

	// Unmap the memory block since we're done with it
	UnmapViewOfFile(data);

	// Close the shared file
	CloseHandle(fileHandle);

	return 0;
}