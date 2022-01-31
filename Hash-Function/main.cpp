#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <algorithm>


unsigned int HashFunction(const std::string& input) {
    unsigned int hash_value = 0;
    for (const auto& c : input)
    {
        hash_value = hash_value * 1313 + (unsigned char)c;
    }
    return hash_value;
}

unsigned int BadHashFunction(const std::string& input) {
    unsigned int hash_value = 0;
    for (const auto& c : input)
    {
        hash_value += (unsigned char)c;
    }
    return hash_value;
}

int menu();
int main() {

    struct Info
    {
        std::string key;
        long int age;
        std::string address;
    };

    std::vector<Info> data (3);

    std::ifstream infile("info.txt", std::ios::in);
    while (!infile.eof())
    {
        std::string line;
        std::getline(infile, line);
        std::istringstream is{ line };

        std::string name;
        std::string age;
        std::string address;

        getline(is, name, ',');
        getline(is, age, ',');
        getline(is, address);

        data.push_back(Info{ name, strtol(age.c_str(),nullptr,10) , address});
    }

    //hash count
    constexpr int buckets = 6;
    std::vector < std::vector<Info> >hash_map;
    hash_map.resize(buckets);

    //fill in the hash map
    for (auto& i : data)
    {
        unsigned int hash = HashFunction(i.key) % hash_map.size();
        hash_map[hash].push_back(i);
    }

        for (auto choice(menu()); choice != 2; choice = menu())
        {
            switch (choice)
            {
                case 1:
                {

                    std::string search_key;
                    /*cout << endl << endl << "Enter search key " << endl;*/
                    std::cin >> search_key;

                    //hash count
                    auto now = std::chrono::high_resolution_clock::now();
                    unsigned int bucket_number = HashFunction(search_key) % hash_map.size();
                    auto& bucket = hash_map[bucket_number];

                    //int info = find_if(bucket.begin(), bucket.end(), [&](const Info& i) {return i.key == search_key; })->phone;
                    int dob = -1;
                    std::string location;
                    for (auto& i : bucket)
                    {
                        if (i.key == search_key)
                        {
                            dob = i.age;
                            location = i.address;
                            break;
                        }
                    }

                    auto duration_hash = std::chrono::high_resolution_clock::now() - now;

                    if (dob != -1)
                    {
                        std::cout << "I found " << search_key << " age " << dob << " address " << location << std::endl;
                    }
                    else
                    {
                        std::cout << search_key << " not found" << std::endl;
                    }
                    std::cout << "It took " << std::chrono::duration_cast<std::chrono::microseconds>(duration_hash).count() << " ms for the hash search" << std::endl;

                    break;
                }
            }
        }
    }

int menu()
{
    std::cout << " \n1. Enter search key" << std::endl;
    std::cout << "2. Quit!" << std::endl;

    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.bad()) {
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cout << "Bad input" << std::endl;
        }
        else break;
    }
    return choice;
}