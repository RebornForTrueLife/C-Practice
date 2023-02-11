
# Code design


### Main pipeline

> `Fetch` data needed to run program (name of units, factor need to convert)
> `Print` out the list of convertable units
> `Ask` user to `Input` a choice number(short_integer)
> `Ask` user to `Input` the amount of chosen unit(float)
> `Calculate` the result
> `Print` the result out
> `Exit`

### Data
> EngUnitList: `global` `string` `array` 2 dimensions of English unit, contain list of unit name(string), one dim for long and one for short name
> MetricList: `global` `string` `array` 2 dimensions of corresponding Metric, contain list of coresponding metric name, , one dim for long and one for short name
> FactorList: `global` `float` `array` of factors to convert corresponding units(by index) 
> choice: an `short integer`, which is chosen index of 4 arrays
> amount: a `float`, which is amount of chosen unit

### In `Func` **convertUnit**(`Calculate`):
> `Input` an short-int: 'choice', a float: 'amount'
> Multiple 'amount' with corresponding factor
> return the result 

### `Func` to initial data: names of convertable units and corresponding fators

