# helpdesk_management.py

class HelpDesk:
    def __init__(self):
        self.tickets = []

    def create_ticket(self):
        issue = input("Describe your issue: ")
        ticket_id = len(self.tickets) + 1
        self.tickets.append({"id": ticket_id, "issue": issue, "status": "open"})
        print(f"🎫 Ticket #{ticket_id} created successfully!\n")

    def resolve_ticket(self):
        try:
            ticket_id = int(input("Enter ticket ID to resolve: "))
            for ticket in self.tickets:
                if ticket["id"] == ticket_id:
                    ticket["status"] = "resolved"
                    print(f"✅ Ticket #{ticket_id} resolved!\n")
                    return
            print("❌ Ticket not found.\n")
        except ValueError:
            print("❌ Invalid input. Please enter a number.\n")

def main():
    hd = HelpDesk()
    print("=== 🛠️ Welcome to Help Desk Management System 🛠️ ===\n")
    while True:
        print("Choose an option:\n1. Create Ticket\n2. Resolve Ticket\n3. Exit")
        choice = input("Enter choice (1/2/3): ")
        if choice == '1':
            hd.create_ticket()
        elif choice == '2':
            hd.resolve_ticket()
        elif choice == '3':
            print("👋 Exiting Help Desk Management System.")
            break
        else:
            print("❌ Invalid choice. Try again!\n")

if __name__ == "__main__":
    main()
