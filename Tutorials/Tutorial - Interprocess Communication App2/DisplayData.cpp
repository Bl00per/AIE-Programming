#include <iostream>
#include <Windows.h>
#include <conio.h>


struct MyData{ 
	int i; 
	float f; 
	char c[13]; 
	bool b; 
	double d; 
};

int main()
{
	// IN APPLICATION 2 - A user of the named shared memory
	// gain access to a named shared memory block that already exists
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, (LPCSTR)L"MySharedMemory");

	if (fileHandle == nullptr)
	{
		std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
		return 1;
	}

	// Map the memory from the shared block to a pointer we can manipulate
	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));

	if (data == nullptr)
	{
		std::cout << "Could not map view of file: " << GetLastError() << std::endl;
		CloseHandle(fileHandle);
		return 1;
	}

	// Write out what is in the memory block
	std::cout << "MyData = { ";
	std::cout << data->i << ", ";
	std::cout << data->f << ", ";
	std::cout << data->c << ", ";
	std::cout << data->b << ", ";
	std::cout << data->d;
	std::cout << " };" << std::endl;

	// Wait for a keypress to close
	_getch();

	// Unmap the memory block since we're done with it
	UnmapViewOfFile(data);

	// Close the shared file
	CloseHandle(fileHandle);

	return 0;
}