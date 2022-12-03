/*

����������� ������, ��� � ���� ����� ���� ��������� ����� (�.�. ����� ���� ���������� ������).
������������ map<std::string, Node>, �.�. ������ ���� � ������ ��������������� �������. Node ������ ������ �����.

addRoot(const std::string& rootName)
addNode(const std::string& parent,  const std::string& nodeName)
operator<< ��� ������ �� �����


//�������� ���������� ����� ����:
	Hello:
		brother:	
			rty5:
				rell:
		sister:
			rty6:
		Mother:
		Father:
			rty4


*/

#include "Header.h"
#include <iostream>
#include <map>

using namespace std;

int main() { //�������� ���������� �����
	tree a;
	a.AddRoot("Hello");
	a.AddNode("Hello","Brother");
	a.AddNode("Hello", "Sister");
	a.AddNode("Hello", "Father");
	a.AddNode("Hello", "Mother");
	
	a.AddNode("Brother", "Rty1");
	a.AddNode("Brother", "Rty2");
	a.AddNode("Brother", "Rty3");
	a.AddNode("Brother", "Rty4");
	a.AddNode("Brother", "Rty5");

	a.AddNode("Rty5", "Rty6");
	a.AddNode("Rty6", "a");
	a.AddNode("a", "b");
	a.AddNode("b", "c");

	cout << a;

	return 0;
}