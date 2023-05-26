def get_employee_performance(points):
    if points >= 70:
        return "Good"
    elif points >= 50:
        return "Neutral"
    else:
        return "Bad"

def ask_question(question, points):
    answer = input(question + " (Yes/No): ")
    if answer.lower() == "yes":
        return points
    return 0

# Define the questions and their corresponding points
questions = [
    ("Does the employee meet project deadlines?", 10),
    ("Does the employee actively contribute in team meetings?", 5),
    ("Is the employee open to learning new technologies?", 8),
    ("Does the employee take initiative in solving problems?", 7),
    ("Does the employee demonstrate strong communication skills?", 6),
    ("Is the employee receptive to feedback and suggestions?", 7),
    ("Does the employee work well with others in a team?", 8),
    ("Does the employee show commitment towards assigned tasks?", 9),
    ("Does the employee show enthusiasm for work?", 6),
    ("Does the employee demonstrate a high level of professionalism?", 9)
]

# Initialize the total points
total_points = 0

# Ask each question and calculate the total points
for question, points in questions:
    total_points += ask_question(question, points)

# Determine the employee performance
performance = get_employee_performance(total_points)

# Print the performance analysis
print("Employee Performance: ", performance)
