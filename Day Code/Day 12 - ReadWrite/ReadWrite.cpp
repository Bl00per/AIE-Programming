#include <iostream>
#include <fstream>

struct bookDetails
{
	char title[40];
	char author[40];
	char publisher[30];
	int yearpublished;
	double price;
};

void WriteRecordToFile(bookDetails *bookrecord);
void ReadRecordToConsole(int recordNumber);

int main() {

	bookDetails newBook = {
		"Harry Potter", //title
		"J.K Rowling", //author
		"Bloombury", //publisher
		1997, //year published
		8.99, //price
	};

	bookDetails newBook2 = {
		"Lord of the Rings", //title
		"J.R.R Tolkien", //author
		"Bloombury", //publisher
		1954, //year published
		15.99, //price
	};

	//WriteRecordToFile(&newBook);
	//WriteRecordToFile(&newBook2);

	ReadRecordToConsole(1);


	system("pause");
	return 0;
}

void WriteRecordToFile(bookDetails *bookrecord) {
	std::ofstream file("data.dat", std::ios::in | std::ios::out | std::ios::binary);

	if (file.good()) {
		std::cout << "File data.dat opened successfully\n";

	}
	else {
		std::ofstream file("data.dat", std::ios::out | std::ios::binary);
		std::cout << "creating data.dat\n";
		file.close();

		WriteRecordToFile(bookrecord);
		return;
	}

	file.seekp(0, std::ios::end);
	file.write((char*)bookrecord, sizeof(bookDetails));

	file.close();
}

void ReadRecordToConsole(int recordNumber) {
	bookDetails readBookRecord;

	//open file from both read and write so you can seek
	std::ifstream file("data.dat", std::ios::in | std::ios::out | std::ios::binary);

	if (file.good()) {
		file.seekg(recordNumber * sizeof(bookDetails), std::ios::beg);
		file.read((char*)&readBookRecord, sizeof(bookDetails));

		std::cout << readBookRecord.title << "\n";
		std::cout << readBookRecord.author << "\n";
		std::cout << readBookRecord.publisher << "\n";
		std::cout << readBookRecord.yearpublished << "\n";
		std::cout << readBookRecord.price << "\n";

	}
	else {
		std::cout << "Error opening file\n";
	}

	file.close();
}