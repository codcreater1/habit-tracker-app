#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Habit {
protected:
    string name;
    int totalDays;
    bool isComplicated;
    int successCount;

public:
    Habit(string name, bool isComplicated)
        : name(name), isComplicated(isComplicated), totalDays(0), successCount(0) {
    }

    virtual void markCompleted() {
        totalDays++;
        successCount++;
    }

    virtual void showStats() const {
        cout << "Habit: " << name << endl;
        cout << "Total Days: " << totalDays << endl;
        cout << "Success Count: " << successCount << endl;
        if (totalDays > 0)
            cout << "Success Rate: " << (successCount * 100.0) / totalDays << "%" << endl;
        else
            cout << "No data yet." << endl;
        cout << "Is Complicated: " << (isComplicated ? "Yes" : "No") << endl;
    }

    string getName() const {
        return name;
    }

    int getTotalDays() const {
        return totalDays;
    }

    int getSuccessCount() const {
        return successCount;
    }

    virtual ~Habit() {}
};

class SimpleHabit : public Habit {
public:
    SimpleHabit(string name, bool isComplicated)
        : Habit(name, isComplicated) {
    }

    void markCompleted() override {
        totalDays++;
        successCount++;
        cout << "Simple habit marked as completed." << endl;
    }

    void showStats() const override {
        cout << "Simple Habit: " << name << endl;
        cout << "Total Days: " << totalDays << endl;
        cout << "Success Count: " << successCount << endl;
        cout << "Is Complicated: " << (isComplicated ? "Yes" : "No") << endl;
    }
};

class ComplexHabit : public Habit {
public:
    ComplexHabit(string name, bool isComplicated)
        : Habit(name, isComplicated) {
    }

    void markCompleted() override {
        totalDays++;
        if (totalDays % 2 == 0) {
            successCount++;
        }
    }

    void showStats() const override {
        cout << "Complex Habit: " << name << endl;
        cout << "Total Days: " << totalDays << endl;
        cout << "Success Count: " << successCount << endl;
        if (totalDays > 0)
            cout << "Success Rate: " << (successCount * 100.0) / totalDays << "%" << endl;
        else
            cout << "No data yet." << endl;
        cout << "Is Complicated: " << (isComplicated ? "Yes" : "No") << endl;
    }
};

struct Human {
    string name;
    vector<Habit*> habitsList;

    void addHabit(Habit* habit) {
        habitsList.push_back(habit);
    }

    void showAllHabits() const {
        for (auto habit : habitsList) {
            habit->showStats();
            cout << "----" << endl;
        }
    }

    void showHabitStatsByIndex(int index) const {
        if (index < 0 || index >= (int)habitsList.size()) {
            cout << "Invalid habit index!" << endl;
            return;
        }
        habitsList[index]->showStats();
    }

    void showLowSuccessHabits() const {
        cout << "=== Habits with Success Rate Below 50% ===" << endl;
        bool found = false;
        for (auto habit : habitsList) {
            int total = habit->getTotalDays();
            double rate = 0;
            if (total > 0) {
                rate = (habit->getSuccessCount() * 100.0) / total;
            }
            if (rate < 50) {
                habit->showStats();
                cout << "----" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Great! No habits with low success rate found :))" << endl;
        }
    }

    void deleteHabits() {
        for (auto habit : habitsList) {
            delete habit;
        }
        habitsList.clear();
    }
};

int main() {
    Human user;
    cout << "Enter your name: ";
    getline(cin, user.name);

    int habitCount;
    cout << "How many habits do you want to add? ";
    cin >> habitCount;
    cin.ignore();

    for (int i = 0; i < habitCount; i++) {
        string habitName;
        string type;
        Habit* habit;

        cout << "Enter name of your habit " << (i + 1) << ": ";
        getline(cin, habitName);

        cout << "Is this habit complex (yes/no): ";
        getline(cin, type);

        if (type == "yes" || type == "Yes") {
            habit = new ComplexHabit(habitName, true);
        }
        else {
            habit = new SimpleHabit(habitName, false);
        }

        user.addHabit(habit);
    }

    user.showLowSuccessHabits();

    cout << user.name << "'s Habits:" << endl;
    user.showAllHabits();

    bool continueMarking = true;
    while (continueMarking) {
        cout << "Choose an action: [mark/save/exit]: ";
        string action;
        getline(cin, action);

        if (action == "mark") {
            for (auto& habit : user.habitsList) {
                habit->markCompleted();
            }
            cout << "One day marked for all habits." << endl;
            user.showAllHabits();
        }
        else if (action == "save") {
           
            cout << "Your progress has been saved successfully. See you again!" << endl;
        }
        else if (action == "exit") {
            cout << "Exiting program. SEE U NEXT TIME STAY WITH GOOD HABITS: " << user.name << "!" << endl;
            break;
        }
        else {
            cout << "Invalid action. Please enter 'mark', 'save' or 'exit'." << endl;
        }
    }

    cout << "Your habits list:" << endl;
    for (int i = 0; i < (int)user.habitsList.size(); i++) {
        cout << i << ": " << user.habitsList[i]->getName() << endl;
    }

    cout << "Select a habit index to see details: ";

    int selectedIndex;
    cin >> selectedIndex;
    cin.ignore();

    user.showHabitStatsByIndex(selectedIndex);

    user.deleteHabits();

    return 0;
}
