# Exercise

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
