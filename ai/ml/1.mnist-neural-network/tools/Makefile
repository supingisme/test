ALL:
	gcc -o extract_test_information_from_mnist_db extract_test_information_from_mnist_db.c  
	gcc -o fix_image fix_image.c `pkg-config --cflags --libs opencv` 
	gcc -o get_grayscale_values_image get_grayscale_values_image.c `pkg-config --cflags --libs opencv` 
	gcc -o resize_image resize_image.c `pkg-config --cflags --libs opencv` 
	gcc -o rgb_to_grayscale rgb_to_grayscale.c  `pkg-config --cflags --libs opencv` 
	gcc -o show_image show_image.c `pkg-config --cflags --libs opencv` 
clean:
	rm *~ *.o

