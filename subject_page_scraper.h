#include <tidy.h>
#include <tidybuffio.h>

#ifndef __SUBJECT_PAGE_SCRAPER__
#define __SUBJECT_PAGE_SCRAPER__

#define PREREQUISITES_TAG "<em>Prerequisite:</em>"
#define COREQUISITES_TAG "<em>Corequisite:</em>"
#define EQUIVALENCIES_TAG "<em>Equivalencies:</em>"
#define EQUIVALENCY_TAG "<em>Equivalency:</em>"

typedef struct subject_page_scraper {
  char* url;
  size_t num_courses;
  int* subject_codes;
} subject_page_scraper_t;

size_t course_subject_buffer_callback(
    char* buffer, 
    size_t size, 
    size_t num_members, 
    TidyBuffer* tidy_buffer
);
void parse_node_for_descriptions(TidyDoc doc, TidyBuffer* tidy_buffer, TidyNode node);

char* split(char* str, const char* delim);
char* trim_white_space(char* str);
void get_requisites(
    char** course_description, 
    char** prerequisites, 
    char** corequisites, 
    char** equivalency
);

void update_each_course(TidyBuffer* tidy_buffer, size_t* num_courses, int* subject_codes);
void update_courses(subject_page_scraper_t* subject_page_scraper);

#endif
