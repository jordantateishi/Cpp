#pragma once
#include <string>

class RSVP
{
private:
	std::string name;
	int group_size;
	static int next_id;

public:
	RSVP();

	RSVP(int id_number, std::string name, int group_size);

	void initialize();

	void display() const;

	int total_size() const;

	std::string get_name();

};