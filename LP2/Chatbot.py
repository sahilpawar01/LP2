def chatbot():
    print("Welcome to ShopEasy Customer Support Bot!")
    print("How can I help you today?")
    print("Type 'exit' to end the chat.\n")

    while True:
        user_input = input("You: ").lower()

        if user_input == 'exit':
            print("Bot: Thank you for chatting with us! Have a nice day!")
            break

        elif "order" in user_input and "status" in user_input:
            print("Bot: Please provide your Order ID to check the status.")
        
        elif "refund" in user_input:
            print("Bot: Our refund policy allows returns within 30 days. Refunds are processed within 5-7 business days.")
        
        elif "contact" in user_input or "support" in user_input:
            print("Bot: You can contact our support team at support@shopeasy.com or call 1800-123-456.")
        
        elif "return" in user_input:
            print("Bot: You can initiate a return from your 'My Orders' section on our website or app.")
        
        elif "hello" in user_input or "hi" in user_input:
            print("Bot: Hello! How can I assist you today?")
        
        else:
            print("Bot: I'm sorry, I didn't understand that. Can you please rephrase?")
            

# Run the chatbot
chatbot()
