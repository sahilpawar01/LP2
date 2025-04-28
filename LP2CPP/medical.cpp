#include <iostream>
#include <string>
#include <algorithm>

void medical_expert_system() {
    std::cout << "🏥 Welcome to the Health Expert System 🏥" << std::endl;
    std::cout << "Please answer the following questions with 'yes' or 'no'.\n" << std::endl;
    
    std::string fever, cough, breath, sore_throat, body_pain, headache;
    
    std::cout << "Do you have a fever? ";
    std::cin >> fever;
    std::transform(fever.begin(), fever.end(), fever.begin(), ::tolower);
    
    std::cout << "Do you have a cough? ";
    std::cin >> cough;
    std::transform(cough.begin(), cough.end(), cough.begin(), ::tolower);
    
    std::cout << "Are you experiencing difficulty in breathing? ";
    std::cin >> breath;
    std::transform(breath.begin(), breath.end(), breath.begin(), ::tolower);
    
    std::cout << "Do you have a sore throat? ";
    std::cin >> sore_throat;
    std::transform(sore_throat.begin(), sore_throat.end(), sore_throat.begin(), ::tolower);
    
    std::cout << "Are you feeling body pain or fatigue? ";
    std::cin >> body_pain;
    std::transform(body_pain.begin(), body_pain.end(), body_pain.begin(), ::tolower);
    
    std::cout << "Do you have a headache? ";
    std::cin >> headache;
    std::transform(headache.begin(), headache.end(), headache.begin(), ::tolower);
    
    std::cout << "\n🩺 Diagnosis:" << std::endl;
    
    if (fever == "yes" && cough == "yes" && breath == "yes") {
        std::cout << "- Possible Condition: COVID-19 or Respiratory Infection" << std::endl;
        std::cout << "- Advice: Visit the hospital immediately and get tested." << std::endl;
    }
    else if (fever == "yes" && body_pain == "yes" && headache == "yes") {
        std::cout << "- Possible Condition: Dengue or Viral Infection" << std::endl;
        std::cout << "- Advice: Consult a doctor soon and take blood tests if necessary." << std::endl;
    }
    else if (sore_throat == "yes" && cough == "yes" && fever == "no") {
        std::cout << "- Possible Condition: Common Cold or Mild Flu" << std::endl;
        std::cout << "- Advice: Home rest, stay hydrated, and monitor your symptoms." << std::endl;
    }
    else if (fever == "yes" && sore_throat == "yes") {
        std::cout << "- Possible Condition: Flu or Throat Infection" << std::endl;
        std::cout << "- Advice: Take warm fluids and consult a doctor if symptoms worsen." << std::endl;
    }
    else {
        std::cout << "- No major symptoms detected." << std::endl;
        std::cout << "- Advice: Maintain a healthy lifestyle and regular monitoring." << std::endl;
    }
    
    std::cout << "\n✅ Thank you for using the Health Expert System. Stay Safe!" << std::endl;
}

int main() {
    medical_expert_system();
    return 0;
}