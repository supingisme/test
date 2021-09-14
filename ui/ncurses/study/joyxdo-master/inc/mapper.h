
/* interface to module mapper.c */

#ifndef JOYXDO_MAPPER_H
#define JOYXDO_MAPPER_H

void xdo_down(const char *key_string);
void xdo_up(const char *key_string);
bool init_mapper(void);
void kill_mapper(void);

#endif
