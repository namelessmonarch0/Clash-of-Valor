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

    ifstream n("stats2.json");
    json jsonPatch = json::parse(n);

    data["/quiz/q1/question"_json_pointer];

    // auto x = data.at("quiz").at("sport").at("q1").at("options").at(0);

    data["quiz"]["maths"]["q2"]["answer"] = 10;

    return 0;
}