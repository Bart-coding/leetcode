## Compress an array of characters "chars"
### For each group of consecutive repeating characters in "chars":
* if there's only one character in the group, just add that character at the begging of "chars" or (if there are already compressed characters) at the end of compressed characters substring
* if not, add also group's length after that character (if group contains > 9 characters, add the length digit by digit)
### Return the length of compressed characters substring in "chars".