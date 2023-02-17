
# Code design


# Data

## Input
- An global const float: [taxPercentage], default 8%
- An amount of price from user: a float: [price]

## Output
- A float that are the Nearest rounded in fraction part, 
which represent the amount of price that was added tax: [taxPrice]


# Code flow
<!-- Main flow -->
## Main
- > `Print` instruction to user what this program is about
- > `Ask` user to enter the [price]
- > `Calculate` the price after added tax, `Assign` to [taxPrice]
- > `Print` [taxPrice] out
- > Exit program

## calTaxPrice
- > `Take` a float number [price]
- > `Calculate` [taxPrice] by multiple [price] with [taxPercentage] and added to [price]
- > `Return` [taxPrice]

<!-- start without rounded -->
