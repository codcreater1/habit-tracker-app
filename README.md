🧠 Habit Tracker Console App (C++)
A simple and extensible console-based habit tracker application written in modern C++. This program allows users to create and manage both simple and complex habits, track their progress, and analyze performance based on success rates.

🚀 Features
✅ Track multiple habits per user.

🔁 Mark habits as completed for each day.

📊 View statistics (total days, success count, success rate).

🔍 Filter and display habits with a low success rate.

🧠 Different logic for SimpleHabit and ComplexHabit types.

🗑️ Memory-safe deletion of all dynamically allocated habits.

💬 Interactive command-line interface.

🛠️ Technologies Used
C++17

OOP (Object-Oriented Programming)

Inheritance and Polymorphism

Standard Template Library (<vector>, <string>, <iostream>)

🧩 Habit Types
SimpleHabit
Every marked day is considered a success.

ComplexHabit
Only even-numbered completions are counted as successful (e.g., day 2, 4, 6...).

📸 Sample Output
yaml

Enter your name: Murat
How many habits do you want to add? 2
Enter name of your habit 1: Exercise
Is this habit complex (yes/no): no
Enter name of your habit 2: Meditation
Is this habit complex (yes/no): yes
=== Habits with Success Rate Below 50% ===
Great! No habits with low success rate found :))
Murat's Habits:
Simple Habit: Exercise
Total Days: 0
Success Count: 0
Is Complicated: No
----
Complex Habit: Meditation
Total Days: 0
Success Count: 0
Is Complicated: Yes
----
...
Choose an action: [mark/save/exit]:
📂 File Structure
bash
Kopyala
Düzenle
📁 HabitTracker/
└── main.cpp         # Main application logic
└── README.md        # Project description
🧪 How to Run
Clone the repo

bash
git clone https://github.com/yourusername/HabitTracker.git
cd HabitTracker
Compile

bash
g++ -std=c++17 -o habit main.cpp
Run

bash
./habit
📌 Future Improvements
⏳ Add date tracking per habit.

📁 File-based save/load functionality.

📱 Port to GUI or web application.

📈 Visual graphs of habit success trends.

🤝 Contributing
Pull requests are welcome! For major changes, please open an issue first to discuss your ideas.
