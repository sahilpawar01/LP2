# airline_scheduling.py

class AirlineScheduling:
    def __init__(self):
        self.flights = []
        self.cargo = []

    def schedule_flight(self):
        flight_number = input("Enter flight number: ")
        destination = input("Enter destination: ")
        self.flights.append({"flight_number": flight_number, "destination": destination})
        print(f"🛫 Flight {flight_number} scheduled to {destination}!\n")

    def schedule_cargo(self):
        cargo_id = input("Enter cargo ID: ")
        try:
            weight = float(input("Enter cargo weight (kg): "))
            self.cargo.append({"cargo_id": cargo_id, "weight": weight})
            print(f"📦 Cargo {cargo_id} of {weight}kg scheduled!\n")
        except ValueError:
            print("❌ Invalid input. Weight must be a number.\n")

def main():
    asch = AirlineScheduling()
    print("=== ✈️ Welcome to Airline Scheduling and Cargo Management ✈️ ===\n")
    while True:
        print("Choose an option:\n1. Schedule Flight\n2. Schedule Cargo\n3. Exit")
        choice = input("Enter choice (1/2/3): ")
        if choice == '1':
            asch.schedule_flight()
        elif choice == '2':
            asch.schedule_cargo()
        elif choice == '3':
            print("👋 Exiting Airline Scheduling System.")
            break
        else:
            print("❌ Invalid choice. Try again!\n")

if __name__ == "__main__":
    main()
