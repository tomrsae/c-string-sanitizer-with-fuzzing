# C String Sanitizer with fuzzing
The sanitizing program was initially created as a submission for exercise 4 in the subject IDATT2503 at NTNU.

This modified version, with fuzzer and address sanitization is created and submitted as exercise 5 in the same subject.

# Tests
The first task was to write a fuzz test for the program we submitted in the last exercise.

There is only one simple test that takes in a lot of bytes, converts it into a C-style string and then uses the sanitizer to escape the characters: `<`, `>` and `&`.

## CI Pipeline
The second task was to create a CI solution that uses fuzzing with address sanitization.

The CI pipeline may be found under [Actions](https://github.com/tomrsae/c-string-sanitizer-with-fuzzing/actions) and it simply builds and runs the fuzz tests.

# Building and running
To build and run the original program, run the following command from the project root:
```
gcc -o input_sanitizer input_sanitizer.c && ./input_sanitizer
```
To build and run the tests, run the following command from the `{project_root}/tests` directory:
```
clang -g -O1 -fsanitize=fuzzer,address input_sanitizer_fuzz_test.c && ./a.out
```