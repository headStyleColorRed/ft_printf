#                      FT_PRINTF

## Description

The function printf() produces output according to a format. 

## Return Value

Upon successful return, this function returns the number of characters printed (excluding the null byte used to end output to strings).

If an output error is encountered, a negative value is returned.

## Conversions

This handmade printf will accept the following conversions:
+ %c -> Character
+ %s -> String
+ %p -> Memory address
+ %d -> Integer
+ %i -> Integer
+ %u -> Unsigned Integer
+ %x -> Lowercase hexadecimal
+ %X -> Uppercase hexadecimal
+ %% -> Percent sign


## Flag characters

Minimun size will be managed and the character % can be followed by zero or more of the following flags: 
+ '-'
+ '0'
+ '.'
+ '*'


## Purpose
This is a [42 school](https://www.42madrid.com/) project that imitates part of printf's original behaviours but without memory management.