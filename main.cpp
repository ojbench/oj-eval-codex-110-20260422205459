// Problem 110 - 小恶魔的生日 (ACMOJ 1073)
// Implements a Date class with construction validation,
// increment/decrement, date arithmetic, comparison, and output.

#include <bits/stdc++.h>
using namespace std;

namespace {
    inline bool is_leap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    inline int month_days(int y, int m) {
        static const int md[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if (m == 2) return md[m] + (is_leap(y) ? 1 : 0);
        return md[m];
    }

    inline bool valid_date(int y, int m, int d) {
        if (y < 1 || m < 1 || m > 12) return false;
        int md = month_days(y, m);
        return d >= 1 && d <= md;
    }

    // Convert date to days since an epoch (1900-01-01 -> 0)
    inline long long days_from_1900(int y, int m, int d) {
        long long days = 0;
        // accumulate years
        for (int yy = 1900; yy < y; ++yy) days += is_leap(yy) ? 366 : 365;
        // accumulate months
        for (int mm = 1; mm < m; ++mm) days += month_days(y, mm);
        days += (d - 1);
        return days;
    }

    inline void ymd_from_days(long long x, int &y, int &m, int &d) {
        // x is days since 1900-01-01 (0-based). Support negative x as well.
        y = 1900;
        if (x >= 0) {
            while (true) {
                int yr_days = is_leap(y) ? 366 : 365;
                if (x >= yr_days) { x -= yr_days; ++y; }
                else break;
            }
            m = 1;
            while (true) {
                int md = month_days(y, m);
                if (x >= md) { x -= md; ++m; }
                else break;
            }
            d = int(x) + 1;
        } else {
            // Move years backward until x within current year
            while (true) {
                int prev_year = y - 1;
                int yr_days = is_leap(prev_year) ? 366 : 365;
                if (-x > yr_days) { x += yr_days; --y; }
                else break;
            }
            // Now we are within previous year span (possibly still negative)
            // Start from end of previous year
            --y;
            m = 12;
            int md = month_days(y, m);
            long long rem = (long long)md + x; // x is negative, md + x in [0, md-1]
            while (rem < 0) {
                x += md; // consume month
                --m;
                if (m == 0) { m = 12; --y; }
                md = month_days(y, m);
                rem = (long long)md + x;
            }
            d = int(rem) + 1;
        }
    }
}

class Date {
private:
    int _year;
    int _month;
    int _day;

    void set_default() {
        _year = 1900; _month = 1; _day = 1;
    }

public:
    Date(): _year(1900), _month(1), _day(1) {}
    Date(int y, int m, int d) {
        if (valid_date(y, m, d)) { _year = y; _month = m; _day = d; }
        else set_default();
    }

    // Pre-increment: next day
    Date& operator++() {
        long long t = days_from_1900(_year, _month, _day) + 1;
        ymd_from_days(t, _year, _month, _day);
        return *this;
    }
    // Post-increment
    Date operator++(int) {
        Date tmp = *this;
        ++(*this);
        return tmp;
    }
    // Pre-decrement: previous day
    Date& operator--() {
        long long t = days_from_1900(_year, _month, _day) - 1;
        ymd_from_days(t, _year, _month, _day);
        return *this;
    }
    // Post-decrement
    Date operator--(int) {
        Date tmp = *this;
        --(*this);
        return tmp;
    }

    // date + integer days
    Date operator+(long long days) const {
        long long t = days_from_1900(_year, _month, _day) + days;
        int y, m, d; ymd_from_days(t, y, m, d);
        return Date(y, m, d);
    }
    // date - integer days
    Date operator-(long long days) const {
        long long t = days_from_1900(_year, _month, _day) - days;
        int y, m, d; ymd_from_days(t, y, m, d);
        return Date(y, m, d);
    }
    // date - date => absolute days between
    long long operator-(const Date& other) const {
        long long a = days_from_1900(_year, _month, _day);
        long long b = days_from_1900(other._year, other._month, other._day);
        long long diff = a - b;
        return diff >= 0 ? diff : -diff;
    }
    // comparison
    bool operator<(const Date& other) const {
        if (_year != other._year) return _year < other._year;
        if (_month != other._month) return _month < other._month;
        return _day < other._day;
    }

    friend ostream& operator<<(ostream& os, const Date& dt) {
        os << dt._year << '-' << dt._month << '-' << dt._day;
        return os;
    }
};

static void Test() {
    int op; if (!(cin >> op)) return;
    int yy, mm, dd;
    if (op == 1 || op == 0) {
        Date d0;
        Date d1(2000, 2, 29);
        Date d2(1900, 2, 29);
        cout << d0 << '\n';
        cout << d1 << '\n';
        cout << d2 << '\n';
        //d0.out(); d1.out(); d2.out();
    }
    if (op == 2 || op == 0) {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        for (int i = 0; i < 5; ++i) cout << ++d0 << '\n';
        for (int i = 0; i < 5; ++i) cout << d0++ << '\n';
        for (int i = 0; i < 5; ++i) cout << d0-- << '\n';
        for (int i = 0; i < 2; ++i) cout << --d0 << '\n';
        cout << d0 << '\n';
        //d0.out();
    }
    if (op == 3 || op == 0) {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        cout << d0 + 100 << '\n';
        cout << d0 - 1000 << '\n';
    }
    if (op == 4 || op == 0) {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        Date d1(2020, 12, 21);
        cout << (d0 < d1) << '\n';
    }
    if (op == 5 || op == 0) {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        Date d1(1912, 6, 23);
        cout << (d0 - d1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Test();
    return 0;
}
