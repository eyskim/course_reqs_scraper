# Multithreaded UBC Course Info Web Scraper

<p align="center">
  <img alt="License" src="https://img.shields.io/github/license/eyskim/course_reqs_scraper">
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/eyskim/course_reqs_scraper">
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/eyskim/course_reqs_scraper">
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/eyskim/course_reqs_scraper">
  <img alt="Lines of code" src="https://img.shields.io/tokei/lines/github/eyskim/course_reqs_scraper">
</p>

<p align="center">
  <img alt="GitHub followers" src="https://img.shields.io/github/followers/eyskim?style=social">
</p>

A simple web scraper to retrieve UBC course information as provided by http://www.calendar.ubc.ca/vancouver/courses.cfm?page=name and saved to a MongoDB database.

## Getting Started

`mongo-c-driver` is required to run the program. For more information and installation: https://github.com/mongodb/mongo-c-driver.

In addition, an environment variable - `$MONGO_URI` - with your MongoDB database URI should be set for use by the program. For example, if your MongoDB URI is `mongodb+srv://user:password.mongodb.net`, your environment variable should be set as `MONGO_URI=mongodb+srv://user:password.mongodb.net`. This is the database in which all course data will be saved. 

By default, the database name is `course_reqs_db` and  the collection name is `courses`. This can be found (and renamed) in `subject_page_scraper.c`. 

### Building & Running the Program

A Makefile is included to simplify the build process. In short, to build and run the program: 

```shell
git clone git@github.com:eyskim/course_reqs_scraper.git
cd course_reqs_scraper/
make clean
make
./main
```

By default, if no argument is passed to the program, it will run with 1 thread. You can also specify the number of threads you want to run the program with as an argument. For example:

```
make
./main 4
```

This will run the program with 4 threads in a thread pool.

## Features

Overall, the program is broken down into three main features:

1. Retrieve links to each course subject page from http://www.calendar.ubc.ca/vancouver/courses.cfm?page=name.

2. Retrieve each course and its information from each subject page.
    - ex. http://www.calendar.ubc.ca/vancouver/courses.cfm?page=name&code=ADHE for all ADHE course information.

3. Save all course data to a MongoDB database.

To speed up the process to retrieve and save course information, there is an option to use multiple threads in a thread pool - `tpool.c`. This will parallelize the process of saving each subject's courses.

### Upcoming

- Correctly parsed pre/co-requisites and equivalent course information

## Contributing

If you'd like to contribute, please fork the repository and use a feature branch. Pull requests are welcome.

## Links

- Repository: https://github.com/eyskim/course_reqs_scraper/
- Issue tracker: https://github.com/eyskim/course_reqs_scraper/issues
  - In case of sensitive bugs like security vulnerabilities, please contact `erickim195@gmail.com` directly instead of using issue tracker. Thank you for your efforts to improve the security and privacy of this project!
- Related projects (coming soon):

## Licensing

The code in this project is licensed under MIT license.
