#include <iostream>
#include <string>
#include <algorithm>

void chatbot() {
    std::cout << "Welcome to ShopEasy Customer Support Bot!" << std::endl;
    std::cout << "How can I help you today?" << std::endl;
    std::cout << "Type 'exit' to end the chat.\n" << std::endl;
    
    std::string user_input;
    
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, user_input);
        
        // Convert to lowercase for case-insensitive comparison
        std::string lower_input = user_input;
        std::transform(lower_input.begin(), lower_input.end(), lower_input.begin(), ::tolower);
        
        if (lower_input == "exit") {
            std::cout << "Bot: Thank you for chatting with us! Have a nice day!" << std::endl;
            break;
        }
        else if (lower_input.find("order") != std::string::npos && 
                 lower_input.find("status") != std::string::npos) {
            std::cout << "Bot: Please provide your Order ID to check the status." << std::endl;
        }
        else if (lower_input.find("refund") != std::string::npos) {
            std::cout << "Bot: Our refund policy allows returns within 30 days. Refunds are processed within 5-7 business days." << std::endl;
        }
        else if (lower_input.find("contact") != std::string::npos || 
                 lower_input.find("support") != std::string::npos) {
            std::cout << "Bot: You can contact our support team at support@shopeasy.com or call 1800-123-456." << std::endl;
        }
        else if (lower_input.find("return") != std::string::npos) {
            std::cout << "Bot: You can initiate a return from your 'My Orders' section on our website or app." << std::endl;
        }
        else if (lower_input.find("hello") != std::string::npos || 
                 lower_input.find("hi") != std::string::npos) {
            std::cout << "Bot: Hello! How can I assist you today?" << std::endl;
        }
        else {
            std::cout << "Bot: I'm sorry, I didn't understand that. Can you please rephrase?" << std::endl;
        }
    }
}

int main() {
    chatbot();
    return 0;
}