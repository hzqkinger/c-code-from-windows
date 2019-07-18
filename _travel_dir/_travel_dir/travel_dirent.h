#pragma once

#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

//struct dirent
//{
//	long d_ino; /* inode number 索引节点号 */
//	off_t d_off; /* offset to this dirent 在目录文件中的偏移 */
//	unsigned short d_reclen; /* length of this d_name 文件名长 */
//	unsigned char d_type; /* the type of d_name 文件类型 */
//	char d_name[NAME_MAX + 1]; /* file name (null-terminated) 文件名，最长255字符 */
//}
//struct __dirstream
//{
//	void *__fd; /* `struct hurd_fd' pointer for descriptor.   */
//	char *__data; /* Directory block.   */
//	int __entry_data; /* Entry number `__data' corresponds to.   */
//	char *__ptr; /* Current pointer into the block.   */
//	int __entry_ptr; /* Entry number `__ptr' corresponds to.   */
//	size_t __allocation; /* Space allocated for the block.   */
//	size_t __size; /* Total valid data in the block.   */
//	__libc_lock_define(, __lock) /* Mutex lock for this structure.   */
//};
//typedef struct __dirstream DIR;

//DIR* opendir(const char * path);
//struct dirent* readdir(DIR* dir_handle);
//void closedir(DIR* dir_handle);

void Copy(const char *dst, const char *src)//仅仅只是拷贝文件
{
	FILE *f1 = fopen(src, "rb");
	FILE *f2 = fopen(dst, "wb");
	fseek(f1, 0L, SEEK_END);
	int lens = ftell(f1);//取出原文件大小
	rewind(f1);
	fread(buf, lens, 1, f1);
	fwrite(buf, lens, 1, f2);
	fclose(f1); fclose(f2);
}
void travel_dir(char *dir)
{
	DIR *dir_point; //DIR是directory的缩写，是目录的意思
	struct dirent *entry;
	if ((dir_point = opendir(dir)) == NULL)
		return;//打开文件夹失败，直接退出

	while (!(entry = readdir(dir_point))){
		printf("%s\n", entry->d_name);
	}
}

void test()
{
	travel_dir("../../.");
}