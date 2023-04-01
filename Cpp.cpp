#include "rsvp.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;



int main()
{
    std::list<RSVP> rsvps;

    int choice = 2;
    while (choice)
    {
        cout << "\nMenu:\n";
        cout << "0. Done\n";
        cout << "1. Add new\n";
        cout << "2. View list\n";
        cout << "3. Total count\n";
        cout << "4. Cancel\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1: {
            RSVP rsvp;
            rsvp.initialize();
            rsvps.push_back(rsvp);
            break;
        }
        case 2: {
            rsvps.sort([](const RSVP& x, const RSVP& y) {
                return x.total_size() < y.total_size();
                });
            cout << "\n";
            for_each(rsvps.begin(), rsvps.end(),
                [](auto& rsvp) {
                    rsvp.display();
                }
            );
            break;
        }
        case 3: {
            float total_count = accumulate(rsvps.begin(), rsvps.end(), 0.0f,
                [](auto accumulator, auto& rsvp) {
                    return accumulator + rsvp.total_size();
                });
            cout << "Total number of people: " << total_count << "\n";
            break;
        }
        case 4: {
            std::string name;
            cout << "Enter name: ";
            cin >> name;
            auto end = remove_if(rsvps.begin(), rsvps.end(), [name](auto& rsvps) {
                return rsvps.get_name() == name;
                });
            rsvps.erase(end, rsvps.end());
            break;
        }

        }
    }
}

