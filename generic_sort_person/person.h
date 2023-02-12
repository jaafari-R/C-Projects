#include <stddef.h>

struct Person
{
    unsigned m_id;
    char m_name[16];
    unsigned char m_age;
};

/*  Used to sort person array, passed to sortPersonArray function
    */
enum PersonSortBy{
    ID = 0,
    NAME,
    AGE
};

/*  returns a person with the parameters set as attributes
    if the name passed is longer than 15 characters, only the first 15 are assigned
    */
struct Person newPerson(unsigned id, const char * name, unsigned char age);

/*  Sorts a person array using buble sort,
    based on Id, Name or Age, passed as sort_by of type PersonSortBy
    */
void sortPersonArray(struct Person person_arr[], size_t arr_size, enum PersonSortBy sort_by);

/*  Sorts a person array using C Standard Library qsort,
    based on Id, Name or Age, passed as sort_by of type PersonSortBy
    */
void sortPersonArraySTD(struct Person person_arr[], size_t arr_size, enum PersonSortBy sort_by);
