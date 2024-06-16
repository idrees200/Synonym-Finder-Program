# Synonym Finder Program

This C++ program allows users to enter pairs of words and their synonyms. It then tokenizes a user-provided text and replaces matching words with their synonyms.

## Features

- **Input**: Users enter the number of word-synonym pairs and then provide each word and its synonym.
- **Tokenization**: Takes a user-provided text input and tokenizes it into separate words.
- **Synonym Replacement**: Checks if any word in the tokenized text matches a word from the input pairs. If so, it replaces the word with its synonym.
- **Output**: Displays the entered words and their synonyms. Also shows the tokenized text with replaced synonyms.

## Usage

1. **Input Words and Synonyms**:
   - Enter the number of word-synonym pairs.
   - For each pair, enter a word and its synonym.

2. **Text Input**:
   - Enter a text for which you want to replace words with synonyms.

3. **Output**:
   - Displays the entered words and their synonyms.
   - Shows the tokenized text with replaced synonyms.

## Example

Suppose you input:
- Number of pairs: 3
- Pairs: { "happy" -> "joyful", "sad" -> "unhappy", "hot" -> "warm" }
- Text: "I feel happy today but sad because it's hot."

The program would output:
ENTERED WORDS ARE :
happy
sad
hot

ENTERED SYNONYMS ARE :
joyful
unhappy
warm

TOKENIZATION :
I
feel
happy
today
but
sad
because
it's
hot

CHANGED ARRAY :
I
feel
joyful
today
but
unhappy
because
it's
warm
