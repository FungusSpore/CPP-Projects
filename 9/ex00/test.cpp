#include <cstring>
#include <ctime>
#include <iterator>
#include <map>
#include <iostream>


template <typename T>
struct tmComparitor {
	bool operator() (const T& lhs, const T& rhs) const{
		if (lhs.tm_year != rhs.tm_year)
			return (lhs.tm_year < rhs.tm_year);
		if (lhs.tm_mon != rhs.tm_mon)
			return (lhs.tm_mon < rhs.tm_mon);
		return (lhs.tm_mday < rhs.tm_mday);
	// 	return (std::tie(lhs.tm_year, lhs.tm_mon, lhs.tm_mday) \ < std::tie(rhs.tm_year, rhs.tm_mon, rhs.tm_mday));
	}
};

int main(void){
	std::map<tm, float, tmComparitor<tm> > database;

	tm date1;
	tm date2;
	tm date3;
	tm date4;

	std::memset(&date1, 0, sizeof(tm));
	std::memset(&date2, 0, sizeof(tm));
	std::memset(&date3, 0, sizeof(tm));
	std::memset(&date4, 0, sizeof(tm));

	date1.tm_year = 2025 - 1900;
	date1.tm_mday = 30;
	date1.tm_mon = 12 - 1;

	date2.tm_year = 2025 - 1900;
	date2.tm_mday = 20;
	date2.tm_mon = 2 - 1;

	date3.tm_year = 2025;
	date3.tm_mday = 20;
	date3.tm_mon = 2;

	date4.tm_year = 2026;
	date4.tm_mday = 123;
	date4.tm_mon = 1235;

	std::cout << date4.tm_year << std::endl;
	std::cout << date4.tm_mon << std::endl;
	std::cout << date4.tm_mday << std::endl;

	tm temp = date4;

	std::cout << temp.tm_year << std::endl;
	std::cout << temp.tm_mon << std::endl;
	std::cout << temp.tm_mday << std::endl;

	time_t datetime;
	if ((datetime = mktime(&date4)) == -1)
		std::cout << "error" << std::endl;
	std::cout << datetime << std::endl;

	std::cout << date4.tm_year << std::endl;
	std::cout << date4.tm_mon << std::endl;
	std::cout << date4.tm_mday << std::endl;

	if (date4.tm_year != temp.tm_year || date4.tm_mon != temp.tm_mon || date4.tm_mday != temp.tm_mday)
		std::cout << "date 4 changed" << std::endl;

	temp = date2;
	if ((datetime = mktime(&date2)) == -1)
		std::cout << "error" << std::endl;
	std::cout << datetime << std::endl;

	if (date2.tm_year != temp.tm_year || date2.tm_mon != temp.tm_mon || date2.tm_mday != temp.tm_mday)
		std::cout << "date 2 changed" << std::endl;

	database[date1] = 1;
	database[date2] = 2;
	database[date3] = 3;

	std::map<tm, float>::iterator it = database.begin();
	for (; it != database.end(); it++){
		std::cout << it->second << std::endl;
	}
}
