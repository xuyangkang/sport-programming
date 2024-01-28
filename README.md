# sport-programming
Xuyang's repository for sport programming

## Guideline

* Python for easy problems
* C++ for difficult ones
* Production level quality


## Dependencies
[bazel](https://bazel.build/)

Follow the install instruction. I use openSUSE so:
```
sudo zypper install bazel
```

[cpplint](https://github.com/cpplint/cpplint)

Install with
```
pip install cpplint
```

## Test
```
bazel test //cpp:all
```

## Lint
```
cpplint --recursive --filter=-legal ./
```
