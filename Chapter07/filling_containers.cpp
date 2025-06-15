#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

struct meme {
    string description;
    size_t year;
};

istream& operator>>(istream &is, meme &m) {
    return is >> quoted(m.description) >> m.year;
}

istream& operator >>(istream &is, pair<string, meme> &p) {
    return is >> quoted(p.first) >> p.second;
}

int main()
{
    map<string, meme> m;

    copy(istream_iterator<pair<string, meme>>{cin}, {}, inserter(m, end(m)));

    auto max_func ([](size_t old_max, const auto &b) {
        return max(old_max, b.first.length());
    });
    const size_t width {accumulate(begin(m), end(m), 0u, max_func)};

    for (const auto &[meme_name, meme_desc] : m) {
        const auto &[desc, year] = meme_desc;

        cout << left << setw(width) << meme_name
             << " : " << desc
             << ", " << year << '\n';
    }
    return 0;
}


int main1()
{
    std::stringstream ss;
    std::string in = "String with spaces, and embedded \"quotes\" too";
    std::string out;
    std::string out1;

    auto show = [&](const auto& what) {
        &what == &in
            ?   std::cout << "read in     [" << in << "]\n"
                          << "stored as   [" << ss.str() << "]\n"
            :   std::cout << "written out [" << out << "]\n\n";
    };

    ss << std::quoted(in);
    show(in);
    ss >> std::quoted(out);
    show(out);
    ss << in;
    ss >> std::quoted(out1);
    show(out1);

    ss.str(""); // clear the stream buffer

    in = "String with spaces, and embedded $quotes$ too";
    const char delim {'$'};
    const char escape {'%'};

    ss << std::quoted(in, delim, escape);
    show(in);
    ss >> std::quoted(out, delim, escape);
    show(out);
    return 0;
}
