import datetime

def get_response(message):
    # Define the rules and responses
    rules = {
        "date": {"response": lambda: f"The current date is {datetime.date.today()}"},
        "time": {"response": lambda: f"The current time is {datetime.datetime.now().time()}"},
        "what is your name?": {"response": "I am a chatbot. You can call me ChatBot."},
        "how old are you?": {"response": "I am a computer program, so I don't have an age."},
        "where are you from?": {"response": "I exist in the digital real, so I don't have a physical location."},
        "how are you?": {"response": "I'm good. Thanks for asking!"},
        "what can you do?": {"response": "I can answer questions, provide the current date and time, and have basic conversations."},
        "what is the meaning of life?": {"response": "The meaning of life is subjective and can vary for each individual."},
        "hi": {"response": "Hello! How can I assist you?"},
        "hello": {"response": "Hello! How can I assist you?"},
        "hey": {"response": "Hello! How can I assist you?"}
    }

    # Check if the message matches any rule
    for rule, response in rules.items():
        if message.lower() == rule:
            if callable(response["response"]):
                return response["response"]()

    # Default response for unknown questions
    return "I'm sorry, I don't know the answer to that question."

# Main chat loop
while True:
    user_input = input("User: ")

    # Check for exit condition
    if user_input.lower() == "exit":
        break

    bot_response = get_response(user_input)
    print("ChatBot:", bot_response)