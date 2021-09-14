#ifndef _aioperf_HANDLE_FILE_H
#define _aioperf_HANDLE_FILE_H

#define AIOPERF_FILE_NAME_SIZE      1024


int
aioperf_files_init(aioperf_manager_t *mgr);
void
aioperf_files_release(aioperf_manager_t *mgr);
int
aioperf_files_read_init(aioperf_repository_t *repository);
int
aioperf_files_write_init(aioperf_repository_t *repository);
void
aioperf_files_read_release(aioperf_repository_t *repository);
void
aioperf_files_write_release(aioperf_repository_t *repository);
int
aioperf_files_create(aioperf_repository_t *repository, aioperf_pool_t *pool,
    char *folder_name, int handle_type);
void
aioperf_files_destroy(aioperf_repository_t *repository);
int
aioperf_files_open(aioperf_pool_t *pool, aioperf_io_task_t **file, 
    char *name, int handle_type);
int
aioperf_files_write(aioperf_worker_t *worker, aioperf_repository_t *repository, 
    aioperf_pool_t *pool);
int
aioperf_files_read(aioperf_worker_t *worker, aioperf_repository_t *repository, 
    aioperf_pool_t *pool);
void
aioperf_files_move_to_end(aioperf_io_task_t **this, aioperf_io_task_t **end);
int 
aioperf_files_create_folder(const char *path);

#endif
