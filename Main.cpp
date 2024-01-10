#include <iostream>
#include <string>
#include <fstream> // fstream - file stream (�������� �����)
// ofstream - output file stream (����� ������ � ����)
// ifstream - input file stream (����� ����� �� �����)
// ����������� ����������, ���������� � ���� ������� � ������
// ��� ������ � �������� �������� ����������



bool statistic(std::string str);



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";

	// ����� ofstream ��� ������ � ����
	std::ofstream out; // ���������� ������� � ���� 
	out.open(path, std::ios::app); // �������� �����. ������ ����, ���� ��� �� ����������

	if (out.is_open()) { // �������� �������� �����
		std::cout << "���� ������ ��� ������.\n";
		std::string str;
		std::cout << "������� ������ -> ";
		std::getline(std::cin, str);
		out << str << '\n'; // ���������� ������ � ����
	}
	else {
		std::cout << "������ �������� �����!\n";
		// ��������� ������� ������ ��� �������� �����:
		// 1. ������������ ���� � �����;
		// 2. ��� ������� � �����;
		// 3. ���� ������ ������ �������� ��� ����������.
	}

	out.close(); // �������� �����



	// ����� ifstream ��� ������ �� �����
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "���� ������. ���������� �����:\n";
		std::string file;
		//  ������������ ����������
		//char sym;
		//while (in.get(sym)) {
		//	file += sym;
		//}
		//std::cout << file << std::endl;

		// ��������� ����������
		//while (!in.eof()) {
		//	std::string word;
		//	in >> word;
		//	file += word + '\n';
		//}
		//std::cout << file << std::endl;

		// ���������� ���������� 
		std::string str;
		while (std::getline(in, str)) {
			// if (str[0] == '#')
			file += str + '\n';
		}
		std::cout << file << std::endl;
	}

	else {
		std::cout << "������ �������� �����!\n";
		// ��������� ������� ������ ��� �������� �����:
		// 1. ������������ ���� � �����;
		// 2. ����� �� ����������;
		// 3. ��� ������ � �����.
	}

	in.close(); 



	// �������� ����� 
	//remove(path.c_str()); // ��������
	if (remove(path.c_str()) == 0) {
		std::cout << "���� �����.\n";
	}
	else {
		std::cout << "������ �������� �����.\n";
		// ��������� ������� ������ ��� �������� �����:
		// 1. ��� ������� � �����;
		// 2. ����� �� ����������;
		// 3. ���� ������ ������ �������� ��� ����������;
		// 4. ������������ ���� � �����.
	}



	// ������ 1. ���������� � ����.
	std::cout << "������� ������ -> ";
	std::string str1;
	std::getline(std::cin, str1);
	if (statistic(str1))
		std::cout << "������ ���������.\n";
	else
		std::cout << "������ ���������� ������.\n";


	return 0;
}


bool statistic(std::string str) {
	static std::ofstream out;
	out.open("stats.txt", std::ios::app);
	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	return false;
}