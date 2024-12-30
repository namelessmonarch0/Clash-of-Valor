#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <fstream>
#include <iostream>
#include <string>

using json = nlohmann::json;
using namespace std;

int main()
{

    ifstream f("stats.json");
    json data = json::parse(f);

    ofstream o("pretty.json");
    o << setw(4) << data << std::endl;

    // json j;
    // j = data;

    ofstream out("stats.json");
    data["quiz"]["maths"]["q1"]["answer"] = false;
    data["quiz"]["sport"]["q1"]["answer"] = 3.14159;

    out << setw(4) << data << endl;

    return 0;
}