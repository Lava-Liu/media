#include <stdio.h>
#include "team.h"
#include <string.h>

int main(void)
{
	member m;
	m.id = TEACHER;
	m.person.t.code=1000;
	strcpy(m.person.t.name,"liuwei");
	m.person.t.salary=1000;
	m.person.t.age=22;
	add_member(&m);
	query();
}
