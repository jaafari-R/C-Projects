#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "../include/string_functions/string_functions.h"


/* compare functions for sortPersonArray */


/* swap person function, swaps two person values */
void swapPerson(struct Person * p1, struct Person * p2)
{
    // Swap id
    p1->m_id ^= p2->m_id;
    p2->m_id ^= p1->m_id;
    p1->m_id ^= p2->m_id;

    // swap age
    p1->m_age ^= p2->m_age;
    p2->m_age ^= p1->m_age;
    p1->m_age ^= p2->m_age;
    
    // Swap name
    string_swap(p1->m_name, p2->m_name, 16);
}

/* returns true if the first person has a higher id */
static bool comparePersonId(const struct Person p1, const struct Person p2)
{
    return p1.m_id > p2.m_id;
}

/* returns true if the first person has a higher order alphabitic name */
static bool comparePersonName(const struct Person p1, const struct Person p2)
{
    return (0 < string_compare(p1.m_name, p2.m_name));
}

/* returns true if the first person is older than the second */
static bool comparePersonyAge(const struct Person p1, const struct Person p2)
{
    return p1.m_age > p2.m_age;
}

/* compare functions array */
static bool (*comparePerson[3]) (const struct Person p1, const struct Person p2) =
{
    comparePersonId,
    comparePersonName,
    comparePersonyAge
};


/* compare functions for sortPersonArray using standard c methods */


/* returns true if the first person has a higher id */
static int comparePersonIdSTD(const void * p1, const void * p2)
{
    return (*(struct Person*)p1).m_id > (*(struct Person*)p2).m_id;
}

/* returns true if the first person has a higher order alphabitic name */
static int comparePersonNameSTD(const void * p1, const void * p2)
{
    return (0 < strcmp((*(struct Person*)p1).m_name, (*(struct Person*)p2).m_name));
}

/* returns true if the first person is older than the second */
static int comparePersonyAgeSTD(const void * p1, const void * p2)
{
    return (*(struct Person*)p1).m_age > (*(struct Person*)p2).m_age;
}

/* compare functions array */
static int (*comparePersonSTD[3]) (const void * p1, const void * p2) =
{
    comparePersonIdSTD,
    comparePersonNameSTD,
    comparePersonyAgeSTD
};


/* Person functions */


struct Person newPerson(unsigned id, const char name[16], unsigned char age)
{
    struct Person person;
    person.m_id = id;
    string_copy(name, person.m_name, 16);
    person.m_age = age;
    return person;
}

void sortPersonArray(struct Person person_arr[], size_t arr_size, enum PersonSortBy sort_by)
{
    size_t i, j;
    size_t size_minus_sorted = arr_size - 1;
    for(i = 0; i < arr_size; i++)
    {
        for(j = 0; j < size_minus_sorted; j++)
        {
            if(comparePerson[sort_by](person_arr[j], person_arr[j + 1]))
                swapPerson(&person_arr[j], &person_arr[j + 1]);
        }
        size_minus_sorted--;
    }

}

void sortPersonArraySTD(struct Person person_arr[], size_t arr_size, enum PersonSortBy sort_by)
{
    size_t i, j;
    size_t size_minus_sorted = arr_size - 1;

    qsort(person_arr, arr_size, sizeof(struct Person), comparePersonSTD[sort_by]);
}