#include "rsvp.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;

RSVP::RSVP() : name(""), group_size(0)
{
}

RSVP::RSVP(int id_number, std::string name, int group_size) : name(name), group_size(group_size)
{
}

void RSVP::initialize()
{
	cout << "Name: ";
	cin >> name;
	cout << "Group size: ";
	cin >> group_size;
}

void RSVP::display() const
{
	cout << "Name: " << name << "	Number in party : " << group_size << "\n";
}

int RSVP::total_size() const
{
	return group_size;
}

std::string RSVP::get_name()
{
	return name;
}
