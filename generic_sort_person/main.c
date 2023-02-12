#include <stdio.h>

#include "person.h"

void printPeople(struct Person people[], size_t p_size);

int main()
{
    struct Person people[3] =
    {
        {0, "Zed", 15},
        {1, "Amitai", 35},
        {2, "FoFo", 10}
    };
    
    printf("Start Order (by id)\n");
    printPeople(people, 3);

    sortPersonArray(people, 3, AGE);
    printf("AGE Order\n");
    printPeople(people, 3);

    sortPersonArray(people, 3, NAME);
    printf("NAME order\n");
    printPeople(people, 3);

    sortPersonArray(people, 3, ID);
    printf("ID order \n");
    printPeople(people, 3);

    sortPersonArraySTD(people, 3, AGE);
    printf("AGE Order\n");
    printPeople(people, 3);

    sortPersonArraySTD(people, 3, NAME);
    printf("NAME order\n");
    printPeople(people, 3);

    sortPersonArraySTD(people, 3, ID);
    printf("ID order \n");
    printPeople(people, 3);

    return 0;
}


void printPeople(struct Person people[], size_t p_size)
{
    for(size_t i = 0; i < p_size; ++i)
        printf("ID: %u, Name: %s, %u years old.\n", people[i].m_id, people[i].m_name, people[i].m_age);
}