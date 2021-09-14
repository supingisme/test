typedef struct {
    // User defined data may be declared here.
	sem_t b;
	sem_t c;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
	sem_init(&obj->b, 0, 0);
	sem_init(&obj->c, 0, 0);
    return obj;
}



void first(Foo* obj) {
	
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&obj->b);
}

void second(Foo* obj) {
    sem_wait(&obj->b);
	
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&obj->c);
}

void third(Foo* obj) {
    sem_wait(&obj->c);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    sem_destroy(&obj->b);
    sem_destroy(&obj->c);
    free(obj);
}

