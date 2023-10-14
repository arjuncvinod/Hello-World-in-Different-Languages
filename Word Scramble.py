import random

def choose_word():
    # List of words for the game
    words = ["PYTHON", "JAVA", "JAVASCRIPT", "RUBY", "CPLUSPLUS", "HTML"]
    
    # Choose a random word from the list
    return random.choice(words)

def scramble_word(word):
    # Scramble the letters of the word
    word_chars = list(word)
    random.shuffle(word_chars)
    return ''.join(word_chars)

def play_game():
    secret_word = choose_word().upper()  # Choose a random word and convert to uppercase
    scrambled_word = scramble_word(secret_word)  # Scramble the word
    
    print("Welcome to Word Scramble Game!")
    print("Unscramble the letters to form a meaningful word.")
    print("Scrambled word:", scrambled_word)
    
    while True:
        user_guess = input("Your guess: ").upper()
        
        if user_guess == secret_word:
            print("Congratulations! You guessed the word correctly:", secret_word)
            break
        else:
            print("Incorrect guess. Try again.")

if __name__ == "__main__":
    play_game()
