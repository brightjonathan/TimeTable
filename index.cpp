#include <iostream>
#include <map>
#include <string>

class Timetable {
private:
    std::map<std::pair<std::string, std::string>, std::string> schedule;

public:
    void addCourse(const std::string& day, const std::string& time, const std::string& course) {
        schedule[std::make_pair(day, time)] = course;
    }

    std::string getCourse(const std::string& day, const std::string& time) {
        auto it = schedule.find(std::make_pair(day, time));
        if (it != schedule.end()) {
            return it->second;
        } else {
            return "No course scheduled at this time.";
        }
    }
};

int main() {
    Timetable timetable;

    // Populate the timetable with sample data
    timetable.addCourse("Monday", "09:00", "COM 311");
    timetable.addCourse("Monday", "11:00", "COM 313");
    timetable.addCourse("Tuesday", "10:00", "GNS 301");
    timetable.addCourse("Wednesday", "13:00", "COM 314");
    timetable.addCourse("Thursday", "14:00", "COM 312");
    timetable.addCourse("Friday", "15:00", "STA 314");
    timetable.addCourse("Saturday", "09:00", "STA 311");

    std::string day, time;
    std::cout << "Enter the day (e.g., Monday): ";
    std::cin >> day;
    std::cout << "Enter the time (e.g., 09:00): ";
    std::cin >> time;

    std::string course = timetable.getCourse(day, time);
    std::cout << "You should be learning: " << course << std::endl;

    return 0;
}
