# employee_performance_evaluation.py

class EmployeePerformance:
    def __init__(self):
        self.scores = {}

    def add_score(self):
        name = input("Enter employee name: ")
        try:
            score = int(input(f"Enter performance score for {name} (0-100): "))
            self.scores[name] = score
            print(f"✅ Score for {name} added successfully!\n")
        except ValueError:
            print("❌ Invalid input. Please enter a number.\n")

    def evaluate(self):
        name = input("Enter employee name to evaluate: ")
        score = self.scores.get(name)
        if score is None:
            print("❌ Employee not found.\n")
            return
        if score >= 85:
            performance = "🌟 Excellent"
        elif score >= 70:
            performance = "👍 Good"
        elif score >= 50:
            performance = "👌 Average"
        else:
            performance = "⚠️ Needs Improvement"
        print(f"Performance of {name}: {performance}\n")

def main():
    ep = EmployeePerformance()
    print("=== 🧑‍💼 Welcome to Employee Performance Evaluation System 🧑‍💼 ===\n")
    while True:
        print("Choose an option:\n1. Add Score\n2. Evaluate Employee\n3. Exit")
        choice = input("Enter choice (1/2/3): ")
        if choice == '1':
            ep.add_score()
        elif choice == '2':
            ep.evaluate()
        elif choice == '3':
            print("👋 Exiting Employee Performance Evaluation System.")
            break
        else:
            print("❌ Invalid choice. Try again!\n")

if __name__ == "__main__":
    main()
