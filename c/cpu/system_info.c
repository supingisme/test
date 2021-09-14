/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <dirent.h>
#include <libgen.h>
#include <wait.h>

// Node structure - represents a node in the tree "skeleton" of the process hierarchy.
typedef struct Node {
	struct Node **children;
	struct Node *parent;
	int num_children;
} *Node;

// function prototypes /////////////////////////////////////////////////////
void sys(char *path);
void pids(char *path, int names);
int is_proc(char *name);
void sort_found_contents(char **found_contents, int size_contents);
int str2int(char *pid_str);
int get_pid(char *content);
void swap_contents(char **contents, int index_1, int index_2);
void swap_perm(int *perm, int index_1, int index_2);
int *sort_found_pids(char **found_contents, int size_contents);
void ps(char *path, int extended_action1, char *parent_id, int extended_action2);
char *extract_pid(char *contents);
char *extract_ppid(char *contents);
char *extract_state(char *contents);
char *extract_name(char *contents);
int *apply_perm(int *arr, int* perm, int length);
int contains_id(int *parent_ids_list, int parent_ids_list_size, int ppid);
void construct_tree(Node root, Node prev, int *input_data, int input_data_size, int num_children, int child_parse_index);
void traversal(Node root, int root_pid, char *root_pid_str);
void free_tree(Node root);
////////////////////////////////////////////////////////////////////////////


// main function
int main(int argc, char **argv)
{
	// parsing path to directory
	// default path is /proc
	char *path = "/proc";
	// If path argument is given and action is not equal to "forktree",
	// set path to passed path.
	if(argc >= 3 && strcmp(argv[1], "forktree") != 0) 
	{
		path = argv[2];
	}

	// If action argument is given...
	if(argc > 1) 
	{
		// sys action
		if(strcmp(argv[1], "sys") == 0)
		{
			sys(path);
		}

		// pids action
		else if(strcmp(argv[1], "pids") == 0)
		{
			int names = 0;
			pids(path, names);
		}

		// names action - special call of pids with names set equal to 1
		if(strcmp(argv[1], "names") == 0)
		{
			int names = 1;
			pids(path, names);
		}
		
		// ps action
		if(strcmp(argv[1], "ps") == 0)
		{
			// extended action - if fourth argument is given, display the process with
			// the passed pid and all its children (transitive closure)
			int extended_action1 = 0;
			char *parent_id = NULL;
			if(argc >= 4) {
				extended_action1 = 1;
				parent_id = argv[3];
			}
			ps(path, extended_action1, parent_id, 0);
		}

		// psext action
		if(strcmp(argv[1], "psext") == 0)
		{
			// extended action - if fourth argument is given, display the process with
			// the passed pid and all its children (transitive closure)
			int extended_action1 = 0;
			char *parent_id = NULL;
			if(argc >= 4) {
				extended_action1 = 1;
				parent_id = argv[3];
			}
			ps(path, extended_action1, parent_id, 1);
		}

		if(strcmp(argv[1], "forktree") == 0)
		{
			// Define array for storing data parsed from stdin.
			int *input_data = NULL;
			// Define array size counter.
			int input_data_size = 0;
			// Define temporary buffer for storing the current parsed value.
			int temp_buff;

			// See Assignment instructions for tree description syntax!
			// While scanner has read some bytes from stdin...
			while(scanf("%d", &temp_buff) > 0)
			{
				// Allocate memory for the next entry in the input_data array.
				input_data = (int*)realloc(input_data, (++input_data_size) * sizeof(int));
				// Put data from temp_buff into the newly allocated memory
				input_data[input_data_size - 1] = temp_buff;
			}

			// optional: print input data
			/*
		    for(int i = 0; i < input_data_size; i++)
		    {
		        printf((i == input_data_size - 1) ? "%d\n" : "%d ", input_data[i]);
		    }
		    printf("\n");
			*/

			// Initialize root node.
			Node root = (Node)malloc(sizeof(Node));
			// Get number of children of root.
			int num_children = input_data[0];
			// Construct tree on root.
			construct_tree(root, NULL, input_data, input_data_size, num_children, 1);

			// Get pid of root process.
			int root_pid = getpid();

			// Get string representation for root_pid (For exec call).
			char *root_pid_str;
			sprintf(root_pid_str, "%d", root_pid);

			// Traverse built tree and create process hierarchy that mimics the tree's structure.
			traversal(root, root_pid, root_pid_str);

			// Free memory allocated for process skeleton Nodes.
			free_tree(root);

		}

	}
	return 0;
}	


// sys: Display some system info obtained from the proc folder
void sys(char *path)
{	
	// Linux version ///////////////////

	// Compute working path.
	char *working_path = (char*)malloc((strlen(path) + strlen("/version"))*sizeof(char));
	working_path = strcpy(working_path, path);
	working_path = strcat(working_path, "/version");

	// Get file descriptor
	int fd = open(working_path, O_RDONLY);

	// Allocate string buffer
	char *buff = (char*)malloc(1024*sizeof(char));
	
	// Read file into buffer.
	read(fd, buff, 1024);

	// Move to first digit.
	int str_index = 0;
	while(!isdigit(buff[str_index]))
	{
		str_index++;
	}

	// Print Linux version.
	printf("Linux: ");
	while(!isspace(buff[str_index]))
	{
		putchar(buff[str_index]);
		str_index++;
	}
	putchar('\n');

	// GCC version //////////////////////
	// get to "version" substring
	while(strncmp(buff + str_index, "version", 7) != 0)
	{
		str_index++;
	}
	
	// get to digits
	while(!isdigit(buff[str_index]))
	{
		str_index++;
	}

	// print result 
	printf("gcc: ");
	while(!isspace(buff[str_index]))
	{
		putchar(buff[str_index]);
		str_index++;
	}
	// go to new line
	putchar('\n');

	// name of first swap partition /////////

	// compute new working path
	free(working_path);
	working_path = (char*)malloc((strlen(path) + strlen("/swaps"))*sizeof(char));
	working_path = strcpy(working_path, path);
	working_path = strcat(working_path, "/swaps");

	// Get file descriptor.
	close(fd);
	fd = open(working_path, O_RDONLY);
	read(fd, buff, 1024);

	// Get to first '/' character.
	str_index = 0;
	while(buff[str_index] != '/')
	{
		str_index++;
	}

	// Print result.
	printf("Swap: ");
	while(!isspace(buff[str_index]))
	{
		putchar(buff[str_index]);
		str_index++;
	}
	putchar('\n');

	// number of kernel modules ///////////////

	// compute new working path
	free(working_path);
	working_path = (char*)malloc((strlen(path) + strlen("/swaps"))*sizeof(char));
	working_path = strcpy(working_path, path);
	working_path = strcat(working_path, "/modules");

	// Get file descriptor.
	fd = open(working_path, O_RDONLY);

	// Module descriptions are stored in separate lines - count lines.
	int mod_count = 0;
	char temp[1];
	while(read(fd, temp, 1))
	{
		if(temp[0] == '\n') {
			mod_count++;
		}
	}

	// print result
	printf("Modules: %d\n", mod_count);
	close(fd);

	// Free allocated resources.
	free(working_path);
	working_path = NULL;

    // Free memory alocated for parse buffer.
	free(buff);
	buff = NULL;
}


// pids: Prints pids in proc folder sorted ascending. If names > 0, it also prints the names of the processes.
// If names == 1, the results are first sorted by names and then by pids.
void pids(char *path, int names)
{

	// Define pointers to the proc directory and the process directories.
	DIR *dir;
	DIR *sub_dir;
    struct dirent *dir_ptr;

    // Allocate buffer for parsing files.
    char *buff = calloc(128, sizeof(char));

    // Define pointer to array of found contents and its size.
    char **found_contents = NULL;
    int size_contents = 0;

    // Open directory pointed to by path.
    if((dir = opendir(path)) == NULL) 
    {
        perror("Error");
        exit(1);
    }
    
    // While there are still objects in the directory...
    while ((dir_ptr = readdir(dir)) != NULL)
    {
    	// Get pid of the process (folder name).
    	char *pid = dir_ptr->d_name;

    	// If the parsed value is a pid (contains only digits)....
    	if(is_proc(pid))
    	{
    		// Allocate memory for path to process folder.
    		char *sub_path = (char*)calloc((strlen(path) + strlen(pid) + 1 + 1), sizeof(char));

    		// Conctruct path to process folder.
    		strcpy(sub_path, path);
    		strcat(sub_path, "/");
    		strcat(sub_path, pid);

    		// Open process folder.
    		if((sub_dir = opendir(sub_path)) == NULL) 
    		{
        		perror("Error");
        		exit(1);
    		}

    		// Define structure for sub directory.
    		struct dirent *sub_dir_ptr;

    		// While exist more objects in folder.
    		while((sub_dir_ptr = readdir(sub_dir)) != NULL)
    		{
    			
    			// Get name of next object in folder.
    			char *name = sub_dir_ptr->d_name;
    			// if file name is "comm"...
 	   			if(!strcmp(name, "comm")) 
 	   			{
 	   				// Allocate memory for path to this file
 	   				char *comm_path = calloc((strlen(sub_path) + 6), sizeof(char));

 	   				// Construct path to "comm" file.
 	   				strncpy(comm_path, sub_path, strlen(sub_path));
 	   				strcat(comm_path, "/");
 	   				strcat(comm_path, "comm");

 	   				// Open "comm" file (get file descriptor).
    				int fd = open(comm_path, O_RDONLY);

    				// Read file into allocated buffer.
 					read(fd, buff, 128);
 					// Close open file.
 					close(fd);

 					// Allocate memory for new entry pointer in contents pointers array.
	   				found_contents = (char**)realloc(found_contents, (++size_contents)*sizeof(char*));
	   				// Allocate memory for the new entry array.
	   				found_contents[size_contents - 1] = (char*)calloc((strlen(pid) + strlen(buff) + 1), sizeof(char));

	   				// Copy found contents in allocated memory.
	    			strcpy(found_contents[size_contents - 1], pid);
	    			strcat(found_contents[size_contents - 1], " ");
	    			strncat(found_contents[size_contents - 1], buff, strlen(buff));

	    			// Free buffer and comm path and reallocate memory to buffer.
					free(buff);
					free(comm_path);
 					buff = calloc(128, sizeof(char));
    			}
    		}
    		// Close process directory.
    		closedir(sub_dir);

    		// free memory allocated to sub_path array
    		free(sub_path);
    	}
    }
    // Close proc directory
    closedir(dir);
    // Free memory allocated for dirent structure.
    free(dir_ptr);

    // If pids action (names == 0)...
    if(!names) {
    	// Sort found pids in ascending order.
    	sort_found_pids(found_contents, size_contents);

    	// Print sorted pids.
    	for(int i = 0; i < size_contents; i++) 
    	{
    	printf("%d\n", get_pid(found_contents[i]));
   		}
    } 
    // If names action (names == 1)...
    else if(names) 
    {
    	// Sort found contents by name and then by pid.
    	sort_found_contents(found_contents, size_contents);

    	// Print found contents.
    	for(int i = 0; i < size_contents; i++) 
    	{
	    	printf("%s", found_contents[i]);
   		}	
    }

    // Free contents arrays and array of pointers to contents array
    for(int i = 0; i < size_contents; i++)
    {
    	free(found_contents[i]);
    }
    free(found_contents);
}

// ps: Print info about processes. 
// If Extended_action1 == 1, print info of children processes of process with pid parent_id
// If Extended_action2 == 1, The function is used for the psext functionality and 
void ps(char *path, int extended_action1, char *parent_id, int extended_action2)
{
	// Define pointers to proc dir and to process dir.
	DIR *dir = NULL;
	DIR *sub_dir = NULL;

	// Define pointer to dirent struct
    struct dirent *dir_ptr = NULL;

    // Allocate memory for buffer.
    char *buff = calloc(65536, sizeof(char));

    // Define pointer to pointer to found contents.
    char **found_contents = NULL;
    // Define and initialize initial contents size.
    int size_contents = 0;

    // Define and initialize found info initial sizes.
    int size_pid = 0;
    int size_ppid = 0;
    int size_stat = 0;
    int size_name = 0;
    int num_threads = 0;
    int file_counter = 0;

    int *file_num_arr = NULL;
    int *thread_num_arr = NULL;
    int file_arr_size = 0;
    int thread_num_arr_size = 0;

    // Define and initialize array of parent process and their children.
    int parent_ids_list[1024];

    // if extended_action1 == 1
    if(extended_action1)
    {
    	// Add passes parent id to array of parents. 
    	parent_ids_list[0] = atoi(parent_id);	
    }
    // Set parents list size to 1.
    int parent_ids_list_size = 1;

    // Open proc folder.
    if((dir = opendir(path)) == NULL)
    {
        perror("Error");
        exit(1);
    }
    
    // While exist more objects in directory...
    while ((dir_ptr = readdir(dir)) != NULL)
    {
    	// Get name of next object in directory
    	char *pid = dir_ptr->d_name;
    	// If found object is the pid folder
    	if(is_proc(pid))
    	{
    		// Enter dir and find comm file.
    		// Allocate memory for path to process folder
    		char *sub_path = (char*)calloc((strlen(path) + strlen(pid) + 1 + 1), sizeof(char));

    		// Construct path to process folder.
    		strcpy(sub_path, path);
    		strcat(sub_path, "/");
    		strcat(sub_path, pid);

    		// Open process folder.
    		if((sub_dir = opendir(sub_path)) == NULL) 
    		{
        		perror("Error");
        		exit(1);
    		}

    		// Define dirent structure for process folder.
    		struct dirent *sub_dir_ptr;

    		// While process folder has more entries...
    		while((sub_dir_ptr = readdir(sub_dir)) != NULL)
    		{
    			
    			char *name = sub_dir_ptr->d_name;

    			// if file name is "comm"
 	   			if(!strcmp(name, "status")) {

 	   				// Allocate memory for status file path.
 	   				char *status_path = calloc((strlen(sub_path) + 8), sizeof(char));

 	   				// Construct path to status file
 	   				strcpy(status_path, sub_path);
 	   				strcat(status_path, "/");
 	   				strcat(status_path, "status");

 	   				// Open status file.
    				int fd = open(status_path, O_RDONLY);
    				// Read into buffer.
 					read(fd, buff, 65535);

 					// Close file.
 					close(fd);

 					// String processing - getting the correct info ///////////////

 					// Initialize starting index.
 					int buff_index = 0;

 					// Initialize temp index
 					int buff_index_temp = buff_index;

 					// name //////////////////////////////////////////////

 					// Get to "Name:"
 					while(strncmp(buff + buff_index, "Name:", 5) != 0) {
 						buff_index++;
 					}

 					// Get to first char in name.
 					buff_index += 6;

 					// Define name pointer.
 					char *name  = NULL;
 					// Initialize name size
 					size_name = 0;

 					// Set traversing index.
 					buff_index_temp = buff_index;

 					// Go to next newline
 					while(*(buff + buff_index_temp) != '\n') {
 						size_name++;
 						buff_index_temp++;
 					}
 					// Allocate memory for found name.
 					name = (char*)calloc(size_name, sizeof(char));

 					// Copy found name into name string.
 					strncpy(name, buff + buff_index, size_name);

 					// state //////////////////////////////////////////////

 					// Get to "State:"
 					while(strncmp(buff + buff_index, "State:", 6) != 0) {
 						buff_index++;
 					}

 					// Get to first character in "State:" info
 					buff_index += 7;
 					// define status info pointer.
 					char *status  = NULL;
 					// Initialize initial size to 0.
 					size_stat = 0;
 					// Set traverse index.
 					buff_index_temp = buff_index;
 					while(*(buff + buff_index_temp) != ' ') {
 						size_stat++;
 						buff_index_temp++;
 					}
 					
 					// Initialize memory for status string.
 					status = calloc(size_stat, sizeof(char));

 					// Copy status info into status string pointer.
 					strncpy(status, buff + buff_index, size_stat);

 					// pid //////////////////////////////////////////////

 					// Get to "Pid:"
 					while(strncmp(buff + buff_index, "Pid:", 4) != 0) {
 						buff_index++;
 					}

 					// Get to first character of pid info.
					buff_index += 5;
					// Define pid info string pointer.
 					char *pid  = NULL;
 					// Initialize initial pid info string size.
 					size_pid = 0;

 					// Initialize traverse buffer.
 					buff_index_temp = buff_index;

 					// Parse pid info.
 					while(*(buff + buff_index_temp) != '\n') {
 						size_pid++;
 						buff_index_temp++;
 					}

 					// Allocate memory for ppidid info string.
 					pid = (char*)calloc(size_pid, sizeof(char));
 					// Copy parsed pid info into allocated string.
 					strncpy(pid, buff + buff_index, size_pid);

 					// ppid //////////////////////////////////////////////

 					// Get to "PPid:"
 					while(strncmp(buff + buff_index, "PPid:", 5) != 0) {
 						buff_index++;
 					}

 					// Get to first char in ppid info.
 					buff_index += 6;

 					// Define ppid info string pointer.
 					char *ppid  = NULL;
 					// Set traverse index.
 					buff_index_temp = buff_index;
 					// Initialize initial ppid info size.
 					size_ppid = 0;

 					// Parse ppid info.
 					while(*(buff + buff_index_temp) != '\n') {
 						size_ppid++;
 						buff_index_temp++;
 					}

 					// Allocate memory for ppid info string.
 					ppid = (char*)calloc(size_ppid, sizeof(char));

 					// Copy parsed ppid info into allocated string.
 					strncpy(ppid, buff + buff_index, size_ppid);

 					// If extended_action1 == 1...	 					
 					if(extended_action1)
 					{
 						// If found pid is not the parent pid passed into the function and is not in the transitive closure of the passed parent pid.
 						if(strcmp(parent_id, pid) != 0 && !contains_id(parent_ids_list, parent_ids_list_size, atoi(ppid)))
 						{
 							continue;
 						}
 						
 						// Add pid into transitive closure list.
 						parent_ids_list[parent_ids_list_size] = atoi(pid);
 						parent_ids_list_size++;
 					}

 					// if extended_action2 == true - parse number of threads of this process and the number of open files
 					if(extended_action2)
 					{

 						// counting the number of threads //////////////////////////////////////////////

 						// Initialize temp. buffer for traversing the sought info.
 						buff_index_temp = buff_index;
 						while(strncmp(buff + buff_index_temp, "Threads:", 8) != 0) {
 							buff_index_temp++;
 						}
 						buff_index_temp += 8;

 						// NUMBER OF THREEADS IS == NUMBER OF ENTRIES IN //TASK

 						// Initialize digit counter.
 						int digit_count2 = 0;
 						// Initialize another temp. buffer index for traversing the threads info.
 						int buff_index_temp2 = 0;
 						// Count num. of digits.
 						while(*(buff + buff_index_temp +  buff_index_temp2) != '\n')
 						{
 							buff_index_temp2++;
 							digit_count2++;
 						}

 						// Initialize and allocate memory for temp storage array for storing thread number information.
 						char *num_threads_temp = (char*)calloc(digit_count2 + 1, sizeof(char));
 						// Copy found number of digits in the allocated memory.
 						num_threads_temp = strncpy(num_threads_temp, buff + buff_index_temp, digit_count2);
 						// Convert to int and store.
 						num_threads = atoi(num_threads_temp);

 						// Free temp storage array memory.
 						free(num_threads_temp);
 						num_threads_temp = NULL;

						// counting the number of open files //////////////////////////////////////////////

 						// Define DIR pointer for the fd directory
						DIR *fd_dir = NULL;

						// Create path to fd fxolder.
						char *fd_path = calloc(strlen(sub_path) + 4, sizeof(char));
						strcpy(fd_path, sub_path);
						strcat(fd_path, "/fd");

						// Open fd folder.
						if((fd_dir = opendir(fd_path)) == NULL) 
						{
							perror("Error");
							exit(1);
						}

						// Define dirent structure for fd folder.
						struct dirent *fd_dir_ptr;

						// While fd folder has more entries...
						while((fd_dir_ptr = readdir(fd_dir)) != NULL)
						{
							// Ignore "." and ".." folders and count the number of entries in the fd folder.
							if(strcmp(fd_dir_ptr->d_name, ".") != 0 && strcmp(fd_dir_ptr->d_name, "..") != 0)
							{
								file_counter++;	
							}
						}

						// Close directories and free allocated resources.
						closedir(fd_dir);
						free(fd_dir_ptr);
						fd_dir_ptr = NULL;
						free(fd_path);
						fd_path = NULL;

						// Add found info to storage arrays.
						file_num_arr = (int*)realloc(file_num_arr, (++file_arr_size)*sizeof(int));
						file_num_arr[file_arr_size - 1] = file_counter;

						thread_num_arr = (int*)realloc(thread_num_arr, (++thread_num_arr_size)*sizeof(int));
						thread_num_arr[thread_num_arr_size - 1] = num_threads;
						
						// Reset counters.
						file_counter = 0;
 						num_threads = 0;
 						///////////////////////////////////////////////////////////////////////////////////
 					}

 					// Allocate memory for new contents pointer.
    				found_contents = (char**)realloc(found_contents, (++size_contents)*sizeof(char*));
    				// Allocate memory for new found contents.
    				found_contents[size_contents - 1] = (char*)calloc(strlen(name) + 1 + strlen(status) + 1 + strlen(pid) + 1 + strlen(ppid) + 1, sizeof(char));

    				// Copy found info into next contents array.
    				strcpy(found_contents[size_contents - 1], pid);
    				strcat(found_contents[size_contents - 1], " ");
    				strcat(found_contents[size_contents - 1], ppid);
    				strcat(found_contents[size_contents - 1], " ");
    				strcat(found_contents[size_contents - 1], status);
    				strcat(found_contents[size_contents - 1], " ");
    				strcat(found_contents[size_contents - 1], name);

    				// Free buffer memory and reallocate.
					free(buff);
 					buff = calloc(65536, sizeof(char));

 					// Free memory for storing info before transferring to contents array.
 					free(pid);
    				pid = NULL;
    				free(ppid);
    				ppid = NULL;
    				free(status);
    				status = NULL;
    				free(name);
    				name = NULL;
    
    			}

    		}
    		// Close process directory 
    		closedir(sub_dir);
		   	sub_dir = NULL;
		   	//free(sub_path);
			//sub_path = NULL;

    	}		

    }

    // Close proc directory.
    closedir(dir);
    dir = NULL;

    // Sort found contents by pid.
	int *perm = sort_found_pids(found_contents, size_contents);

	// If ps action..
	if(!extended_action2)
	{
		// Print results.
		printf("  PID  PPID STANJE IME\n");
		for(int i = 0; i < size_contents; i++) {
			printf("%5s ", extract_pid(found_contents[i]));
			printf("%5s ", extract_ppid(found_contents[i]));	
			printf("%6s ", extract_state(found_contents[i]));
			printf("%s\n", extract_name(found_contents[i]));
		}
	}
	// if psext action...
	else if (extended_action2)
	{
		
		file_num_arr = apply_perm(file_num_arr, perm, size_contents);
		thread_num_arr = apply_perm(thread_num_arr, perm, size_contents);
		// Print results.
		printf("  PID  PPID STANJE  #NITI  #DAT. IME\n");
		for(int i = 0; i < size_contents; i++) {
			printf("%5s ", extract_pid(found_contents[i]));
			printf("%5s ", extract_ppid(found_contents[i]));	
			printf("%6s ", extract_state(found_contents[i]));
			printf("%6d ", thread_num_arr[i]);
			printf("%6d ", file_num_arr[i]);
			printf("%s\n", extract_name(found_contents[i]));
		}
	}

	// Free arrays of thread numbers and numbers of open files.
	free(thread_num_arr);
	free(file_num_arr);
	thread_num_arr = NULL;
	file_num_arr = NULL;				

	// Free arrays of contents and array of pointers to contents.
	for(int i = 0; i < size_contents; i++) {
		free(found_contents[i]);
	}
	free(found_contents);
	found_contents = NULL;
}

// is_proc: Check if the folder with name name is a process folder (starts with a digit).
int is_proc(char *name)
{
	return isdigit(name[0]) ? 1 : 0;
}

// sort_found_contents: Sort found contents first by name and then by pid (selection sort).
void sort_found_contents(char **found_contents, int size_contents)
{
	// Selection sort algorithm
	for(int i = 0; i < size_contents - 1; i++)
	{
		int min_index = i;
		for(int j = i + 1; j < size_contents; j++)
		{
			// Find index of names in contents record array.
			int index_start_name_fst = 0;
			while(found_contents[min_index][index_start_name_fst] != ' ') {
				index_start_name_fst++;
			}
			index_start_name_fst++;

			int index_start_name_snd = 0;
			while(found_contents[j][index_start_name_snd] != ' ') {
				index_start_name_snd++;
			}
			index_start_name_snd++;

			// Sort by name.
			if(strcasecmp(found_contents[min_index] + index_start_name_fst, found_contents[j] + index_start_name_snd) > 0)
			{
				min_index = j;
			}
			// If names are equal, sort by pid.
			else if(strcasecmp(found_contents[min_index] + index_start_name_fst, found_contents[j] + index_start_name_snd) == 0)
			{
				int pid_1 = get_pid(found_contents[min_index]);
				int pid_2 = get_pid(found_contents[j]);
				if(pid_2 < pid_1) {
					min_index = j;
				}
			}
		}
		// If found new minimum...
		if(min_index != i)
		{
			swap_contents(found_contents, i, min_index);
		}
		
	}
}

// sort_found_pids: Sort found pids in ascending order (selection sort).
// This function returns the permutation that was used to sort this array.
int *sort_found_pids(char **found_contents, int size_contents) {
	// create permutations array
	int *perm = (int*)malloc(size_contents*sizeof(int));
	// Create sorted permutation array
	for(int i = 0; i < size_contents; i++)
	{
		perm[i] = i;
	}

	for(int i = 0; i < size_contents - 1; i++) {
		int index_min = i;
		for(int j = i + 1; j < size_contents; j++) {
			int pid_1 = get_pid(found_contents[index_min]);
			int pid_2 = get_pid(found_contents[j]);
			if(pid_2 < pid_1) {
				index_min = j;
			}
		}

		if(index_min != i) {
			swap_contents(found_contents, i, index_min);
			swap_perm(perm, i, index_min);
		}
	}
	return perm;
}

// apply_perm: Apply a permutation specified in perm to array arr. Both arrays are of length length.
int *apply_perm(int *arr, int* perm, int length)
{

	int *res = malloc(length*sizeof(int));
	// Apply transformation.
	for(int i = 0; i < length; i++)
	{
		res[i] = arr[perm[i]];
	}
	
	return res;
}

// get_pid: Get pid info in content entry.
int get_pid(char *content)
{
	int digit_count = 0;
	int pid_index = 0;
	while(content[pid_index] != ' ')
	{
		digit_count++;
		pid_index++;
	}

	char *pid_str = (char*)calloc(digit_count + 1, sizeof(char));
	strncpy(pid_str, content, digit_count);
	int pid_int = str2int(pid_str);
	free(pid_str);
	pid_str = NULL;
	return pid_int;
}

// str2int: convert string pointed to by pid_str to integer
int str2int(char *pid_str)
{
	return atoi(pid_str);
}

// swap_contents: swap contents in array of contents pointers at indices index_1 and index_2
void swap_contents(char **contents, int index_1, int index_2) {
	char *temp = contents[index_1];
	contents[index_1] = contents[index_2];
	contents[index_2] = temp;
}

void swap_perm(int *perm, int index_1, int index_2)
{
	int temp = perm[index_1];
	perm[index_1] = perm[index_2];
	perm[index_2] = temp;
}


// extract_pid: Extract pid info from contents entry as a string..
char *extract_pid(char *contents)
{

	// Initialize initial size and traverse index.
	int size = 0;
	int temp_index = 0;
	// Count digits in pid.
	while(contents[temp_index] != ' ')
	{
		size++;
		temp_index++;
	}

	// Allocate memory for the string containing the pid
	char *res = (char*)calloc(size + 1, sizeof(char));
	// Copy the pid into the string.
	strncpy(res, contents, size);
	return res;
}

// extract ppid info from contents entry as a string.
char *extract_ppid(char *contents)
{
	// Initialize traverse indices.
	int space_counter = 0;
	int contents_index = 0;

	// Count enough spaces to get to the correct part of the record.
	while(space_counter < 1)
	{
		if(contents[contents_index] == ' ')
		{
			space_counter++;
		}
		contents_index++;
	}

	// Initialize size with 0.
	int size = 0;
	// Initialize traverse index.
	int temp_index = contents_index;
	// Count number of digits in the array.
	while(contents[temp_index] != ' ')
	{
		size++;
		temp_index++;
	}

	// Allocate space for the resulting string.
	char *res = (char*)calloc(size + 1, sizeof(char));
	// Copy pid into the allocated memory.
	strncpy(res, contents + contents_index, size);
	return res;
}

// extract state info from contents entry as a string.
char *extract_state(char *contents)
{
	// Similar - see above functions.
	int space_counter = 0;
	int contents_index = 0;
	while(space_counter < 2)
	{
		if(contents[contents_index] == ' ')
		{
			space_counter++;
		}
		contents_index++;
	}

	int size = 0;
	int temp_index = contents_index;
	while(contents[temp_index] != ' ')
	{
		size++;
		temp_index++;
	}

	char *res = (char*)calloc(size + 1, sizeof(char));
	strncpy(res, contents + contents_index, size);
	return res;
}

// extract name info from contents entry as a string.
char *extract_name(char *contents)
{
	// Similar - see above functions.
	int space_counter = 0;
	int contents_index = 0;
	while(space_counter < 3)
	{
		if(contents[contents_index] == ' ')
		{
			space_counter++;
		}
		contents_index++;
	}

	int size = 0;
	int temp_index = contents_index;
	while(contents[temp_index] != ' ')
	{
		size++;
		temp_index++;
	}

	char *res = (char*)calloc(size + 1, sizeof(char));
	strncpy(res, contents + contents_index, size);
	return res;
}

// contains_id: Check if the ancestry transitive closure array contains passed ppid value.
int contains_id(int *parent_ids_list, int parent_ids_list_size, int ppid)
{
	// Go over the array.
	for(int i = 0; i < parent_ids_list_size; i++)
	{
		// If current pid equals the passed pid (ppid)
		if(parent_ids_list[i] == ppid)
		{
			// pid found
			return 1;
		}
	}
	return 0;
}

// construct_tree: Constructs tree form parsed input data stored in input_data array and returns pointer to root
// The input is formated according to the forktree function specification.
void construct_tree(Node root, Node prev, int *input_data, int input_data_size, int num_children, int child_parse_index)
{
	// Set parent to calling Node.
	root->parent = prev;
	root->num_children = num_children;
	root->children = NULL;
	// Base case - Node has no children
	if(num_children <= 0)
	{
		return;
	}

	// Initialize array of pointer to child nodes.
	root->children = (Node*)malloc(num_children*sizeof(Node));

	// Add children nodes.
	for(int i = 0; i < num_children; i++)
	{
		(root->children)[i] = (Node)malloc(sizeof(Node));
	}

	// If tree data for children does not exist there are no more children.
	if(child_parse_index >= input_data_size)
	{
		return;
	}	

	// Build trees on children.
	for(int i = 0; i < num_children; i++)
	{

		// Compute number of children of next child.
		int num_children_child = (child_parse_index + i >= input_data_size) ? 0 : input_data[child_parse_index + i];

		// Compute commulative sum for the input data array from 0 to child_parse_index + i.
		// This commulative sum is used to compute the index at which a particular child will start parsing its children.
		int follow_up = 0;
		for(int j = 0; j < child_parse_index + i; j++)
		{
			follow_up += input_data[j];
		}

		// Compute index at which child will start parsing its index
		int parse_start_index = follow_up + 1;

		// optional: print tree construction step info
		//printf("processing index %d, child_parse index == %d, parse_start_index == %d\n", child_parse_index + i, child_parse_index, parse_start_index);

		construct_tree((root->children[i]), root, input_data, input_data_size, num_children_child, parse_start_index);
	}
}

// Traversal: Traverse a tree of Nodes and create a process structure that mimics its structure.
void traversal(Node root, int root_pid, char *root_pid_str)
{

	// If in parent process...
	if(getpid() == root_pid)
	{
		// Create a new process for executing the pstree command.
		pid_t exec_pid = fork();
		// If in child process...
		if(exec_pid == 0)
		{
			// Wait for all branches to fully extend.
			sleep(2);
			// Execute the pstree command.
			execlp("pstree", "pstree", "-c", root_pid_str, NULL);
			// Kill this process.
			_exit(0);
		}
	}

	// If leaf process... pause (base case)
	if(root->children == NULL)
	{
		pause();
	}

	// Go over children of root.
	for(int i = 0; i < root->num_children; i++)
	{
		// Create new process.
		pid_t pid = fork();

		// If child, recur for its children
		if(pid == 0)
		{
			traversal((root->children)[i], root_pid, root_pid_str);	
		}
	}
	// If root process...
	if(getpid() == root_pid)
	{
		// Wait for the pstree calling process to die.
		wait(NULL);
		// Exit program.
		exit(0);
	}
	// Else pause.
	pause();
}

void free_tree(Node root)
{
	if(root->children == NULL)
	{
		return;
	}

	for(int i = 0; i < root->num_children; i++)
	{
		free_tree((root->children)[i]);
	}
	free(root);
}