def medical_expert_system():
    print("🏥 Welcome to the Health Expert System 🏥")
    print("Please answer the following questions with 'yes' or 'no'.\n")

    fever = input("Do you have a fever? ").lower()
    cough = input("Do you have a cough? ").lower()
    breath = input("Are you experiencing difficulty in breathing? ").lower()
    sore_throat = input("Do you have a sore throat? ").lower()
    body_pain = input("Are you feeling body pain or fatigue? ").lower()
    headache = input("Do you have a headache? ").lower()

    print("\n🩺 Diagnosis:")

    if fever == "yes" and cough == "yes" and breath == "yes":
        print("- Possible Condition: COVID-19 or Respiratory Infection")
        print("- Advice: Visit the hospital immediately and get tested.")
    
    elif fever == "yes" and body_pain == "yes" and headache == "yes":
        print("- Possible Condition: Dengue or Viral Infection")
        print("- Advice: Consult a doctor soon and take blood tests if necessary.")
    
    elif sore_throat == "yes" and cough == "yes" and fever == "no":
        print("- Possible Condition: Common Cold or Mild Flu")
        print("- Advice: Home rest, stay hydrated, and monitor your symptoms.")
    
    elif fever == "yes" and sore_throat == "yes":
        print("- Possible Condition: Flu or Throat Infection")
        print("- Advice: Take warm fluids and consult a doctor if symptoms worsen.")
    
    else:
        print("- No major symptoms detected.")
        print("- Advice: Maintain a healthy lifestyle and regular monitoring.")

    print("\n✅ Thank you for using the Health Expert System. Stay Safe!")

# Run the system
medical_expert_system()
