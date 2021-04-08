# Cringe Word
**Simple word guessing game where user will be given a random word with shuffle letters and user have to guess what word it is.**

## v0.0.1
### Changes
----
- Main Menu
- Input handler for main menu
- Added 50 words
- Game instructions on how to play
- Input handler for game
- Shuffle algorithm for both word list and letters
- Quit command (user can quit game anytime while playing by typing quit)

### Improvements
---
- input handler for both main menu and game
- shuffle algorithm

### Fixes
---
- Dynamic memory storage error
- Unhandled user input which cause unexpected infinite loop

## v0.1.2
### Changes
---
- Add game point

### Game Point
---
**Now a user need to maintain game point in order to play longer. Default game point is ```110``` and it will increase by ```3``` or decrease by ```5``` based on win or lose respectively.**

## Fixes
- Fix letters shuffle incorrectly
- Fix main function initialization 
- Fix some functions to work correctly
