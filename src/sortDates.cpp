#include <string>
#include <vector>
#include <sstream>
#include <tuple>
#include <algorithm>

using namespace std;

// Parses a date string in MM-DD-YYYY format
tuple<int, int, int> parseDate(const string& dateStr) {
    int mm, dd, yyyy;
    char dash;
    stringstream ss(dateStr);
    ss >> mm >> dash >> dd >> dash >> yyyy;
    return make_tuple(yyyy, mm, dd);  // for proper chronological comparison
}

// Comparator for sorting table rows by date in column index 1
bool comp(const vector<string>& a, const vector<string>& b) {
    return parseDate(a[1]) < parseDate(b[1]);
}

// Sorts the table data by date
vector<vector<string>> sortByDate(vector<vector<string>> tabledata) {
    sort(tabledata.begin(), tabledata.end(), comp);
    return tabledata;
}
