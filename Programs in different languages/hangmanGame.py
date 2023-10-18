our_word=input("Player 1 enter you guessing word in caps:")
guess=7
name=input("player 2 enter your name:")
print("Hello",name,"welcome to hangman game!!!")
print("lets start playing!!")
print("Your number of letter's is:")
ls=['_']*len(our_word)
print(ls)

while guess>0:
    g=input("give you guess:")
    j=''
    if g in our_word:
        l=0
        for j in our_word:
            if j==g:
                ls[l]=g
                print("Your guess is correct")
            l=l+1
    else:
        guess=guess-1
        print("your guess is wrong")
    print("You have",guess,"guesses remaining")
    print(ls)
    if ls==list(our_word):
        break
        

if ls==list(our_word):
    print("yay!! You have won")
else:
    print("Better luck next time")
    print("The answer is",our_word)