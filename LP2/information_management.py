# information_management.py

class InformationManagement:
    def __init__(self):
        self.data = {}

    def add_info(self):
        key = input("Enter the information title: ")
        value = input("Enter the information detail: ")
        self.data[key] = value
        print(f"✅ Information '{key}' added successfully!\n")

    def get_info(self):
        key = input("Enter the title you want to search: ")
        print("Result:", self.data.get(key, "❌ Information not found.\n"))

def main():
    im = InformationManagement()
    print("=== 📚 Welcome to Information Management System 📚 ===\n")
    while True:
        print("Choose an option:\n1. Add Information\n2. Get Information\n3. Exit")
        choice = input("Enter choice (1/2/3): ")
        if choice == '1':
            im.add_info()
        elif choice == '2':
            im.get_info()
        elif choice == '3':
            print("👋 Exiting Information Management System.")
            break
        else:
            print("❌ Invalid choice. Try again!\n")

if __name__ == "__main__":
    main()
