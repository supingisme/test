/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void qsort (void *array, size t count, size t size, comparison fn t [Function]
 * compare)
 * The qsort function sorts the array array. The array contains count elements, each of
 * which is of size size.
 * The compare function is used to perform the comparison on the array elements. This
 * function is called with two pointer arguments and should return an integer less than,
 * equal to, or greater than zero corresponding to whether its frst argument is considered
 * less than, equal to, or greater than its second argument.
 * Warning: If two objects compare as equal, their order after sorting is unpredictable.
 * That is to say, the sorting is not stable. This can make a diﬀerence when the compar
 * ison considers only part of the elements. Two elements with the same sort key may
 * diﬀer in other respects.
 *
 */
/* Defne an array of critters to sort. */
struct critter
{
	const char *name;
	const char *species;
};
struct critter muppets[] =
{
	{"Kermit", "frog"},
	{"Piggy", "pig"},
	{"Gonzo", "whatever"},
	{"Fozzie", "bear"},
	{"Sam", "eagle"},
	{"Robin", "frog"},
	{"Animal", "animal"},
	{"Rongtao", "sport"},
	{"RenShanshan", "cute"},
	{"Camilla", "chicken"},
	{"Sweetums", "monster"},
	{"Dr. Strangepork", "pig"},
	{"Link Hogthrob", "pig"},
	{"Zoot", "human"},
	{"RT&RSS", "love"},
	{"Dr. Bunsen Honeydew", "human"},
	{"Beaker", "human"},
	{"Swedish Chef", "human"}
};
int count = sizeof (muppets) / sizeof (struct critter);
/* This is the comparison function used for sorting and searching. */

int
critter_cmp (const struct critter *c1, const struct critter *c2)
{
	return strcmp (c1->name, c2->name);
}
/* Print information about a critter. */
void
print_critter (const struct critter *c)
{
	printf ("%s, the %s\n", c->name, c->species);
}
/* Do the lookup into the sorted array. */
void
find_critter (const char *name)
{
	struct critter target, *result;
	target.name = name;
	result = bsearch (&target, muppets, count, sizeof (struct critter),
			critter_cmp);
	if (result)
		print_critter (result);
	else
		printf ("Couldn’t find %s.\n", name);
}
/* Main program. */
int
main (void)
{
	int i;
	for (i = 0; i < count; i++)
		print_critter (&muppets[i]);
	printf ("\n");
	qsort (muppets, count, sizeof (struct critter), critter_cmp);
	for (i = 0; i < count; i++)
		print_critter (&muppets[i]);
	printf ("\n");
	find_critter ("Kermit");
	find_critter ("Gonzo");
	find_critter ("RT&RSS");
	find_critter ("Janice");
	return 0;
}
/*The output from this program looks like:
 * Kermit, the frog
 * Piggy, the pig
 * Gonzo, the whatever
 * Fozzie, the bear
 * Sam, the eagle
 * Robin, the frog
 * Animal, the animal
 * Camilla, the chicken
 * Sweetums, the monster
 * Dr. Strangepork, the pig
 * Link Hogthrob, the pig
 * Zoot, the human
 * Dr. Bunsen Honeydew, the human
 * Beaker, the human
 * Swedish Chef, the human
 * Animal, the animal
 * Beaker, the human
 * Camilla, the chicken
 * Dr. Bunsen Honeydew, the human
 * Dr. Strangepork, the pig
 * Fozzie, the bear
 * Gonzo, the whatever
 * Kermit, the frog
 * Link Hogthrob, the pig
 * Piggy, the pig
 * Robin, the frog
 * Sam, the eagle
 * Swedish Chef, the human
 * Sweetums, the monster
 * Zoot, the human
 * Kermit, the frog
 * Gonzo, the whatever
 * Couldn’t find Janice.
 *
 */











