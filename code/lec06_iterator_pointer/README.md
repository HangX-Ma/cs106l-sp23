# Practice with stream

We've created a `.csv` file containing some CS faculty, their university, and the year they graduated. Write a function called

```c++
std:: map<std::string, ...>createMap(std::string filename)
```

That takes this information and create a map that relates their name to a `struct` containing their university and year, where `...` is the type of the `struct` you use!

Then, write a function called

```c++
void printMap(std::map<std::string, ...>csMap)
```

that prints each professor and whether they' re a Stanford alum or not!

## Result

You can use the following command to test the code `lec06_readcsv.cpp`.

```bash
./make.sh
./readcsv lecture6_exercise_w23.csv
```

The output will be like this.

```bash
Professor [Chris Gregg] is [Stanford] alum
Professor [Chris Manning] is [not Stanford] alum
Professor [Chris Piech] is [not Stanford] alum
Professor [Cynthia Lee] is [Stanford] alum
Professor [Fei-Fei Li] is [Stanford] alum
Professor [Jerry Cain] is [not Stanford] alum
Professor [Julia Zelenski] is [not Stanford] alum
Professor [Keith Schwarz] is [not Stanford] alum
Professor [Mary Wootters] is [Stanford] alum
Professor [Moses Charikar] is [not Stanford] alum
Professor [Nick Parlante] is [not Stanford] alum
Professor [Nick Troccoli] is [not Stanford] alum
Professor [Nima Anari] is [Stanford] alum
Professor [Phil Levis] is [Stanford] alum
```
